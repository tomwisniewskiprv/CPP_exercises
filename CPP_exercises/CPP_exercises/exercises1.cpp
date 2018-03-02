/*
	CPP EXERCISES
	A series of programming exercises in C++ for the fourth semester of study.
	Tomasz Wisniewski 2018.

	Exercises 1 - Exercises from first class:
	http://www.tomaszx.pl/materialy/JPOiG_lab1_skr.pdf
*/
#include "exercises1.h"
using namespace std;
#define _USE_MATH_DEFINES

//-----------------------------------------------------------------------
void list_exercises1() {

	string options[] = { "3.4", "3.6","5.1","5.2", "7.5","8.7","9.1","11.1","11.2","11.3","11.4","11.5","11.6" };
	cout << "Homework 1:" << endl;
	int option = 0;

	cout.setf(ios::left);
	for (string str : options) {
		cout << setw(3) << ++option << "| " << str << endl;
	}

	int action = 0;
	do {
		cout << setw(3) << ">";
		cin >> action;

		if (cin.fail() || action > option || action < 1) {
			cin.clear();	// clear failbit , eofbit
			cin.sync();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // !important for Visual Studio compiler...
		}
		else {
			break;
		}

	} while (1);

	execute_exercise1(action);

}

//-----------------------------------------------------------------------
void exercise3_4() {
	// exercise3_5 to liczby od najmniejszej do najwiêkszej np 1 5 9

	cout << "Podaj liczby: ";
	int x, y, z;

	cin >> x >> y >> z;
	int result = (x % y % z);

	cout << result;
}

//-----------------------------------------------------------------------
void exercise3_6() {
	int i = 0x100;
	cout << setw(4) << i << ' ' << bitset<32>(i) << endl;
	i = i >> 2;
	cout << setw(4) << i << ' ' << bitset<32>(i) << endl;
	i = i << 4;
	cout << setw(4) << i << ' ' << bitset<32>(i) << endl;
}

//-----------------------------------------------------------------------
void exercise5_1() {

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
void exercise5_2() {

	float radius, a, square;
	const float PI = 3.141592;
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
void exercise7_5() {
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
void exercise8_7() {
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
void exercise9_1() {

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
void exercise11_1() {

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
void exercise11_2() {
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
void exercise11_3() {

	for (int i = 31; i < 52; i++) {
		if (i % 2 == 0)
			cout << i << ' ';
	}
}

//-----------------------------------------------------------------------
void exercise11_4() {

	for (int i = 0; i < 101; i++) {
		if (i % 4 == 0 && i % 8 != 0 && i % 10 != 0)
			cout << i << ' ';
	}
}

//-----------------------------------------------------------------------
void exercise11_5() {

	int years = 0;
	const float income = 12000;
	float savings = 0;
	float interest = 0.05;
	const float goal = 200000;

	while (savings < goal) {
		savings = (savings*interest) + savings + income;
		years++;
		cout << "Years  : " << years << endl
			<< "Savings: " << savings << ' ' << endl;
	}
}

//-----------------------------------------------------------------------
void exercise11_6() {

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			cout << setw(4) << i * j;
		}
		cout << endl;
	}
}

//-----------------------------------------------------------------------
void execute_exercise1(int arg) {

	switch (arg) {

	case 1:
		exercise3_4();
		break;

	case 2:
		exercise3_6();
		break;

	case 3:
		exercise5_1();
		break;

	case 4:
		exercise5_2();
		break;

	case 5:
		exercise7_5();
		break;

	case 6:
		exercise8_7();
		break;

	case 7:
		exercise9_1();
		break;

	case 8:
		exercise11_1();
		break;

	case 9:
		exercise11_2();
		break;

	case 10:
		exercise11_3();
		break;

	case 11:
		exercise11_4();
		break;

	case 12:
		exercise11_5();
		break;

	case 13:
		exercise11_6();
		break;

	default:
		cout << "\nUnknown exercise" << endl;
		list_exercises1();
		break;
	}
}

