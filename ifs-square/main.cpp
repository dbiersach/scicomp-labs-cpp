#include "stdafx.h"
#include "simplescreen.h"
#include "ifs.h"

using namespace std;

IteratedFunctionSystem *ifs = nullptr;
const int iterations = 100000;

void draw(SimpleScreen &ss)
{
    ss.LockDisplay();
    double x = 0, y = 0;
    ALLEGRO_COLOR clr;
    for (int i{}; i < iterations; i++)
    {
        ifs->TransformPoint(x, y, clr);
        while (x < ss.worldXmin || x > ss.worldXmax || y < ss.worldYmin || y > ss.worldYmax)
            ifs->TransformPoint(x, y, clr);
        ss.DrawPoint(x, y, clr);
    }
    ss.UnlockDisplay();
}

void eventHandler(SimpleScreen &ss, ALLEGRO_EVENT &ev)
{
    if (ev.type == ALLEGRO_EVENT_KEY_CHAR)
    {
        if (ev.keyboard.keycode == ALLEGRO_KEY_Q)
        {
            if (ifs != nullptr)
            {
                delete ifs;
            }
            exit(0);
        }
        ss.Redraw();
    }
}

int main()
{
    SimpleScreen ss(draw, eventHandler);
    ss.SetZoomFrame("white", 3);

    ss.SetWorldRect(-2, -2, 6, 6);

    ifs = new IteratedFunctionSystem();

    ifs->SetBaseFrame(0, 0, 4, 4);

    double p = 1. / 4;

    ifs->AddMapping(0, 0, 2, 0, 0, 2, "blue", p);
    ifs->AddMapping(2, 0, 4, 0, 2, 2, "yellow", p);
    ifs->AddMapping(0, 2, 2, 2, 0, 4, "red", p);
    ifs->AddMapping(0, 0, 0, 0, 0, 0, "green", p);

    ifs->GenerateTransforms();

    ss.HandleEvents();

    delete ifs;

    return 0;
}
