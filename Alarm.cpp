#include "Alarm.h"
#include <string>
#include<iostream>

using namespace std;

std::ostream& operator<<(std::ostream& os, const validRing& validRings)
{
	switch (validRings)
	{
	case Melody: os << "Melody"; break;
	case Vibration: os << "Vibration"; break;
	case MelodyAndVibration: os << "MelodyAndVibration"; break;
	case None: os << "None"; break;
	}
	return os;
}

istream& operator >>(istream& is, Alarm& a)
{
	int hr, min, sec, vLevel;
	string ringTone;
	cout << "Setting Alarm" << endl;
	cout << "Enter hour: ";
	is >> hr;
	cout << "Enter minute: ";
	is >> min;
	cout << "Enter second: ";
	is >> sec;
	a.setHour(hr);
	a.setMinute(min);
	a.setSecond(sec);

	cout << "Enter Volume level(0-5): ";
	is >> vLevel;
	a.setVolume(vLevel);
	cout << "Enter ring tone: ";
	cin.ignore();
	getline(cin, ringTone);
	a.setRing(ringTone);

	return is;
}


Alarm::Alarm(int aHour, int aMinute, int aSecond, int aVolume, string aRing) :Time(aHour, aMinute, aSecond)
{
	setRing(aRing);
	setVolume(aVolume);
}

// Type conversion constructor
Alarm::Alarm(const Time & t) :Time(t)
{
	setVolume(0);
	setRing("None");
}
void Alarm::displayAlarm()const
{
	cout << "Alarm Time: " << getHour() << ":" << getMinute() << ":" << getSecond() << endl;
	cout << "Volume level: " << Volume << endl;
	cout << "Ringtone: ";
	cout << AlarmType << endl;
}
void Alarm::setVolume(int aVolume)
{
	if (aVolume > 5)
		Volume = 5;
	else if (aVolume < 0)
		Volume = 0;
	else
		Volume = aVolume;
}

void Alarm::operator[](int aVolume)
{
	if (aVolume > 5)
		Volume = 5;
	else if (aVolume < 0)
		Volume = 0;
	else
		Volume = aVolume;
}
void Alarm::setRing( string alarmType)
{
	if (alarmType == "Melody")
		AlarmType = Melody;
	else if (alarmType == "Vibration")
		AlarmType = Vibration;
	else if (alarmType == "Melody+Vibration")
		AlarmType = MelodyAndVibration;
	else
		AlarmType = None;


}


Alarm::operator Time() {
	return Time();
}
