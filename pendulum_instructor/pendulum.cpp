#include "stdafx.h"

using namespace std;

void pendulum()
{
	const double length = 1.0; // (m)
	const double g = 9.8;	   // (m/s^2)
	const double phaseConstant = g / length;

	// Set number of time steps in simulation
	const int timeSteps{250};

	// Duration of simulation (secs)
	const double endTime{10};

	// Calculate time step (delta t)
	const double deltaTime{endTime / timeSteps};

	vector<double> time(timeSteps,0);
	vector<double> omega(timeSteps,0);
	vector<double> theta(timeSteps,0);

	// Set initial pendulum angular velocity
	omega.at(0) = 0.0;

	// Set initial pendulum displacement
	theta.at(0) = M_PI / 18.0;

	// Perform Euler method to estimate differential equation
	for (int step{}; step < timeSteps - 1; ++step)
	{
		omega.at(step + 1) = omega.at(step) - phaseConstant * theta.at(step) * deltaTime;
		theta.at(step + 1) = theta.at(step) + omega.step(step + 1) * deltaTime;
		time.at(step + 1) = time.at(step) + deltaTime;
	}

	// Graph the decay curve using CERN's ROOT libraries
	TCanvas *c1 = new TCanvas("Harmonic Motion - Euler-Cromer Method");
	c1->SetTitle("Simple Pendulum - Euler-Cromer Method");

	TGraph *g1 = new TGraph(timeSteps, time.data(), theta.data());

	g1->SetTitle("Simple Pendulum - Euler-Cromer Method;time (s);theta (radians)");
	g1->SetLineColor(kBlue);
	g1->SetLineWidth(3);

	g1->Draw();
}
