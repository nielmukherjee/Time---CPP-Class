# Time---CPP-Class
Defining class in C++

## Task 1 - Class definition
Create a class named **Time** that contains integer fields for *hours*, *minutes* and *seconds*. The hours should be stored in military time (24-hours format), that is, 0 through 23. User must be able to perform following operations:
  * Get and set current hour, minute and second
  * Add a function that displays the universal time in 24-hours format, using a colon to separate hours, minutes and seconds. For example 3 o’clock evening should be displayed as 15:00:00
  * Add a function that displays the standard time in 12-hours format, using a colon to separate hours, minutes and seconds followed by AM/PM accordingly. For example 3 o’clock evening should be displayed as 03:00:00 PM
  * Add another function that takes an argument as minutes to be added to the time. This function increments by x number of minutes in current time. For example, 12:30 plus 15 is 12:45, 14:50 plus 20 is 15:10, and 23:59 plus 2 is 0:01.
  * The arguments in Time constructor for hours, minutes and seconds are optional. All three values initialize to default time if no argument is supplied.
  * The constructor and setter functions ensure that the hours field is not greater than 23 and that the minutes and second fields are not greater than 59; default to these maximum values if the arguments to the constructor are out of range.
  * Set default time to a specific time e.g. 15:45:00

Create a main( ) function that instantiates an array of at least four Time objects and demonstrates that they display correctly both before and after varying amounts of time have been added to them.

## Task 2 - Operator Overloading
For the above **Time** class, perform following additional operations:
 * Overload the stream insertion << operator to display current time on screen. e.g.
  ```
  Time t1(8, 20, 10); 
  cout << t1; // will display 08:20:10
  ```
 * Overload operator = that interchanges (swap) two time values. e.g.
  ```
  Time t1(8, 20, 10), t2(3, 40, 34); 
  t1 = t2; 
  cout << t1; // will display 03:40:34 
  cout << t2; // will display 08:20:10
  ```
 * Overload the pre and post increment operator for this class so that it adds 1 hour to the current time value. Minutes and hours remain unchanged. e.g.
  ```
  Time t1(8, 20, 10); 
  t1++; // or ++t1; 
  cout << t1; // will display 09:20:10
  ```
Create a main( ) function to demonstrate the above 3 features of the Time class.

## Task 3 - Operator Overloading
Create a class named **Alarm** inherited from class **Time** of Tasks 1 & 2 that contains integer data for *volume*, and string for *alarm type*. The volume level can be set from 0 to 5. The alarm type can be set to: "Melody", "Vibration", "Melody+Vibration":
 * Overload the stream extraction >> operator to set the alarm. e.g.
 ```
 Alarm a1;
 cin >> a1;     // will set alarm a1 according to the user input
 ```
 
 * Overload subscript operator [ ] that takes integer value to set volume in valid range (0-5). e.g.
 ```
 a1[0];  // will mute the alarm
 a1[5];  // will set the maximum possible volume level
 ```
* Write the code for type conversion from **Time** to **Alarm** and vice versa.
