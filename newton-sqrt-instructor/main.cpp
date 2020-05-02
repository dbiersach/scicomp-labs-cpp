#include "stdafx.h"

using namespace std;

int main()
{
    double x{ 168923 };

    double lowEnd{};
    double highEnd{ x };

    double estimate = (highEnd + lowEnd) / 2;
    double estimateSquared = pow(estimate, 2);

    double epsilon{ 1e-14 };

    while (abs(estimateSquared - x) > epsilon)
    {
        if (estimateSquared > x)
            highEnd = estimate;
        else
            lowEnd = estimate;

        estimate = (highEnd + lowEnd) / 2;
        estimateSquared = pow(estimate, 2);

        if (highEnd == lowEnd)
            break;
    }

    cout << "Estimated Square Root of "
         << x << " = " << fixed
         << setprecision(14) << estimate
         << endl;

    return 0;
}
