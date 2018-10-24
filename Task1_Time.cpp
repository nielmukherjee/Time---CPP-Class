#include<iostream> 
#include<iomanip> 

using namespace std;

class Time {
	int hour, minute, second;
	static Time defaultTime;
public:
	Time(int, int, int);
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
};

Time Time::defaultTime(0, 0, 0);

Time::Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {
	if (h < 0 || h>23 || h == 0)
		setHour(defaultTime.getHour());
	if (m < 0 || m>59 || m == 0)
		setMinute(defaultTime.getMinute());
	if (s < 0 || s>59 || s == 0)
		setSecond(defaultTime.getSecond());
}

int Time::getHour()const {
	return hour;
}

int Time::getMinute()const {
	return minute;
}

int Time::getSecond()const {
	return second;
}

void Time::setHour(int h) {
	if (h < 0 || h>23)
		hour = 0;
	else
		hour = h;
}

void Time::setMinute(int m) {
	if (m < 0 || m>59)
		minute = 0;
	else
		minute = m;
}

void Time::setSecond(int s) {
	if (s < 0 || s>59)
		second = 0;
	else second = s;
}

void Time::Display24()const {
	cout << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond() << endl;
}

void Time::Display12()const {
	cout << setfill('0') << setw(2) << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond() << " " << ((getHour()<12) ? "AM" : "PM") << endl;
}

void Time::addMinute(int m) {
	int tMin = getMinute(), tHour = getHour();
	tMin += m % 60;
	tHour += m / 60;

	if (tMin > 59) {
		tMin -= 60;
		tHour++;
	}

	setMinute(tMin);
	setHour(tHour);
}

void Time::setDefaultTime(int h, int m, int s) {
	if (h < 0 || h>23)
		defaultTime.setHour(0);
	else
		defaultTime.setHour(h);
	if (m < 0 || m>59)
		defaultTime.setMinute(0);
	else
		defaultTime.setMinute(m);
	if (s < 0 || s>59)
		defaultTime.setSecond(0);
	else
		defaultTime.setSecond(s);
}

void main() {
	Time::setDefaultTime(15, 45, 0);
	Time t[4] = { Time(12,30),Time(14,50),Time(24,12) };

	t[0].Display24();
	t[0].Display12();
	cout << "Adding 15 minutes" << endl;
	t[0].addMinute(15);
	t[0].Display24();
	t[0].Display12();

	t[1].Display24();
	t[1].Display12();
	cout << "Adding 20 minutes" << endl;
	t[1].addMinute(20);
	t[1].Display24();
	t[1].Display12();

	t[2].Display24();
	t[2].Display12();
	cout << "Adding 2 minutes" << endl;
	t[2].addMinute(2);
	t[2].Display24();
	t[2].Display12();

	t[3].Display24();
	t[3].Display12();

	system("pause");
}