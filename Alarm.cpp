#include "Alarm.h"  // class implemented
#include<string>
using namespace std;

// File scope starts here 

/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

// Alarm Default+Overloaded Constructor
Alarm::Alarm(int aHour, int aMinute, int aSecond, int aVolume, const string& aRing) : Time(aHour, aMinute, aSecond), mVolume(aVolume) {
	this->SetAlarm(aVolume, aRing);
}
// end Alarm constructor 

// Alarm Type conversion Constructor
Alarm::Alarm(const Time& aTime) : Time(aTime), mVolume(0), mAlarmType(None) { }
// end Alarm constructor 


//============================= OPERATORS ====================================

// Stream Extraction
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
	a.SetHour(hr);
	a.SetMinute(min);
	a.SetSecond(sec);

	cout << "Enter Volume level(0-5): ";
	is >> vLevel;
	a.SetVolume(vLevel);
	cout << "Enter ring tone: ";
	cin.ignore();
	getline(cin, ringTone);
	a.SetAlarmType(ringTone);

	return is;
}
// end stream extraction

// subscript operator to set volume in valid range (0-5).
void Alarm::operator[](int aVolume)
{
	this->SetVolume(aVolume);
}
// end subscript operator

// Function-operator for type conversion.
Alarm::operator Time() {
	return this->GetTime();
}
// end function-operator

//============================= OPERATIONS ===================================
// function that displays alarm
void Alarm::DisplayAlarm()const
{
	cout << "Alarm Time: ";
	this->Display24();
	cout << "Volume level: " << this->GetVolume() << endl;
	cout << "Ringtone: ";
	cout << this->GetAlarmType() << endl;
}
// end function DisplayAlarm


//============================= ACESS      ===================================

// function that sets volume of Alarm
void Alarm::SetVolume(int aVolume) {
	if (aVolume > 5) {
		cout << "Voume out of maximum range: Setting it to 5." << endl;
		this->mVolume = 5;
	}
	else if (aVolume < 0) {
		cout << "Voume below minimum range: Setting it to 0." << endl;
		this->mVolume = 0;
	}
	else
		this->mVolume = aVolume;
}
// end function SetVolume

// function that sets alarm type
void Alarm::SetAlarmType(const string& aAlarmType) {
	if (aAlarmType == "Melody")
		this->mAlarmType = Melody;
	else if (aAlarmType == "Vibration")
		this->mAlarmType = Vibration;
	else if (aAlarmType == "Melody+Vibration")
		this->mAlarmType = MelodyAndVibration;
	else
		this->mAlarmType = None;
}
// end function SetAlarmType

// function that sets Alarm
void Alarm::SetAlarm(int aHour, int aMinute, int aSecond, int aVolume, const string& aRing) {
	this->SetTime(aHour, aMinute, aSecond);
	this->SetAlarm(aVolume, aRing);
}
// end function SetAlarm

// overloaded function that sets the Alarm
void Alarm::SetAlarm(int aVolume, const string& aRing){
	this->SetVolume(aVolume);
	this->SetAlarmType(aRing);
}
// end function SetAlarm

// overloaded function that sets the Alarm
void Alarm::SetAlarm(const Alarm& aAlarm) {
	this->SetTime(aAlarm.GetTime());
	this->SetAlarm(aAlarm.GetVolume(), aAlarm.GetAlarmType());
}
// end function SetAlarm

// function that gets volume of Alarm
int Alarm::GetVolume()const {
	return this->mVolume;
}
// end function GetVolume

// function that gets alarm type
const string Alarm::GetAlarmType()const {
	if (this->mAlarmType == Melody)
		return "Melody";
	else if (this->mAlarmType == Vibration)
		return "Vibration";
	else if (this->mAlarmType == MelodyAndVibration)
		return "MelodyAndVibration";
	else
		return "None";
}
// end function GetAlarmType

// function that gets the Alarm
const Alarm& Alarm::GetAlarm()const {
	return *this;
}
// end function GetAlarm
