#include "stdafx.h"

using namespace std;

void damped_pendulum()
{
    // Set number of time steps in simulation
    const int timeSteps{250};

    double timeAt[timeSteps];
    double omega[timeSteps];
    double theta[timeSteps];

    const double length = 1.0; // (m)
    const double g = 9.8;      // (m/s^2)

    const double phaseConstant = g / length;

    // Set initial pendulum angular velocity
    omega[0] = 0.0;

    // Set initial pendulum displacement
    theta[0] = M_PI / 18.0;

    // Duration of simulation (secs)
    const double endTime{10};

    // Calculate time step (delta t)
    const double deltaTime{endTime / timeSteps};

    // Set initial time
    timeAt[0] = 0.0;

    // Perform Euler method to estimate differential equation
    for (int step{}; step < timeSteps - 1; ++step)
    {
		omega[step + 1] = omega[step] - phaseConstant * theta[step] * deltaTime - omega[step] * deltaTime;
		theta[step + 1] = theta[step] + omega[step + 1] * deltaTime;
		timeAt[step + 1] = timeAt[step] + deltaTime;
    }

    // Graph the decay curve using CERN's ROOT libraries
    string title = "Damped Pendulum using Euler-Cromer Method";
    TCanvas *c1 = new TCanvas(title.c_str());
    c1->SetTitle(title.c_str());

    TGraph *g1 = new TGraph(timeSteps, timeAt, theta);

    g1->SetTitle((title + ";time (s);#theta (radians)").c_str());
    g1->SetLineColor(kBlue);
    g1->SetLineWidth(3);
    g1->Draw();
}
