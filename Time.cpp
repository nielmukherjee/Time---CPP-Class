#include "Time.h"  // class implemented
#include<iomanip>
using namespace std;

// File scope starts here 

/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

// Time Default + Overloaded Constructor
Time::Time(int aHour, int aMinute, int aSecond) : mHour(aHour), mMinute(aMinute), mSecond(aSecond) {
	if (aHour == -999 && aMinute == -999 && aSecond == -999)
		this->SetTime(Time::sGetDefaultTime());
	else
		this->SetTime(aHour, aMinute, aSecond);
}
// end Time constructor


//============================= OPERATORS ====================================

// Stream Insertion
ostream& operator<<(ostream& os, const Time& t) {
	os << setfill('0') << setw(2) << t.GetHour() << ":" << setw(2) << t.GetMinute() << ":" << setw(2) << t.GetSecond();
	return os;
}
// end stream insertion

// Stream Extraction
istream& operator >>(istream& is, Time& t) {
	int hh, mm, ss;
	cout << "Enter Hour: ";
	is >> hh;
	cout << "Enter Minute: ";
	is >> mm;
	cout << "Enter Second: ";
	is >> ss;
	t.SetTime(hh, mm, ss);

	return is;
}
// end stream extraction

// Assignment operator to swap time.
Time& Time::operator =(Time& rhs) {
	Time t = *this;
	this->SetTime(rhs.GetTime());
	
	rhs.SetTime(t.GetTime());

	return *this;
}
// Assignment operator

// pre-increment operator
Time& Time::operator ++() {
	if (this->GetHour() == 23) {
		this->SetHour(0);
	}
	else {
		++mHour;
	}

	return *this;
}
// pre-increment

// post-increment operator
Time Time::operator ++ (int) {
	Time t = *this;
	if (this->GetHour() == 23) {
		this->SetHour(0);
	}
	else {
		this->mHour++;
	}

	return t;
}
// end post-increment

//============================= OPERATIONS ===================================

// function that displays time in 24 hours format.
void Time::Display24()const {
	cout << setfill('0') << setw(2) << this->GetHour() << ":" << setw(2) << this->GetMinute() << ":" << setw(2) << this->GetSecond() << endl;
}
// end function Display24

// function that displays time in 12 hours format.
void Time::Display12()const {
	cout << setfill('0') << setw(2) << ((this->GetHour() == 0 || this->GetHour() == 12) ? 12 : this->GetHour() % 12) << ":" << setw(2) << this->GetMinute() << ":" << setw(2) << this->GetSecond() << " " << ((this->GetHour()<12) ? "AM" : "PM") << endl;
}
// end function Display12

// function that adds 'X' no. of minutes to the Time object
void Time::AddMinute(int x) {
	int tMin = this->GetMinute(), tHour = this->GetHour();
	tMin += x % 60;
	tHour += x / 60;

	if (tMin > 59) {
		tMin -= 60;
		tHour++;
	}

	this->SetMinute(tMin);
	this->SetHour(tHour);
}
// end function AddMinute



//============================= ACESS      ===================================

// function that sets hour
void Time::SetHour(int aHour) {
	if (aHour < 0 || aHour>23)
		this->mHour = 0;
	else
		this->mHour = aHour;
}
// end function SetHour

// function that sets minute
void Time::SetMinute(int aMinute) {
	if (aMinute < 0 || aMinute>59)
		this->mMinute = 0;
	else
		this->mMinute = aMinute;
}
// end function SetMinute

// function that sets second
void Time::SetSecond(int aSecond) {
	if (aSecond < 0 || aSecond>59)
		this->mSecond = 0;
	else 
		this->mSecond = aSecond;
}
// end function SetSecond

// function that sets the Time
void Time::SetTime(int aHour, int aMinute, int aSecond) {
	this->SetHour(aHour);
	this->SetMinute(aMinute);
	this->SetSecond(aSecond);
}
// end function SetTime

// function that sets the Time
void Time::SetTime(const Time &obj) {
	this->SetTime(obj.GetHour(), obj.GetMinute(), obj.GetSecond());
}
// end function SetTime

// static function that sets default time
void Time::sSetDefaultTime(int aHour, int aMinute, int aSecond) {
	if (aHour == -999 && aMinute == -999 && aSecond == -999)
		msDefaultTime.SetTime(Time::sGetCurrentTime());
	else
		msDefaultTime.SetTime(aHour, aMinute, aSecond);
}
// end function sSetDefaultTime

// function that gets hour
int Time::GetHour()const {
	return this->mHour;
}
// end function GetHour

// function that gets minute
int Time::GetMinute()const {
	return this->mMinute;
}
// end function GetMinute

// function that gets second
int Time::GetSecond()const {
	return this->mSecond;
}
// end function GetSecond

// function that gets the Time
const Time& Time::GetTime()const {
	return *this;
}
// end function GetTime

// static function that gets default date
const Time& Time::sGetDefaultTime() {
	return msDefaultTime;
}
// end function sGetDefaultTime

// static function that gets current time
Time  Time::sGetCurrentTime() {
	time_t currentTime = time(NULL);
	struct tm localTime;

	time(&currentTime);                   // Get the current time
	localtime_s(&localTime, &currentTime);  // Convert the current time to the local time

	int Hour1 = localTime.tm_hour;
	int Minute1 = localTime.tm_min;
	int Second1 = localTime.tm_sec;

	Time t(Hour1, Minute1, Second1);

	return t;
}
// end function sGetCurrentTime

/////////////////////////////// PRIVATE    ///////////////////////////////////

/*private static member cannot be accessed outside the class except for initialization*/
Time Time::msDefaultTime(Time::sGetCurrentTime().GetHour(), Time::sGetCurrentTime().GetMinute(), Time::sGetCurrentTime().GetSecond());		// intitalize class variable
