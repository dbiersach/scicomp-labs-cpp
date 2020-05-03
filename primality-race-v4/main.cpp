#include "stdafx.h"

using namespace std;
using namespace chrono;

seed_seq seed{ 2016 };
default_random_engine generator{ seed };
uniform_int_distribution<int> distribution(100000, 999999);

int primes[169];

void InitPrimes()
{
    int numPrimes{};
    int n{ 3 };
    while (numPrimes < 169)
    {
        if (n % 2 == 1)
        {
            bool isPrime = true;
            for (int p{}; p < numPrimes; ++p)
                if (n % primes[p] == 0)
                {
                    isPrime = false;
                    break;
                }
            if (isPrime)
            {
                primes[numPrimes] = n;
                numPrimes++;
            }
        }
        n += 2;
    }
}

int CountPrimes(unique_ptr<vector<int>> const &samples)
{
    int numPrimes{};
    for (const auto &sample : *samples)
    {
        if (sample % 2 != 0)
        {
            int sqrtSample = sqrt(sample);
            bool isPrime = true;
            for (int n{}; primes[n] <= sqrtSample; ++n)
                if (sample % primes[n] == 0)
                {
                    isPrime = false;
                    break;
                }
            if (isPrime)
                numPrimes++;
        }
    }
    return numPrimes;
}

int main()
{
    const auto samples{ make_unique<vector<int>>(100000) };

    for (auto &sample : *samples)
        sample = distribution(generator);

    InitPrimes();

    cout.imbue(std::locale(""));
    cout << "Counting primes in vector of "
         << samples->size() << " random integers..."
         << endl;

    auto startTime = steady_clock::now();

    int numPrimes = CountPrimes(samples);

    auto endTime = steady_clock::now();

    auto totalTime = duration_cast<milliseconds>
                     (endTime - startTime).count();

    cout << "Number of Primes: " << numPrimes << endl;
    cout << "Total run time (ms): " << totalTime << endl;

    return 0;
}
