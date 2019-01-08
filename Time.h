/**  Time class to handle time in a C++ code.
*
* #include "Time.h" <BR>
* -llib
*
*/
#ifndef TIME_H
#define TIME_H

// SYSTEM INCLUDES
#include<iostream>
#include <ctime>


// Time class definition
class Time {
public:
// LIFECYCLE
	/** Default + Overloaded constructor.
	*/
	Time(int = -999, int = -999, int = -999);
	
	// Use compiler-generated copy constructor, assignment, and destructor.
	// Time(const Time&);
	// Time& operator=(const Time&);
	// ~Time();

// OPERATORS
	/** Stream Insertion operator.
	*
	* @param os Standard Output Stream.
	* @param from The value to be inserted to the output stream.
	*
	* @return A reference to the standard output stream.
	*/
	friend std::ostream& operator <<(std::ostream& os, const Time& from);

	/** Stream Extraction operator.
	*
	* @param is Standard Intput Stream.
	* @param to The value to be extracted from the input stream.
	*
	* @return A reference to the standard input stream.
	*/
	friend std::istream& operator >>(std::istream& is, Time& to);

	/** Assignment operator to swap time.
	*
	* @param A Reference to the Right Hand object.
	*
	* @return A reference to the (swapped) current object.
	*/
	Time& operator =(Time&);
	
	/** pre-increment operator.
	*
	* @param void
	*
	* @return A reference to the (incremented) current time.
	*/
	Time& operator ++();

	/** post-increment operator.
	*
	* @param Dummy int to make it different from pre-increment
	*
	* @return Time object with previous value. 
	*/
	Time operator ++(int); //post-increment 

// OPERATIONS
	/** Displays time in 24 hours format.
	*
	* @param void
	*
	* @return void
	*/
	void Display24()const;

	/** Displays time in 12 hours format.
	*
	* @param void
	*
	* @return void
	*/
	void Display12()const;

	/** Add 'X' no. of minutes to the Time object.
	*
	* @param x The no. of minutes to be added.
	*
	* @return void
	*/
	void AddMinute(int x = 0);


// ACCESS
	// setters
	void SetHour(int = 0);
	void SetMinute(int = 0);
	void SetSecond(int = 0);
	void SetTime(int = 0, int = 0, int = 0);
	/**
	# @overload void SetTime(const Time&);
	*/
	void SetTime(const Time&);
	/**
	# static function that sets default time
	*/
	static void sSetDefaultTime(int = -999, int = -999, int = -999);

	// getters
	int GetHour()const;
	int GetMinute()const;
	int GetSecond()const;
	const Time& GetTime()const;
	static const Time& sGetDefaultTime();
	static Time sGetCurrentTime();

private:

// DATA MEMBERS
	int mHour;
	int mMinute;
	int mSecond;
	// class variable shared by all objects of Time class
	static Time msDefaultTime;
};
// end class Time
#endif  
// _TIME_H_
