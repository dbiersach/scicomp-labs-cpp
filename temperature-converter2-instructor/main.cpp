#include "stdafx.h"

using namespace std;

int main()
{
    cout.imbue(std::locale(""));
    cout << fixed << setprecision(2);

    for (double degC{ -44 }; degC <= 216; degC += 4)
    {
        double degF = degC * 9. / 5 + 32;

        cout << setw(7) << right << degC << " C = "
             << setw(7) << right << degF << " F"
             << endl;
    }

    return 0;
}

