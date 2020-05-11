#include "stdafx.h"

using namespace std;

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
    return terms;
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
    double x = (1 + sqrt(5)) / 2;

    auto terms = EncodeCF(x);

    cout << "To " << terms.size() << " terms, "
         << "the simple continued fraction for\n"
         << setprecision(18) << x << " is" << endl;

    DisplayCF(terms);

    return 0;
}
