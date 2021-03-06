#include "stdafx.h"

using namespace std;

const int n = 420;

vector<double> x(n + 1);
vector<double> y(n + 1);

void InitData(double a, double b) {
  double dx = (a + b) / n;

  for (int i = 0; i <= n; i++) {
    x.at(i) = a + i * dx;
    y.at(i) = sin(4 * M_PI * x.at(i)) * sin(6 * M_PI * x.at(i)) *
              sin(10 * M_PI * x.at(i)) * sin(14 * M_PI * x.at(i));
  }
}

void nyquist_unknown() {
  InitData(0, 210);

  TCanvas* c = new TCanvas((string()
                                .append("Sinusoid Aliasing (")
                                .append(to_string(n))
                                .append(" samples)"))
                               .c_str());

  TMultiGraph* mg = new TMultiGraph();
  string title = "y=UNKNOWN (" + to_string(n) + " samples)";
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
