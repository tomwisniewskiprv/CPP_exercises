//-----------------------------------------------------------------------
// Exercises from other group - just for fun
//-----------------------------------------------------------------------

#include "exercises6_1_gr2.h"


//-----------------------------------------------------------------------
// Palindrom - another version :(
// Checks if whole sentence (only alphanumeric chars counts) is a palindrom.
//-----------------------------------------------------------------------
void lab6_1_ex3() {

	string text = "Ile Roman ladny dyndal na moreli";
	string striped;
	cout << text << endl;

	for (size_t i = 0; i < text.length(); i++) {
		if (isalpha(text[i]))
			striped += (char)tolower(text[i]);
	}

	for (size_t front = 0, back = striped.size() - 1; striped[front] == striped[back] && front <= (striped.size() / 2); front++, back--)
		if (front == back || front > back) cout << "Palindrom: " << text << endl;

}


//-----------------------------------------------------------------------
// Cesar cipher
// Encrypts whole file.
//-----------------------------------------------------------------------
void lab6_1_ex9() {

	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string plain_text = "TEKST do ZASZYFROWANIA!" "\nDruga linia tajnego tekstu.";
	string ciphertext;

	ofstream fout;
	fout.open("plaintext.txt");
	fout << plain_text << endl;
	fout.close();

	ifstream fin;
	fin.open("plaintext.txt");
	while (getline(fin , plain_text)) {
		ciphertext += plain_text + '\n';
	}
	fin.close();

	plain_text = ciphertext;

	string encrypted;
	string decrypted;

	int key = 1;
	const int letters = 26;

	for (int i = 0; i < plain_text.size(); i++) {
		if (isalpha(plain_text[i]))
			encrypted += (char)((( plain_text[i] - (isupper(plain_text[i])?'A':'a') + key) % letters) + (isupper(plain_text[i])?'A':'a'));
		else
			encrypted += plain_text[i];
	}
	cout << encrypted << endl;

	ofstream encrypted_file("ciphertext.txt");
	encrypted_file << encrypted;
	encrypted_file.close();

	for (int i = 0; i < encrypted.size(); i++) {
		if (isalpha(encrypted[i]))
			decrypted += (char)(((encrypted[i] - (isupper(encrypted[i]) ? 'A' : 'a') - key + letters) % letters) + (isupper(encrypted[i]) ? 'A' : 'a'));
		else
			decrypted += encrypted[i];
	}

	cout << decrypted << endl;


}