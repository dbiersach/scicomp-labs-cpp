#include "stdafx.h"

using namespace std;

inline double f(double x)
{
    return 1 / sqrt(2 * M_PI) * exp(-x * x / 2);
}

double Simpsons(double a, double b)
{
    int intervals = 1e5;
    double dx{ (b - a) / intervals };
    double sum{ f(a) + f(b) };
    a += dx;
    for (int i{ 1 }; i < intervals; ++i, a += dx)
        sum += f(a)*(2 * (i % 2 + 1));
    return (dx / 3)*sum;
}

int main()
{
    cout << Simpsons(-1, 1) << endl;

    return 0;
}
