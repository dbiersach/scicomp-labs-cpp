#include "stdafx.h"
#include "simplescreen.h"

using namespace std;

void draw(SimpleScreen& ss)
{
    double radius{ 5 };
    int width{ 15 };

    // You must determine proper offsets
    double ringOffsetFullX{radius * 5. / 2};
    double ringOffsetHalfX{radius * 5. / 4};
    double ringOffsetY{radius};

    ss.DrawCircle(0, 0, radius, "black", width);
    ss.DrawCircle(-ringOffsetFullX, 0, radius, "blue", width);
    ss.DrawCircle(ringOffsetFullX, 0, radius, "red", width);
    ss.DrawCircle(-ringOffsetHalfX, -ringOffsetY, radius, "yellow", width);
    ss.DrawCircle(ringOffsetHalfX, -ringOffsetY, radius, "green", width);
}

int main()
{
    SimpleScreen ss(draw);
    ss.SetWorldRect(-20, -20, 20, 20);
    ss.HandleEvents();
    return 0;
}
