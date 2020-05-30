#include "stdafx.h"

using namespace std;

int main()
{
	const double R = 1.0967757e7;

	cout << "Rydberg Formula Hydrogen Spectral Lines" << endl;
	cout << fixed << setprecision(0);

	// k is the final orbit #
	for (int k{1}; k < 5; ++k)
	{
        // j is the initial orbit #
		for (int j{k + 1}; j < k + 6; ++j)
		{
			double lambda = 1 / (R * (1 / pow(k, 2) - 1 / pow(j, 2)));
			cout << setw(3) << j;
			cout << setw(10) << lambda * 1e9 << "nm";
			cout << endl;
		}
		// Skip a line between families
		cout << endl;
	}

	return 0;
}
