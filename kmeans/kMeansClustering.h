// kMeansClustering.h

#pragma once

#include "stdafx.h"

//using std::string;
//using std::vector;

class Cluster
{
public:
    Cluster(int index);
    double x{};
    double y{};
    string clr{};
    int population{};
};

class DataPoint
{
public:
    DataPoint() = default;
    DataPoint(double new_x, double new_y);
    double x{};
    double y{};
    Cluster* c{nullptr};
};


