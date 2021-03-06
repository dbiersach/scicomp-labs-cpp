#include "stdafx.h"
#include "simplescreen.h"
#include "niederreiter.h"

using namespace std;

double f(double x)
{
    return 1.0 / sqrt(2.0 * M_PI) * exp(-pow(x, 2) / 2.0);
}

void draw(SimpleScreen &ss)
{
    ss.DrawAxes();

    double x = ss.worldXmin;
    const double dx = ss.worldWidth / 97;

    PointSet ps;
    while (x <= ss.worldXmax)
    {
        ps.add(x, f(x));
        x += dx;
    }
    ss.DrawLines(&ps, "green", 2, false);

    Niederreiter qrng;
    double r[2];
    int seed{};

    const int iterations = 10000;
    int count{};

    ss.LockDisplay();

    for (int i{}; i < iterations; ++i)
    {
        qrng.Next(2, &seed, r);
        double x = r[0] * -2.0 - 1.0;
        double y = r[1] * -0.5;
        if (y <= f(x))
        {
            ss.DrawPoint(x, y, "red");
            count++;
        }
        else
            ss.DrawPoint(x, y, "blue");
    }

    ss.UnlockDisplay();

    double estArea = (double)count / iterations;
    double actArea = 0.682689492;
    double err = (actArea - estArea) / actArea * 100;

    cout << "Std Normal 1st Deviation Area QRNG" << endl
         << "Iterations = " << iterations << endl
         << "Est. Area  = " << estArea << endl
         << "Act. Area  = " << actArea << endl
         << "Abs. % Err = " << abs(err) << endl
         << endl;
}

int main()
{
    cout.imbue(locale(""));

    SimpleScreen ss(draw);
    ss.SetZoomFrame("white", 3);

    ss.SetWorldRect(-4, -0.1, 4, 0.6);

    ss.HandleEvents();

    return 0;
}
