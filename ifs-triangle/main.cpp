#include "stdafx.h"
#include "simplescreen.h"
#include "ifs.h"

using namespace std;

IteratedFunctionSystem* ifs = nullptr;
const int iterations = 1000000;

void draw(SimpleScreen& ss)
{
    ss.LockDisplay();
    double x, y;
    ALLEGRO_COLOR clr;
    for (int i{}; i < iterations; i++)
    {
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

    ss.SetWorldRect(0, 0, 30, 30);

    ifs = new IteratedFunctionSystem();

    ifs->SetBaseFrame(0, 0, 30, 30);

    double p = 1. / 3;

    ifs->AddMapping(0, 0, 15, 0, 0, 15, "blue", p);
    ifs->AddMapping(15, 0, 30, 0, 15, 15, "blue", p);
    ifs->AddMapping(7.5, 15, 22.5, 15, 7.5, 30, "blue", p);

    ifs->GenerateTransforms();

    ss.HandleEvents();

    delete ifs;

    return 0;
}
