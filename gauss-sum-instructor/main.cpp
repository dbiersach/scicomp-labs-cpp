#include "stdafx.h"

using namespace std;

int main()
{
    double n = 1000;

    double sumByLooping = 0;

    for (int k{1}; k <= n; ++k)
        sumByLooping += k;

    cout.imbue(std::locale(""));

    cout << "Manual sum of first " << n
         << " natural numbers = "
         << sumByLooping << endl;

    double sumByGauss = (n * (n + 1)) / 2;

    cout << "Gaussian sum of first " << n
         << " natural numbers = "
         << sumByGauss << endl;

    return 0;
}
