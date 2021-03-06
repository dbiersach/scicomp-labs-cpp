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

    ss.SetWorldRect(-5, -5, 55, 65);

    ifs = new IteratedFunctionSystem();

    ifs->SetBaseFrame(0, 0, 48, 48);

    ifs->AddMapping(24, 0, 24, 0, 24, 10, "green", 0.01);
    ifs->AddMapping(20, 4, 28, 17.5, 6, 12, "green", 0.07);
    ifs->AddMapping(20.5, 14, 28, -1, 35, 22.5, "green", 0.07);
    ifs->AddMapping(4, 12.5, 44, 9, 7.5, 53, "green", 0.85);

    ifs->GenerateTransforms();

    ss.HandleEvents();

    delete ifs;

    return 0;
}
