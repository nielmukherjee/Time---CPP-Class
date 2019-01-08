/**
* @file Task2_main.cpp
*
* @brief This code implements operator overloading.
*
* @author Saif Ullah Ijaz
*
*/

// SYSTEM INCLUDES
#include <iostream> 
using namespace std;

// LOCAL INCLUDES
#include "time.h"



// function main begins program execution
void main() {
	Time t1(8, 20, 10), t2(3, 40, 34);
	cout << "Before Interchanging:" << endl;
	cout << "Time 1: " << t1 << endl << "Time 2: " << t2 << endl << endl;

	t1 = t2;
	cout << "After Interchanging:" << endl;
	cout << "Time 1: " << t1 << endl << "Time 2: " << t2 << endl << endl;

	cout << "Pre-incrmenting Time 1 (++t1): " << ++t1 << endl;
	cout << "Post-incrmenting Time 2 (t2++): " << t2++ << endl << endl;

	cout << "After Incrementing:" << endl;
	cout << "Time 1: " << t1 << endl << "Time 2: " << t2 << endl << endl;


	system("pause");
}
// end main
