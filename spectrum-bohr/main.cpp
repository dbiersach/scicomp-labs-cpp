#include "stdafx.h"

using namespace std;

int main()
{
	const double eCharge = 1.6e-19;
	const double eMass = 9.1e-31;
	const double permittivity = 8.84e-12;
	const double hPlank = 6.63e-34;
	const double speedLight = 3e8;

	const double E0 = 0;

	cout << "Bohr Model Hydrogen Spectral Lines" << endl;
	cout << fixed << setprecision(0);

	for (int i{1}; i < 5; ++i)
	{
		for (int f{i + 1}; f < i + 6; ++f)
		{
			double Ei = 0;
			double Ef = 0;
			double lambda = 0;
			cout << setw(3) << f;
			cout << setw(10) << lambda << "nm";
			cout << endl;
		}
		// Skip a line between families
		cout << endl;
	}

	return 0;
}
