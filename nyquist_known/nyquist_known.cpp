#include "stdafx.h"

using namespace std;

const int n = 640;

vector<double> x(n + 1);
vector<double> y(n + 1);

void InitData(double a, double b) {
  double dx = (b - a) / n;

  for (int i = 0; i <= n; i++) {
    x.at(i) = a + i * dx;
    y.at(i) = sin(4.0 / 5.0 * M_PI * x.at(i));
  }
}

void nyquist_known() {
  InitData(0, 20);

  TCanvas* c = new TCanvas((string()
                                .append("Sinusoid Aliasing (")
                                .append(to_string(n))
                                .append(" samples)"))
                               .c_str());

  TMultiGraph* mg = new TMultiGraph();
  string title = "y=sin(#frac{4#pi}{5}x) (" + to_string(n) + " samples)";
  mg->SetTitle(title.c_str());
  gStyle->SetTitleFontSize(0.03f);

  mg->SetMinimum(-1.);
  mg->SetMaximum(1.);

  TGraph* g = new TGraph(n + 1, x.data(), y.data());
  g->SetLineColor(kBlue);
  g->SetMarkerColor(kRed);
  g->SetMarkerStyle(kFullDotLarge);

  mg->Add(g);
  mg->Draw("ALP");

  mg->GetXaxis()->SetTitle("x");
  mg->GetYaxis()->SetTitle("y");

  gPad->Modified();
}
