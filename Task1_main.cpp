#include<iostream>
#include<iomanip> 
#include "Time.h"

using namespace std;


void main() {
	Time::setDefaultTime(15, 45, 0);
	Time t[4] = { Time(12,30),Time(14,50),Time(24,12) };

	t[0].Display24();
	t[0].Display12();
	cout << "Adding 15 minutes" << endl;
	t[0].addMinute(15);
	t[0].Display24();
	t[0].Display12();
	cout << endl;

	t[1].Display24();
	t[1].Display12();
	cout << "Adding 20 minutes" << endl;
	t[1].addMinute(20);
	t[1].Display24();
	t[1].Display12();
	cout << endl;

	t[2].Display24();
	t[2].Display12();
	cout << "Adding 2 minutes" << endl;
	t[2].addMinute(2);
	t[2].Display24();
	t[2].Display12();
	cout << endl;
	
	t[3].Display24();
	t[3].Display12();

	system("pause");
}