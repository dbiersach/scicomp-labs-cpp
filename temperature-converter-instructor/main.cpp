#include "stdafx.h"

using namespace std;

int main()
{
    cout.imbue(locale(""));
    cout << right << fixed << setprecision(2);

    for (double degF{-44}; degF <= 216; degF += 4)
    {
        double degC = (degF - 32) * 5. / 9;

        cout << setw(7) << degF << " F = "
             << setw(7) << degC << " C" << endl;
    }

    return 0;
}
