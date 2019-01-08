/**
* @file Task3_main.cpp
*
* @brief This code implements inheritance and type conversion.
*
* @author Saif Ullah Ijaz
*
*/

// SYSTEM INCLUDES
#include <iostream> 
using namespace std;

// LOCAL INCLUDES
#include "Alarm.h"



// function main begins program execution
void main() {
	Time t1(8, 20, 10);
	cout << t1 << endl << endl;

	Alarm a1;
	a1 = (Alarm)t1;	// Type conversion: from Time to Alarm
	a1[3];
	a1.SetAlarmType("Melody+Vibration");
	a1.DisplayAlarm();
	cout << endl;

	Alarm a2;
	cin >> a2;
	a2.DisplayAlarm();
	cout << endl;

	cout << (Time)a2 << endl;		// Type conversion: from Alarm to Time



	system("pause");
}
// end main
