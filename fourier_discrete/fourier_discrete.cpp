#include "stdafx.h"

using namespace std;

vector<double> xOrd;    // Sample # (0-99)
vector<double> xAct;    // Actual X value sampled
vector<double> yAct;    // Actual Y value sampled
vector<double> xRad;    // Scaled X value (radians)
vector<double> fCos;    // Frequency Cosine Amplitude
vector<double> fSin;    // Frequence Sine Amplitude
vector<double> yEst;    // Reconstructed Y value
vector<double> yPower;  // Frequency Power Amplitude

void LoadSamples(string filename)
{
    ifstream infile(filename);
    if (!infile.is_open())
    {
        cout << "Unable to open " << filename << endl;
        exit(-1);
    }
    string line{};
    const regex comma(",");
    while (infile && getline(infile, line))
    {
        vector<string> row{
            sregex_token_iterator(line.begin(), line.end(), comma, -1),
            sregex_token_iterator()};
        xAct.push_back(stod(row.at(0)));
        yAct.push_back(stod(row.at(1)));
        xOrd.push_back(xAct.size() - 1);
    }
}

void ScaleDomain()
{
    double delta = (2 * M_PI) / xAct.size();
    for (size_t i{}; i < xAct.size(); ++i)
        xRad.push_back(delta * i);
}

void CalcDFT()
{
    const size_t sample_count{yAct.size()};
    const size_t term_count{sample_count / 2};

    for (size_t term{0}; term < term_count; ++term)
    {
        double fcos{0}, fsin{0};
        for (size_t i{0}; i < sample_count; ++i)
        {
            double xs = xRad.at(i);
            double ys = yAct.at(i);
            fcos += cos(term * xs) * ys;
            fsin += sin(term * xs) * ys;
        }
        fcos /= sample_count;
        fsin /= sample_count;
        if (term > 0)
        {
            fcos *= 2;
            fsin *= 2;
        }
        fCos.push_back(fcos);
        fSin.push_back(fsin);
    }
}

void CalcIDFT()
{
    size_t sample_count{yAct.size()};
    size_t term_count{fCos.size()};

    for (size_t i{}; i < sample_count; ++i)
    {
        double xs = xRad.at(i);
        double yt{};
        for (size_t term{}; term < term_count; ++term)
        {
            yt += fCos.at(term) * cos(term * xs);
            yt += fSin.at(term) * sin(term * xs);
        }
        yEst.push_back(yt);
    }
}

void CalcPowerSpectrum()
{
    size_t term_count{fCos.size()};
    for (size_t term{}; term < term_count; ++term)
        yPower.push_back(sqrt(pow(fCos.at(term), 2) + pow(fSin.at(term), 2)));
}

void PlotTransforms()
{
    string c1Title{"Samples"};
    TCanvas *c1 = new TCanvas(c1Title.c_str());
    c1->SetTitle(c1Title.c_str());
    TMultiGraph *mg1 = new TMultiGraph();
    mg1->SetTitle(c1Title.c_str());
    TGraph *g1 = new TGraph(xAct.size(), xAct.data(), yAct.data());
    g1->SetLineColor(kBlue);
    g1->SetLineWidth(2);
    mg1->Add(g1);
    TGraph *g2 = new TGraph(xAct.size(), xAct.data(), yEst.data());
    g2->SetLineColor(kRed);
    g2->SetLineWidth(2);
    mg1->Add(g2);
    mg1->Draw("AL");
    TLegend *leg1 = new TLegend(0.8, 0.85, 0.9, 0.9);
    leg1->AddEntry(g1, "Actual", "l");
    leg1->AddEntry(g2, "Reconstructed", "l");
    leg1->Draw();

    string c2Title{"Discrete Fourier Transform"};
    TCanvas *c2 = new TCanvas(c2Title.c_str());
    c2->SetTitle(c2Title.c_str());
    TMultiGraph *mg2 = new TMultiGraph();
    mg2->SetTitle(c2Title.c_str());
    TGraph *g3 = new TGraph(fCos.size(), xOrd.data(), fCos.data());
    g3->SetFillColor(kBlue);
    mg2->Add(g3);
    TGraph *g4 = new TGraph(fSin.size(), xOrd.data(), fSin.data());
    g4->SetFillColor(kRed);
    mg2->Add(g4);
    mg2->Draw("AB");
    TLegend *leg2 = new TLegend(0.85, 0.85, 0.9, 0.9);
    leg2->AddEntry(g3, "fCos", "f");
    leg2->AddEntry(g4, "fSin", "f");
    leg2->Draw();
    mg2->GetXaxis()->SetLimits(0, fCos.size());
    gPad->Modified();

    string c3Title{"Power Spectrum"};
    TCanvas *c3 = new TCanvas(c3Title.c_str());
    c3->SetTitle(c3Title.c_str());
    TMultiGraph *mg3 = new TMultiGraph();
    mg3->SetTitle(c3Title.c_str());
    TGraph *g5 = new TGraph(yPower.size(), xOrd.data(), yPower.data());
    g5->SetFillColor(kGreen);
    mg3->Add(g5);
    mg3->Draw("AB");
    mg3->GetXaxis()->SetLimits(0, fCos.size());
    gPad->Modified();
}

void fourier_discrete(string filename)
{
    LoadSamples(filename);

    ScaleDomain();

    CalcDFT();

    CalcIDFT();

    CalcPowerSpectrum();

    PlotTransforms();
}
