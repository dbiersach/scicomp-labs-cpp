#include "stdafx.h"

using namespace std;

void decay_flourine18()
{
    // Half-life of Fluorine-18 (secs to hours)
    const double halfLife{6586.0 / 60 / 60};

    // Set number of time steps in simulation
    const int timeSteps{100};

    // Duration of simulation (hours)
    const double endTime{12};

    // Calculate time step (delta t)
    const double deltaTime{endTime / timeSteps};

    // Calculate decay factor
    const double decayFactor = deltaTime / halfLife;

    // Initialize domain and range vectors
    vector<double> time(timeSteps, 0);
    vector<double> nuclei(timeSteps, 0);

    // Set percent of nuclei initially present
    nuclei.at(0) = 100;

    // Perform Euler method to estimate differential equation
    for (int step{}; step < timeSteps - 1; ++step)
    {
        nuclei.at(step + 1) = nuclei.at(step) - nuclei.at(step) * decayFactor;
        time.at(step + 1) = time.at(step) + deltaTime;
    }

    // Graph the decay curve using CERN's ROOT libraries
    TCanvas *c1 = new TCanvas("Fluorine-18 Tau Graph");
    c1->SetTitle("Lab 1 - Nuclear Decay");

    TGraph *g1 = new TGraph(timeSteps, time.data(), nuclei.data());

    g1->SetTitle("Radioactive Decay of Fluorine-18;time (h);% of Original Amount");
    g1->SetMarkerStyle(kFullDotMedium);
    g1->SetLineColor(2);
    g1->Draw();
}
