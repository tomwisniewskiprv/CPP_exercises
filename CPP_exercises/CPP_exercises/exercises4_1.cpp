//-----------------------------------------------------------------------
// Strings and ciphers (basic ones at least)
//-----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// Exercise 2 - lab4 - GADERYPOLUKI
void lab4_ex2() {
	string keys[] = {
		"GA-DE-RY-PO-LU-KI-ga-de-ry-po-lu-ki",
		"PO-LI-TY-KA-RE-NU-po-li-ty-ka-re-nu",
		"KA-CE-MI-NU-TO-WY-ka-ce-mi-nu-to-wy"
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


/*
Przeczytaj od u¿ytkownika ci¹g tekstu zakoñczony znakiem kropki (.)
Nastêpnie podziel ten¿e tekst na s³owa i wszystkie d³u¿sze od 4
znaków zapisz do oddzielnej tablicy stringów.
Na koñcu wypisz na ekran napis z³o¿ony z 2 i 3 znaku ka¿dego elementu w tej nowej tablicy.
*/
void lab4_ex4() {

	//string input = "ABBCCDDDD.";
	string input = "A BB CCC DDDD.";
	string buff;
	int lenght = input.length();
	int position = 0, start = 0;
	bool found = false;

	do {
		position = input.find_first_of(' ', position);
		cout << position << endl;

		if (found) {

		}
		if (position >= 0) {
			buff = input.substr(start, position - start);
		}
		else {
			buff = input.substr(start);
		}

		cout << buff << endl;

		if (position + 1 < lenght) {
			start = ++position;
		}
	} while (position > 0);

}

void lab4_file1() {

	string line, buff;

	float f_avg = 0;
	float x_min, x, x_max, y;
	int counter = 0;
	bool first = true;

	ifstream fin;
	fin.open("input.txt");

	if (!fin.is_open()) {
		cout << "File Error!" << endl;
		exit(0);
	}

	vector <string> tab;
	vector <float> values;

	while (fin.good()) {
		getline(fin, line);
		tab.push_back(line);

		buff = line.substr(line.rfind('\t'));

		x = stof(buff);
		f_avg += stof(buff);

		if (first) {
			first = !first;
			x_min = x_max = x;
			values.push_back(x);
		}
		else {
			if (x < x_min) x_min = x;
			if (x > x_max) x_max = x;
			values.push_back(x);
		}

		cout << line << " " << "\tbuffer: " << buff << " | " << f_avg << endl;
		counter++;
	}
	fin.close();
	f_avg = f_avg / counter;

	cout << "---------" << endl;
	cout << "x_min: " << x_min << " x_max: " << x_max << endl;
	cout << "---------" << endl;

	ofstream fout;
	fout.open("output.txt");

	for (int i = 0; i < tab.size(); i++) {
		x = values[i];
		y = (x - x_min) / (x_max - x_min);
		buff = tab[i] + "\t" + to_string(y) + "\n";
		cout << buff;
		fout << buff;
	}
	fout.close();
	cout << "---------" << endl;

}
