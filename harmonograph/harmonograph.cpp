#include "stdafx.h"

using namespace std;

void harmonograph()
{
    const double g = 9.8; // (m/s^2)

    const int timeSteps{2500};
    const double endTime{10};
    const double deltaTime{endTime / timeSteps};

    vector<double> time(timeSteps, 0);
    vector<double> omega1(timeSteps, 0);
    vector<double> theta1(timeSteps, 0);
    vector<double> omega2(timeSteps, 0);
    vector<double> theta2(timeSteps, 0);

    // Set first pendulum initial conditions
    const double length1 = 1.0; // (m)
    theta1.at(0) = M_PI / 18.0; // (~10 degrees)
    omega1.at(0) = 0.0;         // (rads/s)

    // Set second pendulum initial conditions
    const double length2 = 1.5; // (m)
    theta2.at(0) = M_PI / 18.0; // (~10 degrees)
    omega2.at(0) = 0.0;         // (rads/s)

    const double phaseConstant1 = g / length1;
    const double phaseConstant2 = g / length2;

    // Perform Euler-Cromer method to estimate differential equation
    for (int step{}; step < timeSteps - 1; ++step)
    {
        // First pendulum
        omega1.at(step + 1) = omega1.at(step) - phaseConstant1 * theta1.at(step) * deltaTime;
        theta1.at(step + 1) = theta1.at(step) + omega1.at(step + 1) * deltaTime;
        // Second pendulum
        omega2.at(step + 1) = omega2.at(step) - phaseConstant2 * theta2.at(step) * deltaTime;
        theta2.at(step + 1) = theta2.at(step) + omega2.at(step + 1) * deltaTime;
        // Update time
        time.at(step + 1) = time.at(step) + deltaTime;
    }

    // Graph the decay curve using CERN's ROOT libraries
    TCanvas *c1 = new TCanvas("Two Pendulum Harmonograph");
    c1->SetTitle("Two Pendulum Harmonograph - Euler-Cromer Method");

    TGraph *g1 = new TGraph(timeSteps, theta1.data(), theta2.data());

    g1->SetTitle("Two Pendulum Harmonograph - Euler-Cromer Method;theta (radians);theta (radians)");
    g1->SetMarkerStyle(kDot);
    g1->SetMarkerColor(kBlue);
    g1->SetLineColor(kBlue);
    g1->SetLineWidth(2);
    g1->Draw();
}
