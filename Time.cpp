#include "Time.h"

Time Time::defaultTime(0, 0, 0);

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {
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

Time& Time::operator=(Time& rhs) {
	Time t = *this;
	hour = rhs.hour;
	minute = rhs.minute;
	second = rhs.second;
	rhs.hour = t.hour;
	rhs.minute = t.minute;
	rhs.second = t.second;

	return *this;
}

//pre-increment 
Time& Time::operator ++ () {
	if (hour == 23) {
		hour = 0;
	}
	else {
		++hour;
	}

	return *this;
}

// post-increment 
Time Time::operator ++ (int) {
	Time t = *this;
	if (hour == 23) {
		hour = 0;
	}
	else {
		++hour;
	}

	return t;
}

ostream& operator <<(ostream& os, const Time& t) {
	os << setfill('0') << setw(2) << t.hour;
	os << ":";
	os << setfill('0') << setw(2) << t.minute;
	os << ":";
	os << setfill('0') << setw(2) << t.second;

	return os;
}