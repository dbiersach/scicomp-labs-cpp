// vigenere-cipher.cpp

#include "stdafx.h"

using namespace std;

int main()
{
	string plaintext = "Attack at Dawn";
	string keyword = "Lemon";

	// Remove spaces and convert to UPPERCASE
	boost::algorithm::erase_all(plaintext, " ");
	boost::algorithm::to_upper(plaintext);
	boost::algorithm::to_upper(keyword);

	// Create UPPERCASE alphabet
	string alphabet;
	for (int i{}; i < 26; i++)
		alphabet += char('A' + i);

	// Create tabula recta
	vector<string> table;
	for (size_t i{ 0 }; i < alphabet.length(); i++)
		table.push_back(
			alphabet.substr(i, alphabet.length() - i)
			+ alphabet.substr(0, i));

	// Encrypt plaintext
	string ciphertext;
	for (size_t i{}; i < plaintext.length(); i++)
	{
		size_t row = keyword[i % keyword.length()] - alphabet[0];
		size_t col = plaintext[i] - alphabet[0];
		ciphertext += table.at(row).at(col);
	}

	// Decrypt ciphertext
	string decryption;
	for (size_t i{}; i < ciphertext.length(); i++)
	{
		size_t row = keyword[i % keyword.length()] - alphabet[0];
		size_t col = table.at(row).find_first_of(ciphertext.at(i), 0);
		decryption += alphabet.at(col);
	}

	cout << right;
	cout << setw(14) << "Plaintext = " << plaintext << endl << endl;
	cout << setw(14) << "Keyword = " << keyword << endl << endl;
	cout << setw(14) << "Ciphertext = " << ciphertext << endl << endl;
	cout << setw(14) << "Decryption = " << decryption << endl;
	cout << endl;

	return 0;
}

