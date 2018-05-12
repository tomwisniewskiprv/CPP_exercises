/*
	CPP EXERCISES
	A series of programming lab1_exs in C++ for the fourth semester of study.
	Tomasz Wisniewski 2018.

	Program entry point.

*/
#include <iostream>
#include <climits>
#include <cstdlib>

#include "homework1.h"
#include "exercises1.h"
#include "exercises3.h"
#include "exercises4.h"
#include "exercises4_1.h"
#include "exercises6_1_gr2.h"
using namespace std;

//-----------------------------------------------------------------------
// Notes about how to handle cin errors
//-----------------------------------------------------------------------
void cin_input_demo() {

	string options[] = { "Homework 1" , "Exercises 1" };
	cout << "Menu:" << endl;
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
		else 
			break;

	} while (1);

}


//-----------------------------------------------------------------------
// Program entry point
//-----------------------------------------------------------------------
int main() {

	srand(time(NULL));
	cout << "~: C++ Exercises :~" << endl;

	lab4_ex4();

	system("pause");
	return 0;
}