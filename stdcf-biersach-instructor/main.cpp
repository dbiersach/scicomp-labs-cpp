#include "stdafx.h"

using namespace std;

vector<int> EncodeCF(double x)
{
    vector<int> terms;
    while(terms.size() < 7)
    {
        terms.push_back(floor(x));
        x = x - floor(x);
        if (x < 1e-9) break;
        x = 1/x;
    }
    return terms;
}

void DisplayCF(vector<int> terms)
{
    cout << "{";
    auto itr = terms.begin();
    while (true)
    {
        cout << *itr;
        if (++itr == terms.end()) break;
        cout << ", ";
    }
    cout << "}\n";
    return;
}

int main()
{
    for (int n{ 1 }; n < 10; n++)
    {
        double x = (sqrt(4 * n*n - 4 * n + 5) + 1) / 2;
        DisplayCF(EncodeCF(x));
    }
    return 0;
}
