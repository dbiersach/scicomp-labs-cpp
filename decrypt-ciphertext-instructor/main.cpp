#include "stdafx.h"

using namespace std;

int main()
{
	ifstream ifs("ciphertext2.txt", ios::binary | ios::ate);
	ifstream::pos_type pos = ifs.tellg();

	vector<uint8_t> fileBytes(pos);

	ifs.seekg(0, ios::beg);
	ifs.read((char*)(fileBytes.data()), pos);

	int shift = +15;

	for (auto b : fileBytes)
		cout << (char)(b + shift);

	cout << endl << endl;

	return 0;
}
