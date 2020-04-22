#pragma once

#include "stdafx.h"

using std::string;

class Cluster
{
public:
    Cluster(int index);
    double x{};
    double y{};
    string clr{};
    int population{};
    double mean_distance{};
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
