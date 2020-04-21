#include "cluster.h"

// Cluster
Cluster::Cluster()
{
    x = 0;
    y = 0;
    clr = "";
    population = 0;
}

Cluster::Cluster(int index)
    :Cluster()
{
    if (index == 0)
        clr = "red";
    if (index == 1)
        clr = "blue";
    if (index == 2)
        clr = "green";
    if (index == 3)
        clr = "orange";
    if (index == 4)
        clr = "yellow";
    if (index == 5)
        clr = "white";
}

Cluster::~Cluster()
{

}

// DataPoint
DataPoint::DataPoint()
{
    x = 0;
    y = 0;
    c = nullptr;
}

DataPoint::DataPoint(double x, double y)
    :DataPoint()
{
    this->x = x;
    this->y = y;
}

DataPoint::~DataPoint()
{

}


