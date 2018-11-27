#ifndef Time_HEADER 
#define Time_HEADER

#include<iostream> 
#include<iomanip> 

using namespace std;

class Time {
	int hour, minute, second;
	static Time defaultTime;
public:
	Time(int = 0, int = 0, int = 0);
	int getHour()const;
	int getMinute()const;
	int getSecond()const;
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	void Display24()const;
	void Display12()const;
	void addMinute(int);
	static void setDefaultTime(int, int, int);

	Time& operator = (Time&);
	Time& operator ++ (); //pre-increment 
	Time operator ++ (int); //post-increment 

	friend ostream& operator <<(ostream&, const Time&);
};

#endif