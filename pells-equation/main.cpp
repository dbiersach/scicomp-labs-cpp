#include "stdafx.h"

using namespace std;

void DisplayHeader()
{
    cout << setw(4) << "n"
         << setw(8) << "x"
         << setw(8) << "y"
         << endl;

    cout << setw(4) << "==="
         << setw(8) << "======"
         << setw(8) << "======"
         << endl;
}

int main()
{
    DisplayHeader();

    const uintmax_t xMax = 70000;

    for (uintmax_t n = 2; n <= 70; n++)
    {
        cout << setw(4) << n;
        bool foundSolution = false;
        uintmax_t x = 1;
        while ((x <= xMax) && !foundSolution)
        {
            uintmax_t xSqr = x * x;
            uintmax_t y = 1;
            uintmax_t yMax = sqrt(xSqr / n);
            while ((y <= yMax) && !foundSolution)
            {
                uintmax_t ySqr = y * y;
                if (xSqr - n * ySqr == 1)
                {
                    cout << setw(8) << x
                         << setw(8) << y;
                    foundSolution = true;
                }
                y++;
            }
            x++;
        }
        if (!foundSolution)
            cout << setw(8) << "-"
                 << setw(8) << "-";
        cout << endl;
    }
    return 0;
}

