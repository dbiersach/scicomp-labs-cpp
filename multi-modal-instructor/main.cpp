#include "stdafx.h"

using namespace std;

vector<int> FindModes(vector<int> data)
{
    // Prepare return vector
    vector<int> modes;

    // Tally occurances like a histogram
    vector<int> occurances(data.size(), 0);
    for (auto s : data)
        occurances.at(s)++;

    // Find element occurring most often
    int maxOccurance =
        *max_element(
            occurances.begin(), occurances.end());

    // Copy every element with highest occurance
    // to the return vector
    for (size_t i{}; i < occurances.size(); i++)
        if (occurances.at(i) == maxOccurance)
            modes.push_back(i);

    return modes;
}

int main()
{
    // Prepare data vector
    vector<int> data {7,1,2,3,7,4,5,6,7,1,2,1,1,9,7,10,2,2};

    cout << "The modes of the data are: " << endl;
    for (auto& n : FindModes(data))
        cout << n << endl;

    return 0;
}

