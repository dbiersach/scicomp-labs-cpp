#include "stdafx.h"

using namespace std;

int main()
{
    int J{ 115425 };
    int K{ 3254121 };
    int L{ 379020 };

    cout << "Given the quadratic:" << endl
         << J << "x^2 + " << K << "x + " << L
         << " = 0" << endl << endl
         << "The factors are:"
         << endl << endl;

    for (int a{ 1 }; a <= J; ++a)
    {
        if (J % a == 0)
        {
            int c = J / a;
            for (int b{ 1 }; b <= L; ++b)
            {
                if (L % b == 0)
                {
                    int d = L / b;
                    if (a*d + b*c == K)
                    {
                        cout << "(" << a << "x + " << b << ")"
                             << "(" << c << "x + " << d << ")"
                             << endl;
                    }
                }
            }
        }
    }

    return 0;
}

