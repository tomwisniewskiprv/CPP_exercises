/*
	CPP EXERCISES
	A series of programming exercises in C++ for the fourth semester of study.
	Tomasz Wisniewski 2018.

	Entry point.
*/
#include <iostream>
#include <climits>
#include <cstdlib>

#include "homework1.h"
#include "exercises1.h"
using namespace std;

//-----------------------------------------------------------------------
void menu() {

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
		else {
			break;
		}

	} while (1);

	switch (action) {
	case 1:
		list_homework1();
		break;
	case 2:
		list_exercises1();
		break;
		/*
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
		*/
	default:
		cout << "Wrong action." << endl;
		break;
	}


}


//-----------------------------------------------------------------------
int main() {
	cout << "~: C++ Exercises :~" << endl;

	menu();

	system("pause");
	return 0;
}