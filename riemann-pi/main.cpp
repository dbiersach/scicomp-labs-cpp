#include "stdafx.h"

using namespace std;
using namespace chrono;

vector<int> primes{ 2,3 };

int PrimeCountingFunction(int x)
{
    // Add your code here
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
