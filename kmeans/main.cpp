#include "stdafx.h"
#include "simplescreen.h"
#include "kMeansClustering.h"

using namespace std;

int num_clusters{3};
double mean_multiple{0};

vector<DataPoint*>* dataPoints{};
vector<Cluster*>* clusters{};
bool converged{};

double GetDistance(double x1, double y1, double x2, double y2 )
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

void InitDataPoints()
{
    dataPoints = new vector<DataPoint*>();
    dataPoints->push_back(new DataPoint(23, 35));
    dataPoints->push_back(new DataPoint(35, 18));
    dataPoints->push_back(new DataPoint(14, 3));
    dataPoints->push_back(new DataPoint(17, 6));
    dataPoints->push_back(new DataPoint(38, 15));
    dataPoints->push_back(new DataPoint(26, 41));
    dataPoints->push_back(new DataPoint(27, 38));
    dataPoints->push_back(new DataPoint(30, 35));
    dataPoints->push_back(new DataPoint(19, 12));
    dataPoints->push_back(new DataPoint(24, 32));
    dataPoints->push_back(new DataPoint(41, 26));
    dataPoints->push_back(new DataPoint(38, 24));
    dataPoints->push_back(new DataPoint(36, 21));
    dataPoints->push_back(new DataPoint(30, 32));
    dataPoints->push_back(new DataPoint(17, 3));
    dataPoints->push_back(new DataPoint(12, 5));
    dataPoints->push_back(new DataPoint(24, 38));
    dataPoints->push_back(new DataPoint(14, 6));
    dataPoints->push_back(new DataPoint(27, 32));
    dataPoints->push_back(new DataPoint(17, 9));
    //dataPoints->push_back(new DataPoint(5, 40));
}

void InitClusters()
{
    clusters = new vector<Cluster*>();
    for (int i{}; i < num_clusters; ++i)
        clusters->push_back(new Cluster(i));
    // Assign each data point to an initial
    // cluster in a round-robin fashion
    for (size_t i{}; i < dataPoints->size(); ++i)
    {
        Cluster* c = clusters->at(i % clusters->size());
        dataPoints->at(i)->c = c;
        c->population++;
    }
}

void UpdateClusters()
{
    // Phase I: Calculate the new geometric mean of each
    // cluster based upon current data point assignments
    bool phase1_change{false};
    for (auto c : *clusters)
    {
        DataPoint newCenter;
        double count{};
        for (auto dp : *dataPoints)
        {
            if (dp->c == c)
            {
                newCenter.x += dp->x;
                newCenter.y += dp->y;
                count++;
            }
        }
        newCenter.x /= count;
        newCenter.y /= count;
        // Move cluster center (mean) if necessary
        if (newCenter.x != c->x || newCenter.y != c->y)
        {
            c->x = newCenter.x;
            c->y = newCenter.y;
            phase1_change = true;
        }
    }

    // Phase II: Assign data points to nearest cluster
    bool phase2_change{false};
    for (auto dp : *dataPoints)
    {
        double distMin = numeric_limits<double>::max();
        Cluster* cNearest = nullptr;
        for (auto c : *clusters)
        {
            double dist = GetDistance(dp->x, dp->y, c->x, c->y);
            if (dist < distMin)
            {
                distMin = dist;
                cNearest = c;
            }
        }
        // If the nearest cluster to this point is NOT
        // the point's currently assigned cluster...
        if (cNearest != dp->c)
        {
            // Then reassign data point to the new cluster, but only
            // if this is not the last point the current cluster.
            // Reassignment must never result in an empty cluster
            if (dp->c->population > 1)
            {
                dp->c->population--;
                // Assign point to new (nearer) cluster
                dp->c = cNearest;
                dp->c->population++;
                phase2_change = true;
            }
        }
    }

    // Phase III - Evict points too far from its cluster center
    if (mean_multiple > 0 && !phase1_change && !phase2_change && !converged)
    {
        // Calculate the mean distance from each
        // cluster's center to each of its assigned points
        for (auto c : *clusters)
        {
            double count_points{};
            double total_distance{};
            for (auto dp : *dataPoints)
            {
                if (dp->c == c)
                {
                    total_distance += GetDistance(dp->x, dp->y, c->x, c->y);
                    count_points++;
                }
            }
            c->mean_distance = total_distance / count_points;
        }
        // Check the distance of each point to its' cluster center.
        // If that distance is greater than the "mean_multiple" for
        // that cluster, then evict (remove) that data point
        auto itr = dataPoints->begin();
        while (itr != dataPoints->end())
        {
            DataPoint* dp = *itr;
            Cluster* c = dp->c;
            double dist_center = GetDistance(dp->x, dp->y, c->x, c->y);

            if (dist_center > c->mean_distance * mean_multiple)
                itr = (*dataPoints).erase(itr);
            else
                itr++;
        }
        converged = true;
    }
}

void draw(SimpleScreen& ss)
{
    ss.Clear();
    ss.DrawAxes();
    // Draw each data point
    for (auto dp : *dataPoints)
        ss.DrawRectangle(dp->c->clr, dp->x, dp->y, 1, 1, 0, true);
    // Draw each cluster's geometric center (the "mean")
    for (auto c : *clusters)
        ss.DrawCircle(c->x, c->y, 1, c->clr, 2);
    ss.Update();
}

void eventHandler(SimpleScreen& ss, ALLEGRO_EVENT& ev)
{
    if (ev.type == ALLEGRO_EVENT_KEY_CHAR)
    {
        switch (ev.keyboard.keycode)
        {
        case ALLEGRO_KEY_S:
            UpdateClusters();
            ss.Redraw();
            break;
        case ALLEGRO_KEY_Q:
            ss.Exit();
            break;
        }
    }
}

int main()
{
    SimpleScreen ss(draw, eventHandler);
    ss.SetWorldRect(-5, -5, 45, 45);

    cout << "Press S to single step the cluster algorithm\n";
    cout << "Press Q to quit the application\n";

    InitDataPoints();

    InitClusters();

    ss.HandleEvents();

    return 0;
}
