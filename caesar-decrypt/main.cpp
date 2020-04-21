#include "stdafx.h"

using namespace std;

int main()
{
    // Open the ciphertext file
    ifstream ifs("ciphertext1.txt", ios::binary | ios::ate);

    // Read the input file straight into the buffer
    ifstream::pos_type pos = ifs.tellg();
    vector<unsigned char> buff(pos);
    ifs.seekg(0, ios::beg);
    ifs.read((char*)(buff.data()), pos);
    ifs.close();

    int shift = 0;

    // Shift every character in ciphertext
    for (auto c : buff)
        cout << (char)(c + shift);

    cout << endl << endl;

    return 0;
}
