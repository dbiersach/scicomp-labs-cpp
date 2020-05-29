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

	ss.SetWorldRect(0, 0, 30, 30);

	ifs = new IteratedFunctionSystem();

	ifs->SetBaseFrame(0, 0, 30, 30);

	double p = 1. / 6;

	double h = 10.0 * sqrt(3) / 2.0; // 10 * sin(60 degrees)

	ifs->AddMapping(25, 15, 15, 15, 20, 15 + h, "blue", p);		// COD
	ifs->AddMapping(20, 15 + h, 15, 15, 10, 15 + h, "blue", p); // DOE
	ifs->AddMapping(10, 15 + h, 15, 15, 5, 15, "blue", p);		// EOF
	ifs->AddMapping(5, 15, 15, 15, 10, 15 - h, "blue", p);		// FOA
	ifs->AddMapping(10, 15 - h, 15, 15, 20, 15 - h, "blue", p); // AOB
	ifs->AddMapping(20, 15 - h, 15, 15, 25, 15, "blue", p);		// BOC

	ifs->GenerateTransforms();

	ss.HandleEvents();

	delete ifs;

	return 0;
}
