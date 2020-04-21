#include "stdafx.h"

using namespace std;
using namespace chrono;

vector<int> primes{ 2,3 };

void FindPrimesUnder(int limit)
{
    int n = primes.back() + 2;
    while (n < limit)
    {
        if (n % 2 == 1)
        {
            bool isPrime = true;
            for (int p : primes)
                if (n % p == 0)
                {
                    isPrime = false;
                    break;
                }
            if (isPrime && n <= limit)
                primes.push_back(n);
        }
        n += 2;
    }
}

int main()
{
    cout.imbue(locale(""));
    cout << right;

    auto startTime = system_clock::now();

    for (int i{ 1 }; i <= 6; i++)
    {
        FindPrimesUnder((int)pow(10, i));
        cout << "10^" << to_string(i) << " ="
             << setw(7) << primes.size() << endl;
    }

    auto stopTime = system_clock::now();

    auto totalTime = duration_cast<milliseconds>(stopTime - startTime);
    cout << endl << "Run time (ms): " << totalTime.count() << endl;

    return 0;
}

