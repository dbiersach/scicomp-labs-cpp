#include "stdafx.h"

using namespace std;

void freq_histogram(string filename)
{
    // Open file at the end (ios::ate) so the next "get"
    // position will return the actual file size
    ifstream ifs(filename, ios::binary | ios::ate);
    ifstream::pos_type pos = ifs.tellg();

    // Allocate a vector big enough to hold all the file bytes
    vector<unsigned char> fileBytes(pos);

    // Read in the file from the beginning straight into the vector
    ifs.seekg(0, ios::beg);
    ifs.read((char*)(fileBytes.data()), pos);

    // Create a ROOT chart
    string title = "Frequency Analysis";
    TCanvas* c1 = new TCanvas(title.c_str());
    c1->SetTitle(title.c_str());

    // Create a ROOT one dimensional histogram of integers
    TH1I* h1 = new TH1I(nullptr, title.c_str(), 256, 0, 257);
    h1->SetStats(kFALSE);

    TAxis* ya = h1->GetYaxis();
    ya->SetTitle("Count");
    ya->CenterTitle();

    TAxis* xa = h1->GetXaxis();
    xa->SetTitle("ASCII Value");
    xa->CenterTitle();
    xa->SetTickSize(0);

    // Fill the histogram using the bytes in the file
    for (auto item : fileBytes)
        h1->Fill((int)item);

    // Label any bin with the ASCII value
    // if the bin count is > 6% of the file size,
    // as these would be noteworthy occurrences
    for (int i{1}; i < xa->GetNbins(); ++i)
        if (h1->GetBinContent(i) > fileBytes.size() * 0.06)
            xa->SetBinLabel(i, to_string(i).c_str());

    h1->Draw();
}
