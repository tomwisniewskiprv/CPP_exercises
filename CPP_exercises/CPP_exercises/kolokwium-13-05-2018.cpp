#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <limits>

using namespace std;

// zadanie 1 
// tabliczka mnozenia
void zadanie1() {

	bool keepAsking = true;

	int x = 0 , y = 0; 
	while (keepAsking) {
		cout << "Podaj wymiar x: ";
		while (!(cin >> x)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "jeszcze raz: ";
		}
		cout << endl;
		cout << "Podaj wymiar y: ";
		while (!(cin >> y)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "jeszcze raz: ";
		}
		cout << endl;

		if ((x >= 2 && x <= 20) && (y >= 2 && y <= 20)) {
			keepAsking = false;
			break;
		}
		else {
			cout << "Podaj inne wymiary min 2x2 max 20x20" << endl;
		}
	}

	int ** tab = new int * [x];

	for (int i = 0; i < x; i++) {
		tab[i] = new int[y];
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			tab[i][j] = i * j;
			cout << bitset<12>(tab[i][j]) << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < x; i++) {
		delete[] tab[i];
	}
	delete[] tab;
}

// zadnie 2
// badanie ciagu
void zadanie2(int* tab, int elements) {

	int current = 0, next = 0;
	int count = 0;
	bool rosnacy = false;
	bool malejacy = false;

	for (int i = 0; i < elements - 1; i++) {
		if (tab[i] < tab[i + 1])
			rosnacy = true;
		else {
			rosnacy = false;
		}

		if (tab[i] > tab[i + 1])
			malejacy = true;
		else {
			malejacy = false;
		}
	}

	if (rosnacy == true && malejacy == false) {
		cout << "Ciag jest rosnacy" << endl;
	}
	else if (rosnacy == false && malejacy == true) {
		cout << "Ciag jest malejacy" << endl;
	}
	else {
		cout << "Ciag nie jest ani rosnacy ani malejacy" << endl;
	}

	for (int i = 0; i < elements; i++) {
		if (tab[i] % 2 == 0 && tab[i] > 9 && tab[i] < 100 && tab[i] % 3 == 0)
			count++;
	}

	cout << "Suma pierwszego i ostatniego elementu: " << tab[0] + tab[elements - 1] << endl;
	cout << "Liczba elementow parzystych , dwufycforowych , podzielnych przez 3 : " << count << endl;
}

// zadanie 3 
void emerytura(char nazwaPliku[]) {
	ifstream fin(nazwaPliku);
	ofstream foutM("mezczyzni.txt");
	ofstream foutK("kobiety.txt");

	vector <string> people;
	string tmp;
	if (fin) {
		while (getline(fin, tmp)) {
			people.push_back(tmp);
			tmp.clear();
		}
	}
	else {
		cout << "ERROR - input file does not exist";
	}
	fin.close();

	string buff;
	int subStr = 0;
	int wiek = 0;

	for (auto line : people) {

		subStr = line.find(' ', line.find(' ') + 1);
		buff = line.substr(subStr);

		if (string::npos == buff.find('M')) {
			subStr = buff.find(' ', 1);
			wiek = 60 - stoi(buff.substr(subStr));
			tmp = line + " LATA DO EMERYTURY " + to_string(wiek) + '\n';
			foutK << tmp;
		}
		else {
			subStr = buff.find(' ', 1);
			wiek = 65 - stoi(buff.substr(subStr));
			tmp = line + " LATA DO EMERYTURY " + to_string(wiek) + '\n';
			foutM << tmp;
		}
	}

	foutM.close();
	foutK.close();
}

int main(void) {

	// test
	int tabSize = 10;
	int tab[] = { 2 , 5 , 7 , 19 , 27 , 40 , 42 , 53 , 60 , 64 };

	// zadanie 1
	zadanie1();

	// zadanie 2
	zadanie2(tab, tabSize);

	// zadanie 3
	char file[] = "emeryci.txt";
	emerytura(file);

	system("pause");
	return 0;
}