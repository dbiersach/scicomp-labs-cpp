#include "stdafx.h"

using namespace std;

vector<int> NormalizeCF(vector<int>& terms)
{
    if (terms.size() < 19 && terms.back() == 1)
    {
        terms.pop_back();
        terms.back()++;
    }
    return terms;
}

vector<int> EncodeCF(double x)
{
    vector<int> terms;
    while(terms.size() < 20)
    {
        terms.push_back(floor(x));
        x = x - floor(x);
        if (x < 1e-9) break;
        x = 1/x;
    }
    return NormalizeCF(terms);
}

void DisplayCF(const vector<int>& terms)
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
    double x = 3.245;

    auto terms = EncodeCF(x);

    cout << "To " << terms.size() << " terms, "
         << "the simple continued fraction for\n"
         << setprecision(14) << x << " is" << endl;

    DisplayCF(terms);

    return 0;
}
