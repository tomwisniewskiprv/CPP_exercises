#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

vector<string> lines;

// wczytuje plik tekstowy linia po lini i umiesza go
// w globalnym wektorze lines
void loadFile(string fileName) {
	lines.clear();

	ifstream file(fileName);
	string tempLine;

	if (file) {
		while (file.good()) {
			getline(file, tempLine);
			lines.push_back(tempLine);
			tempLine.clear();
		}
	}
	else {
		cout << "Error with file input.";
	}

	file.close();
}

// zadania z haslami
// parzyste , nie parzyste
void odp1() {

	ofstream fout("odpowiedz1.txt");

	int odd = 0, even = 0;

	for (auto line : lines) {
		if (line.size() % 2 == 0)
			even++;
		else odd++;
	}

	fout << "Even: " << even << endl;
	fout << "Odd : " << odd << endl;
	fout << "Sum : " << even + odd << endl;

	fout.close();
}

// zadania z haslami
// palindrom
void odp2() {

	ofstream fout("odpowiedz2.txt");
	int counter = 0;

	for (auto line : lines) {
		for (size_t front = 0, back = line.size() - 1; line[front] == line[back] && front <= (line.size() / 2); front++, back--)
			if (front == back || front > back) {
				cout << "Palindrom: " << line << endl;
				fout << line << endl;
			}
	}

	fout.close();
}

// zadania z haslami
// string2bin
void odp3_4() {

	ofstream fout("odpowiedz3.txt");
	ofstream fout4("odpowiedz4.txt");

	vector <string> v220;

	string max, min;
	int iMax = 0, iMin = 0;
	bool first = true;

	for (auto line : lines) {

		if (first) {
			first = false;
			iMax = iMin = line.size();
			max = min = line;
		}

		if (iMax < line.size()) {
			iMax = line.size();
			max = line;
		}
		if (iMin > line.size()) {
			iMin = line.size();
			min = line;
		}

		for (int i = 0; i < line.size() - 1 - 1; i++) {
			if ((char)line[i] + (char)line[i + 1] == 220) {
				v220.push_back(line);
			}
		}
	}

	for (auto line : v220) {
		fout << line << endl;
	}

	fout.close();
	fout4 << "MAX:\t" << iMax << "\t" << max << endl;
	fout4 << "MIN:\t" << iMin << "\t" << min << endl;
	fout4.close();

}

// zadania z liczbami
void liczby1() {

	long number = 0, odd = 0, even = 0;
	long min, max;
	bool first = true;
	string largestNumber;

	vector <string> v9;

	for (auto bin : lines) {
		if (bin.size() > 0)
			number = stoi(bin, nullptr, 2);

		if (bin.size() == 9)
			v9.push_back(bin);

		if (first) {
			first = false;
			min = max = number;
		}

		if (number > max) {
			max = number;
			largestNumber = bin;
		}

		if (number % 2 == 0)
			even++;
		else odd++;

	}

	ofstream fout("liczby1.txt");
	fout << "Liczby parzyste: " << even << endl;
	fout.close();

	fout.open("liczby2.txt");
	fout << "Najwiêksza liczba : " << max << " " << largestNumber;
	fout.close();

	fout.open("liczby3.txt");
	number = 0;
	for (auto bin : v9) {
		number += stoi(bin, nullptr, 2);
	}

	bitset<32> binary(number);

	fout << "Suma liczb :" << number << " " << binary;
	fout.close();

}

void exercises7() {

	loadFile("hasla.txt");
	odp1();
	odp2();
	odp3_4();

	loadFile("liczby.txt");
	liczby1();

}