#include<iostream>
#include "Alarm.h"


void main() {
	Time t1(8, 20, 10);
	cout << t1 << endl << endl;

	Alarm a1;
	a1 = (Alarm) t1;	// Type conversion: from Time to Alarm
	a1[3];
	a1.setRing("Melody+Vibration");
	a1.displayAlarm();
	cout << endl;

	Alarm a2;
	cin >> a2;
	a2.displayAlarm();
	cout << endl;

	cout << (Time)a2<<endl;		// Type conversion: from Alarm to Time

	system("PAUSE");

}