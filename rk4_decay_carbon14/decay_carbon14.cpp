#include "stdafx.h"

using namespace std;

// The differential equation
double f(double y, double x)
{
	return (-x) / 5730;  // Half-life of Carbon-14 (years)
}

// Fourth-Order Runge-Kutta Method for a single 1st order differential equation
void runge_kutta(double &y, double &x, const double dx,
	double(*f)(double, double))
{
	double k1 = f(y, x);
	double k2 = f(y + k1 * dx / 2, x + dx / 2);
	double k3 = f(y + k2 * dx / 2, x + dx / 2);
	double k4 = f(y + k3 * dx, x + dx);
	y += dx / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
	x += dx;
}

void rk4_decay_carbon14()
{
    // Duration of simulation (years)
    const double endTime{40000};

    // Set number of time steps in simulation
    const int timeSteps{100};

    // Calculate time step
    const double deltaTime{endTime / timeSteps};

    // Initialize domain and range vectors
    vector<double> time(timeSteps, 0);
    vector<double> nuclei(timeSteps, 0);

    // Set percent of nuclei initially present
    nuclei.at(0) = 100;

    double x = time.at(0);
    double y = nuclei.at(0);

    // Perform Euler method to estimate differential equation
    for (int step{1}; step < timeSteps; ++step)
    {
        runge_kutta(y, x, deltaTime, f);        
        time.at(step) = x;
        nuclei.at(step) = y;        
    }

    // Graph the decay curve using CERN's ROOT libraries
    TCanvas *c1 = new TCanvas("Carbon-14 Tau Graph");
    c1->SetTitle("Lab 3 - Nuclear Decay");

    TGraph *g1 = new TGraph(timeSteps, time.data(), nuclei.data());

    g1->SetTitle("Radioactive Decay of Carbon-14;time (yrs);% of Original Amount");
    g1->SetMarkerStyle(kFullDotMedium);
    g1->SetLineColor(2);
    g1->Draw();
}
