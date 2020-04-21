#include "stdafx.h"

using namespace std;

void decay_carbon14()
{
    // Set number of time steps in simulation
    const int timeSteps{ 100 };

    double timeAt[timeSteps];
    double nuclei[timeSteps];

    // Set percent of nuclei initially present
    nuclei[0] = 100;

    // Half-life of Carbon-14 (years)
    const double halfLife{ 1 };

    // Duration of simulation (years)
    const double endTime{ 1 };

    // Calculate time step (delta t)
    const double deltaTime{ endTime / timeSteps };

    // Calculate decay factor
    const double decayFactor = deltaTime / halfLife;

    // Set initial time
    timeAt[0] = 0.0;

    // Perform Euler method to estimate differential equation
    for (int step{}; step < timeSteps - 1; ++step)
    {
        nuclei[step + 1] = nuclei[step] - nuclei[step] * decayFactor;
        timeAt[step + 1] = timeAt[step] + deltaTime;
    }

    // Graph the decay curve using CERN's ROOT libraries
    TCanvas* c1 = new TCanvas("Carbon-14 Tau Graph");
    c1->SetTitle("Lab 1 - Nuclear Decay");

    TGraph* g1 = new TGraph(timeSteps, timeAt, nuclei);

    g1->SetTitle("Radioactive Decay of Carbon-14;time (yrs);% of Original Amount");
    g1->SetMarkerStyle(kFullDotMedium);
    g1->SetLineColor(2);
    g1->Draw();
}
