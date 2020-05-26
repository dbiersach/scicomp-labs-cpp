#include "stdafx.h"

using namespace std;

int main()
{
	int ageInYears = 53;

	int ageInSeconds =
		ageInYears * 60 * 60 * 24 * 365;

	cout.imbue(locale(""));

	cout << "My age is:" << endl;
	cout << ageInYears << " (yrs)" << endl;
	cout << ageInSeconds << " (s)" << endl;

	return 0;
}
