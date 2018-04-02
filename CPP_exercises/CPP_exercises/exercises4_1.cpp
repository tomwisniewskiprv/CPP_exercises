//-----------------------------------------------------------------------
// Strings and ciphers (basic ones at least)
//-----------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// Exercise 2 - lab4 - GADERYPOLUKI
void lab4_ex2() {
	string keys[] = {
		"GA-DE-RY-PO-LU-KI",
		"PO-LI-TY-KA-RE-NU",
		"KA-CE-MI-NU-TO-WY"
	};

	// ALA MA KOTA == GUG MG IPTG // dla gaderypoluki
	string input;
	string encoded = "";
	string decoded = "";
	bool char_found = false;
	int number = 0;
	int key = 0;

	for (string k : keys)
		cout << ++number << " " << k << endl;

	cout << "Wybierz klucz : ";
	getline(cin, input);
	key = stoi(input) - 1;

	cout << "Podaj tekst do zaszyfrowania/odszyfrowania:" << endl;
	getline(cin, input);

	encoded = input;

	for (int i = 0; i < encoded.size(); i++) {
		for (int k = 0; k <= keys[key].size(); k++) {
			if (encoded[i] == keys[key][k]) {
				switch (k % 3) {
				case 0:
					decoded += keys[key][k + 1];
					break;
				case 1:
					decoded += keys[key][k - 1];
					break;
				default:
					break;
				}
				char_found = true;
				break;
			}
			char_found = false;
		}
		if (!char_found) {
			decoded += encoded[i];
		}
	}

	decoded += '\n';
	cout << decoded << endl;
}

// Exercise 3 - lab4 - Simple substitution cipher
void lab4_ex3() {
	const int LETTERS = 26;
	string encoded = "DOXQRIRGB MFBOTPWX LPLYX ALPQXGB MIRPFHX";
	int key = 1;

	for (int i = 0; i < LETTERS; i++, key++) {
		for (int letter = 0; letter < (int)encoded.size(); letter++) {
			if (encoded[letter] != 32)
				cout << (char)(((encoded[letter] + key) % LETTERS) + 'A');
			else cout << " ";
		}

		cout << endl;
	}
}

// Exercise 6 - Immortal palindrom
void lab4_ex6() {

	string words[] = { "KAJAK" , "ABBA" , "Ala" , "AmMA" };

	for (auto word : words) {
		for (int start = 0, end = (int)(word.size() - 1); word[start] == word[end] && start <= (int)(word.size() / 2); start++, end--) 
			if (start == end || start > end) cout << "Palindorm: " << word << endl;
	}
}
