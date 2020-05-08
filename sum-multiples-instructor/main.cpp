#include "stdafx.h"

using namespace std;


int main()
{
    int termsMax = 1900;
    int sum = 0;

    for (int n = 1; n < termsMax; n++)
        if ((n % 7 == 0) && (n % 11 == 0))
            sum += n;

    cout.imbue(locale(""));

    cout << "The sum of all natural numbers less than "	<< termsMax << endl
         << "that are fully divisible by both 7 and 11 is " << sum << endl << endl;

    return 0;
}

