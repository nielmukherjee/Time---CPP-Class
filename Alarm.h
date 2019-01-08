/**  Alarm class inherited from Time class.
*
* #include "Alarm.h" <BR>
* -llib
*
*/
#ifndef ALARM_H
#define ALARM_H

// SYSTEM INCLUDES
#include<iostream>
using std::string;

// LOCAL INCLUDES
#include "Time.h"

// define enumeration
enum validRing { Melody, Vibration, MelodyAndVibration, None };

// Alarm class definition
class Alarm : public Time {
public:
// LIFECYCLE
	/** Default + Overloaded constructor.
	*/
	Alarm(int = 0, int = 0, int = 0, int = 0, const string& = "");

	/** Type conversion constructor.
	*/
	Alarm(const Time&);

	// Use compiler-generated copy constructor, assignment, and destructor.
	// Alarm(const Alarm&);
	// Alarm& operator=(const Alarm&);
	// ~Alarm();

// OPERATORS
	/** Stream Extraction operator.
	*
	* @param is Standard Intput Stream.
	* @param to The value to be extracted from the input stream.
	*
	* @return A reference to the standard input stream.
	*/
	friend std::istream& operator >>(std::istream& is, Alarm& to);

	/** subscript operator to set volume in valid range (0-5).
	*
	* @param aVolume to be set.
	*
	* @return void.
	*/
	void operator [](int aVolume);

	/** Function-operator for type conversion.
	*
	* @param void.
	*
	* @return void.
	*/
	operator Time();


// OPERATIONS
	/** function that displays alarm.
	*
	* @param void
	*
	* @return void
	*/
	void DisplayAlarm()const;


// ACCESS
	// setters
	void SetVolume(int = 0);
	void SetAlarmType(const string&  = "");
	void SetAlarm(int = 0, int = 0, int = 0, int = 0, const string& = "");
	/**
	# @overload void SetAlarm(int = 0, const string& = "");
	*/
	void SetAlarm(int = 0, const string& = "");
	/**
	# @overload void SetAlarm(const Alarm& aAlarm);
	*/
	void SetAlarm(const Alarm& aAlarm);

	// getters
	int GetVolume()const;
	const string GetAlarmType()const;
	const Alarm& GetAlarm()const;

private:

// DATA MEMBERS
	int mVolume;
	validRing mAlarmType;
};
// end class Alarm
#endif  
// _ALARM_H_
