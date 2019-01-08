/**
* @file Task1_main.cpp
*
* @brief This code implements creates array of Time objects
* and add minutes seperately.
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

	Time::sSetDefaultTime(15, 45, 0);
	Time t[4] = { Time(12,30),Time(14,50),Time(23,59) };

	t[0].Display24();
	t[0].Display12();
	cout << "Adding 15 minutes" << endl;
	t[0].AddMinute(15);
	t[0].Display24();
	t[0].Display12();
	cout << endl;

	t[1].Display24();
	t[1].Display12();
	cout << "Adding 20 minutes" << endl;
	t[1].AddMinute(20);
	t[1].Display24();
	t[1].Display12();
	cout << endl;

	t[2].Display24();
	t[2].Display12();
	cout << "Adding 2 minutes" << endl;
	t[2].AddMinute(2);
	t[2].Display24();
	t[2].Display12();
	cout << endl;

	t[3].Display24();
	t[3].Display12();


	system("pause");
}
// end main
