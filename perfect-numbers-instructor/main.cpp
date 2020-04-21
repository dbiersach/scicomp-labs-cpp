#include "stdafx.h"

using namespace std;

int main()
{
    for (int n{ 2 }; n < 10000; ++n)
    {
        int sumOfFactors{ 1 };

        for (int factor{ 2 }; factor < n; factor++)
            if (n % factor == 0)
                sumOfFactors += factor;

        if (sumOfFactors == n)
            cout << n << " is a perfect number"
                 << endl;
    }
    return 0;
}
