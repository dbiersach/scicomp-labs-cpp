#include "stdafx.h"

using namespace std;

int main()
{
    // Open the input and output files
    ifstream ifs("plaintext1.txt", ios::binary | ios::ate);
    ofstream ofs("ciphertext1.txt", ios::binary);
    //ifstream ifs("plaintext2.txt", ios::binary | ios::ate);
    //ofstream ofs("ciphertext2.txt", ios::binary);

    // Read the input file straight into the buffer
    ifstream::pos_type pos = ifs.tellg();
    vector<unsigned char> buff(pos);
    ifs.seekg(0, ios::beg);
    ifs.read((char*)(buff.data()), pos);
    ifs.close();

    // To produce ciphertext1.txt
    int shift = 45;

    // To produce ciphertext2.txt
    //int shift = -15;

    // Shift every character in plaintext
    for (auto& c : buff)
        c += shift;

    // Save the ciphertext file
    ofs.write((char*)buff.data(),buff.size());
    ofs.close();

    return 0;
}
