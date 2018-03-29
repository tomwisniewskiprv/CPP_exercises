/*
	CPP EXERCISES
	A series of programming lab1_exs in C++ for the fourth semester of study.
	Tomasz Wisniewski 2018.

	Homework 1
*/
#include "homework1.h"
using namespace std;


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