#include<iostream>
#include<iomanip> 
#include "Time.h"

using namespace std;


void main() {
	Time t1(2, 34, 56), t2(23, 01, 60);
	cout << "Before Interchanging:" << endl;
	cout << "Time 1: " << t1 << endl << "Time 2: " << t2 << endl << endl;

	t1 = t2;
	cout << "After Interchanging:" << endl;
	cout << "Time 1: " << t1 << endl << "Time 2: " << t2 << endl << endl;

	cout << "Pre-incrmenting Time 1 (++t1): " << ++t1 << endl;
	cout << "Post-incrmenting Time 2 (t2++): " << t2++ << endl << endl;

	cout << "After Incrementing:" << endl;
	cout << "Time 1: " << t1 << endl << "Time 2: " << t2 << endl << endl;

	system("PAUSE");
}