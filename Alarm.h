#ifndef Alarm_HEADER 
#define Alarm_HEADER

#include"Time.h"

enum validRing { Melody, Vibration, MelodyAndVibration, None };

class Alarm :public Time
{
	int Volume;
	validRing AlarmType;
public:
	friend istream& operator >>(istream&, Alarm&);
	Alarm(int = 0, int = 0, int = 0, int = 0, string = "");
	Alarm(const Time &);		// contructor for type conversion
	void displayAlarm()const;
	void setVolume(int);
	void setRing(string);

	void operator[](int);
	operator Time();

};


#endif