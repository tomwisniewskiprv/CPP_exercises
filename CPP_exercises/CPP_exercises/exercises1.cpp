/*
	CPP EXERCISES
	A series of programming lab1_exs in C++ for the fourth semester of study.
	Tomasz Wisniewski 2018.

	Exercises 1 - Exercises from first class:
	http://www.tomaszx.pl/materialy/JPOiG_lab1_skr.pdf
*/
#include "exercises1.h"
using namespace std;
#define _USE_MATH_DEFINES


//-----------------------------------------------------------------------
void lab1_ex3_4() {
	// lab1_ex3_5 to liczby od najmniejszej do najwiêkszej np 1 5 9

	cout << "Podaj liczby: ";
	int x, y, z;

	cin >> x >> y >> z;
	int result = (x % y % z);

	cout << result;
}

//-----------------------------------------------------------------------
void lab1_ex3_6() {
	int i = 0x100;
	cout << setw(4) << i << ' ' << bitset<32>(i) << endl;
	i = i >> 2;
	cout << setw(4) << i << ' ' << bitset<32>(i) << endl;
	i = i << 4;
	cout << setw(4) << i << ' ' << bitset<32>(i) << endl;
}

//-----------------------------------------------------------------------
void lab1_ex5_1() {

	float h, a;
	do {
		cin.clear();
		cin.sync();
		cout << "Height: ";
		cin >> h;
		h *= 100;
	} while (!cin.good());

	do {
		cin.clear();
		cin.sync();
		cout << "Base: ";
		cin >> a;
		a *= 100;
	} while (!cin.good());

	float P = (a * h) / 2;
	cout << "Surface area: " << P << endl;

}

//-----------------------------------------------------------------------
void lab1_ex5_2() {

	float radius, a, square;
	const float PI = 3.141592f;
	cout << "Enter radius: ";
	cin >> radius;
	float P = PI * powf(radius, 2);
	a = 2 * radius;
	square = a * a;

	cout << "Surface area: " << P << endl
		<< "Square side : " << a << endl
		<< "Square area : " << square << endl;

	system("pause");
}

//-----------------------------------------------------------------------
void lab1_ex7_5() {
	float hours;
	float rate;

	do {
		cout << "How many hours ? :";
		cin >> hours;
		cout << "Rate ? :";
		cin >> rate;

		if (cin.fail()) {
			cin.clear();	
			cin.sync();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		}
		else {
			break;
		}
	} while (1);

	cout << "Daily gain: " << rate * 8 << endl;
	cout << "Total gain: " << rate * hours << endl;
}
//-----------------------------------------------------------------------
void lab1_ex8_7() {
	int calories = 1500;
	int trainings = 0;
	int weeks = 0;

	cout << "Trainings per week : ";
	cin >> trainings;
	cout << "Weeks of trainings : ";
	cin >> weeks;

	long result = trainings * weeks * 1500;
	cout << "Calories           : " << result << " kcal" << endl;

}

//-----------------------------------------------------------------------
void lab1_ex9_1() {

	long A, B, C;
	long buff[3];

	for (int i = 0; i < 3; i++) {
		do {
			cin.clear();
			cin.sync();
			cout << "Give the coefficient " << char('A' + i) << " : ";
			cin >> buff[i];
		} while (!cin.good());
	}

	A = buff[0];
	B = buff[1];
	C = buff[2];

	cout << A << ' ' << B << ' ' << C << endl;

	float delta = (B*B) - (4 * A*C);
	float x1, x2;
	int roots;

	if (A != 0) {
		if (delta > 0) {
			roots = 2;
		}
		else if (delta == 0.0) {
			roots = 1;
		}
		else {
			roots = 0;
		}
	}
	else {
		cout << "Division by 0. Exiting.";
	}

	switch (roots) {
	case 2:
		x1 = (-B - sqrt(delta)) / (2 * A);
		x2 = (-B + sqrt(delta)) / (2 * A);
		cout << "delta: " << delta << endl;
		cout << "Roots: " << x1 << ' ' << x2 << endl;
		break;
	case 1:
		x1 = -B / (2 * A);
		cout << "delta: " << delta << endl;
		cout << "Root : " << x1 << endl;
		break;
	case 0:
		cout << "There are no roots. " << endl;
		break;
	default:
		break;
	}
}

//-----------------------------------------------------------------------
void lab1_ex11_1() {

	long long natural, max, min, sum = 0, counter = 0;
	double avg = 0;
	bool is_first = true;

	do {
		cin.clear();
		cin.sync();
		cout << "Enter natural number : ";
		cin >> natural;

		if (is_first) {
			is_first = !is_first;
			max = min = natural;
		}

		if (cin.fail())
			cout << "Not a number!" << endl;
		else if (natural != 0) {
			counter++;
			sum += natural;

			if (max < natural)
				max = natural;
			if (natural < min)
				min = natural;
		}
	} while (natural != 0);

	avg = sum / counter;
	cout << "Min: " << min << endl
		<< "Max: " << max << endl
		<< "AVG: " << avg << endl;

}

//-----------------------------------------------------------------------
void lab1_ex11_2() {
	// brute force method for finding Prime numbers.
	// #TODO
	int max = 100;
	int primes[100];
	int counter = 0;
	int n = 2;
	for (int i = 2; ; i++)
		if (n != (n / i) * i) {

		}
}

//-----------------------------------------------------------------------
void lab1_ex11_3() {

	for (int i = 31; i < 52; i++) {
		if (i % 2 == 0)
			cout << i << ' ';
	}
}

//-----------------------------------------------------------------------
void lab1_ex11_4() {

	for (int i = 0; i < 101; i++) {
		if (i % 4 == 0 && i % 8 != 0 && i % 10 != 0)
			cout << i << ' ';
	}
}

//-----------------------------------------------------------------------
void lab1_ex11_5() {

	int years = 0;
	const float income = 12000;
	float savings = 0;
	float interest = 0.05f;
	const float goal = 200000;

	while (savings < goal) {
		savings = (savings*interest) + savings + income;
		years++;
		cout << "Years  : " << years << endl
			<< "Savings: " << savings << ' ' << endl;
	}
}

//-----------------------------------------------------------------------
void lab1_ex11_6() {

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			cout << setw(4) << i * j;
		}
		cout << endl;
	}
}

//-----------------------------------------------------------------------
