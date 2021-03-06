#include "stdafx.h"

using namespace std;

double herons(double s)
{
    double x = s / 2;
    double epsilon = 1e-6;
    while (x*x - s > epsilon)
        x = ((s / x) + x) / 2;
    return x;
}

int main()
{
    seed_seq seed{ 2016 };
    default_random_engine generator{ seed };
    uniform_int_distribution<> distribution(1e6, 2e6);

    double s = distribution(generator);

    cout << fixed << setprecision(0)
         << "The square root of " << s << " is "
         << setprecision(8) << herons(s)
         << endl << endl;

    return 0;
}

