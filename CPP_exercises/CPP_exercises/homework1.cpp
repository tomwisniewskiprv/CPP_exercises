/*
	CPP EXERCISES
	A series of programming exercises in C++ for the fourth semester of study.
	Tomasz Wisniewski 2018.

	Homework 1
*/
#include "homework1.h"
using namespace std;

//-----------------------------------------------------------------------
void list_homework1() {

	// KISS DRY ... I know I know ... it will be fixed #TODO

	string options[] = { "Greatest Common Divisor" , "Factorial" , "Calculator #TODO" };
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

	execute_homework1(action);
}

void execute_homework1(int arg) {
	switch (arg) {

	case 1:
		GCD();
		break;

	case 2:
		_factorial();
		break;

	case 3:
		calc();
		break;

	default:
		cout << "\nUnknown exercise" << endl;
		list_homework1();
		break;
	}
}

//-----------------------------------------------------------------------
// Euclidean algorithm - the greatest common divisor - wrapper 
void GCD() {

	long n, m, n1, m1;
	cout << "Euclidean algorithm:" << endl;
	cout << "WARNING! There is no type check!" << endl;
	cout << "Type two integers separated with space : ";
	cin >> n >> m;

	// save variables for later
	n1 = n;
	m1 = m;

	while (n > 0 && m > 0) {
		if (m > n) {
			m = m % n;
			cout << m << endl;
		}
		else {
			n = n % m;
			cout << n << endl;
		}
	}
	long result = n + m;

	cout << "NWD(" << n1 << "," << m1 << ") = " << result << endl;
}

//-----------------------------------------------------------------------
// Factorial - this is just a wrapper because factorial func. is recursive.
void _factorial() {
	cout << "Factorial." << endl;
	cout << "WARNING! There is no type check!" << endl;
	cout << "Type a number please :";

	long input;
	cin >> input;
	
	cout << "Result : " << factorial(input) << endl;
}
//-----------------------------------------------------------------------
// Factorial (silnia)
long factorial(long x) {

	if (x == 1)
		return 1;
	return x * factorial(x - 1);
}

//-----------------------------------------------------------------------
// Calculator
void calc() {
	cout << "Calculator #TODO" << endl;

}