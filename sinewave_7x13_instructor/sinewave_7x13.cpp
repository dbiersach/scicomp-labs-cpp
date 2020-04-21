#include "stdafx.h"

using namespace std;

const double b = 26;
const int n = 640;

vector<double> x(n + 1);
vector<double> y(n + 1);

void InitData()
{
    double dx = b / n;

    for (int i = 0; i <= n; i++)
    {
        x.at(i) = i * dx;
        y.at(i) = sin(14.0 / 13.0 * M_PI * x.at(i));
    }
}

void sinewave_7x13()
{
    InitData();

    TCanvas* c = new TCanvas(
        (string().append("Sinusoid Aliasing (")
         .append(to_string(n))
         .append(" samples)")).c_str());

    TMultiGraph* mg = new TMultiGraph();
    string title = "y=UNKNOWN ("
                   + to_string(n) + " samples)";
    mg->SetTitle(title.c_str());
    gStyle->SetTitleFontSize(0.03f);

    mg->SetMinimum(-1.);
    mg->SetMaximum(1.);

    TGraph* g = new TGraph(n + 1, &x.at(0), &y.at(0));
    g->SetLineColor(kBlue);
    g->SetMarkerColor(kRed);
    g->SetMarkerStyle(kFullDotLarge);

    mg->Add(g);
    mg->Draw("ALP");

    mg->GetXaxis()->SetTitle("x");
    mg->GetYaxis()->SetTitle("y");

    gPad->Modified();
}
