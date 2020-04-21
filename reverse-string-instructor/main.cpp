#include "stdafx.h"

using namespace std;

string ReverseString(string a)
{
    string b;

    for(int i = a.length() - 1; i >= 0; --i)
        b += a.at(i);

    return b;
}

int main()
{
    string s = "Forever Young";
    string r = ReverseString(s);

    cout << "Original string = "
         << s << endl;

    cout << "Reversed string = "
         << r << endl;

    reverse(s.begin(),s.end());

    cout << "  STL reverse() = "
         << s << endl;

    return 0;
}
