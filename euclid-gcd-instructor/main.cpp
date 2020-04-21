#include "stdafx.h"

using namespace std;

int GCD(int a, int b)
{
    if (a < b)
        swap(a, b);

    int c = a - b;

    while (c > 0)
    {
        if (c > b)
            a = c;
        else
        {
            a = b;
            b = c;
        }
        c = a -b;
    }

    return b;
}

int main()
{
    int a = 231;
    int b = 182;

    cout << "The GCD of " << a
         << " and " << b << " = "<<
         GCD(a,b) << endl;

    return 0;
}
