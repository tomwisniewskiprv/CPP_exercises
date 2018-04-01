/*
CPP EXERCISES
A series of programming lab1_exs in C++ for the fourth semester of study.
Tomasz Wisniewski 2018.

Exercises 3 - Arrays
http://www.tomaszx.pl/materialy/JPOiG_lab3.pdf
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>     /* srand, rand */
#include <ctime>     
#include <stack>
using namespace std;

// Random number generator for range 0-100
int random(int range) {
	return rand() % range ;
}

bool vector_multiplication(int vector1[], int vector2[], int v1_size, int v2_size);
void fill_vector(int* &vector, int size);

// Exercise 1
void lab3_ex1() {

	// 1, 1, 2, 3, 5, 8, 13, 21, 34
	const int BUFF_SIZE = 100;
	unsigned long long* buffer = new unsigned long long[BUFF_SIZE];

	buffer[0] = buffer[1] = 1;

	for (int i = 2; i < BUFF_SIZE; i++)
		buffer[i] = buffer[i - 1] + buffer[i - 2];

	cout << "Exercise 1:\n";
	for (int i = 0; i < BUFF_SIZE; i++)
		cout << buffer[i] << " ";

	delete[] buffer;
}


// Exercise 2
void lab3_ex2() {

	int number = random(100);
	int rest = 0;
	int buffer = number;
	int power = 0;
	int tmp = 1;
	int i = 0;

	// dec2bin

	while (1) {
		tmp = static_cast<int>(pow(2, power));
		if (number >= tmp)
			power++;
		else break;
	}

	bool* binary = new bool[power];

	while (number) {
		rest = number % 2;
		number = number / 2;
		binary[i++] = rest;
	}

	cout << "Random number: " << buffer << endl;
	cout << "Bin:\t" ;
	for (int j = power - 1; j >= 0; j--)
		cout << binary[j] << " ";

	delete[] binary;

	// dec2hex
	number = buffer;
	stack<char> reverse;
	string sHex;
	string sValues = "0123456789ABCDEF";

	while (number) {
		reverse.push(sValues[number % 16]);
		sHex += sValues[number % 16];
		number /= 16;
	}

	sHex.clear();

	while (!reverse.empty()) {
		sHex += reverse.top();
		reverse.pop();
	}

	cout << "\nHex:\t" ;
	cout << sHex << endl;

}

// Exercise 3
void lab3_ex3() {

	const int VECTOR_SIZE = 4;

	int* vector1 = new int[VECTOR_SIZE];
	int* vector2 = new int[VECTOR_SIZE];

	for (int i = 0; i < VECTOR_SIZE; i++) {
		vector1[i] = 1;
		vector2[i] = 1;
	} 

	fill_vector(vector1, VECTOR_SIZE);
	fill_vector(vector2, VECTOR_SIZE);

	bool resutl = vector_multiplication(vector1, vector2, VECTOR_SIZE, VECTOR_SIZE);

	if (resutl) {
		for (int i = 0; i < VECTOR_SIZE; i++)
			cout << vector1[i] << " ";
	}
	else cout << "Multiplication failed." << endl;

	delete[] vector1;
	delete[] vector2;
}

// 
bool vector_multiplication(int vector1[], int vector2[], int v1_size, int v2_size) {

	if (v1_size == v2_size) {
		for (int i = 0; i < v1_size; i++) {
			vector1[i] *= vector2[i];
		}
		return 1;
	}
	else return 0;
}


// Fill vector with random numbers
void fill_vector(int* &vector, int size) {

	for (int i = 0; i < size; i++) {
		vector[i] = random(100);
	}
}


// Exercise 4
void lab3_ex4() {

	int rand = random(100);
	int guess = 0;

	cout << "Zgadnij liczbe:";
	do {
		cin >> guess;
		if (guess == rand) break;

		if (guess > rand)
			cout << "za duzo" << endl;
		else cout << "za malo" << endl;

	} while (1);

}


// Exercise 5
void lab3_ex5() {
	const int ASCII_size = 256;
	char tab_ASCII[ASCII_size];

	for (int i = 0; i < ASCII_size; i++) {
		tab_ASCII[i] = static_cast<char>(i);
		cout << i << " " << tab_ASCII[i] << endl;
	}

}
