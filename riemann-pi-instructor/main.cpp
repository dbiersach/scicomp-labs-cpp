#include "stdafx.h"

using namespace std;
using namespace chrono;

vector<int> primes{ 2,3 };

int PrimeCountingFunction(int x)
{
    int n = primes.back() + 2;
    while (n < x)
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
            if (isPrime && n <= x)
                primes.push_back(n);
        }
        n += 2;
    }
    return primes.size();
}

int main()
{
    cout.imbue(locale(""));
    cout << right;

    boost::timer timer;

    for (int i{ 1 }; i <= 6; i++)
    {
        cout << "10^" << to_string(i) << " =" << setw(7);
        cout << PrimeCountingFunction((int)pow(10, i)) << endl;
    }

    cout << endl << "Run time: "
         << timer.elapsed() << "s" << endl;

    return 0;
}

