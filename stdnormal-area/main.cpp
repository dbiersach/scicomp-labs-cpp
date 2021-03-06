#include "stdafx.h"

using namespace std;

inline double f(double x)
{
    return 0;
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
    cout << Simpsons(0, 0) << endl;

    return 0;
}
