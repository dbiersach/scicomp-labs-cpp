#include "stdafx.h"

using namespace std;

int main()
{
    cout.imbue(locale(""));
    cout << right << fixed << setprecision(2);

    for (double degC{-44}; degC <= 216; degC += 4)
    {
        double degF = degC * 9. / 5 + 32;

        cout << setw(7) << degC << " C = "
             << setw(7) << degF << " F"
             << endl;
    }

    return 0;
}
