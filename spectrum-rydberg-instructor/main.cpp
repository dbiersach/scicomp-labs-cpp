#include "stdafx.h"

using namespace std;

int main()
{
	const double R = 1.0967757e7;

	cout << "Rydberg Formula Hydrogen Spectral Lines" << endl;

	for (int k{ 1 }; k < 5; ++k) {
		for (int j{ k + 1 }; j < k + 6; ++j) {
			double lambda = 1 / (R * (1 / pow(k, 2) - 1 / pow(j, 2)));
			cout << setw(3) << j;
			cout << setw(10) << setprecision(0) << fixed;
			cout << lambda * 1e9 << "nm" << endl;
		}
		// Skip a line between families
		cout << endl;
	}

    return 0;
}
