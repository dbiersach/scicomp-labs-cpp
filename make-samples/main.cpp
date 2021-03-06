#include "stdafx.h"

using namespace std;

int main()
{
    // Vector of tuples to store x, y values
    const auto samples{make_unique<vector<tuple<double, double>>>()};

    // Number of samples
    size_t nx{100};

    // Delta X
    double dx{2 * M_PI / nx};

    for (double x{0}; nx > 0; x += dx, --nx)
    {
        double y{29 * cos(3 * x) + 7 * cos(19 * x) + 17 * sin(11 * x) + 2 * sin(31 * x)};
        samples->push_back(make_tuple(x, y));
    }

    // Create samples file
    string filename{"samples.csv"};
    ofstream outfile(filename);
    outfile.exceptions(ofstream::failbit);

    for (const auto &d : *samples)
    {
        outfile << fixed << get<0>(d) << ", ";
        outfile << fixed << get<1>(d) << endl;
    }
    outfile.flush();
    outfile.close();

    cout << "Created file " << filename << endl;

    return 0;
}
