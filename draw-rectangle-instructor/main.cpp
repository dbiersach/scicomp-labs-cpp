#include "stdafx.h"
#include "simplescreen.h"

using namespace std;

int main()
{
	SimpleScreen ss;
	ss.SetWorldRect(-30, -30, 30, 30);
	ss.DrawAxes();

	PointSet ps;
	ps.add(0, 0);
	ps.add(21, 0);
	ps.add(21, 10);
	ps.add(0, 10);

	ss.DrawLines(&ps, "violet", 1, true, true);

	ss.HandleEvents();

	return 0;
}
