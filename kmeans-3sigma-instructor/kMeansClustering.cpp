#include "stdafx.h"
#include "SimpleScreen.h"
#include "kMeansClustering.h"

using namespace std;

Cluster::Cluster(int index)
{
    if (index == 0) clr = "red";
    if (index == 1) clr = "blue";
    if (index == 2) clr = "green";
    if (index == 3) clr = "orange";
    if (index == 4) clr = "yellow";
    if (index == 5) clr = "white";
}

DataPoint::DataPoint(double new_x, double new_y)
{
    x = new_x;
    y = new_y;
}
