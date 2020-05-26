#include "stdafx.h"

using namespace std;

int main()
{
	int ageInYears = 0;

	int ageInSeconds = ageInYears;

	cout.imbue(locale(""));

	cout << "My age is:" << endl;
	cout << ageInYears << " (yrs)" << endl;
	cout << ageInSeconds << " (s)" << endl;

	return 0;
}
