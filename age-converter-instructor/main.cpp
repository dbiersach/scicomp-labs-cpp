#include "stdafx.h"

using namespace std;

int main()
{
	double ageInYears = 51;

	double ageInSeconds =
		ageInYears * 60 * 60 * 24 * 365;

	cout.imbue(std::locale(""));
	cout << fixed << setprecision(2);

	cout << "Age (years) = "
		<< ageInYears << endl;

	cout << "Age (secs) = "
		<< ageInSeconds << endl;

    return 0;
}
