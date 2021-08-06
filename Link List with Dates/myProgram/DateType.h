//**********************************************************
//The following two lines are additional compiler directives
//	to avoid the inclusion of the contents of DateType.h
//	more than one time when compiling shoe .cpp file.
//**********************************************************
#ifndef MY_DATETYPE_H
#define MY_DATETYPE_H

#define LESS	-1
#define EQUAL	0
#define GREATER	1

#include <iostream>
using namespace std;

// This is file DateType.h
// Here we declare the interface of a class so that we can
//	store the information of dates in objects of the DateType class and
//	call methods provided by these objects to process date information
// The actually implementation of the methods is inside DateType.cpp

class DateType
{
 public:	//The following members can be called anywhere

  DateType();
  //The first constructor method to initialize a DateType object
  //  initialize day, month, year in the object
  //  to 1, 1, and 2000 representing 1/1/2000

  DateType(int newMonth, int newDay, int newYear);
  //The second constructor method to initialize a DateType object
  //Check whether newMonth, newDay, newYear compose a valid date first.
  //If they do Not compose a valid date,
  //  initialize day, month, year in the object
  //  to 1, 1, and 2000 representing 1/1/2000
  //If they do compose a valid date,
  //   use newMonth, newDay, newYear to update day, month, year in the object,


  int YearIs();       // a method to returns year
  int MonthIs();      // a method to returns month
  int DayIs();        // a method to returns day

  bool SetDate(int newMonth, int newDay, int newYear);
  //A method to set a new date for the DateType object.
  //Check whether newMonth, newDay, newYear compose a valid date first.
  //If they do Not compose a valid date,
  //   do not change the date stored in the object and then return false.
  //If they do compose a valid date,
  //   use newMonth, newDay, newYear to update day, month, year in the object,
  //   and then return true.

  void ReadDate();
  //A method to read in three integers and set them as the
  //	as the day, month, year of the DateType object to the console cout

  void PrintDate();
  //A method to output the contents of the DateType object to the console cout

  int ComparedTo(DateType aDate);
  // Pre: the object itself and aDate should have been initialized.
  // Post:return value should be
  // 	LESS, if the object itself comes before aDate.
  //	EQUAL, if the object itself is the same as aDate.
  //	GREATER, if the object itself comes after aDate.

  int ComparedCentury(DateType aDate);
	// Pre: Self and aDate have been initialized.
	// Post: return
	//	LESS, if the object itSelf comes before the century of aDate.
	//	EQUAL, if the object itSelf is in the same century as aDate.
	//	GREATER, if the object itSelf comes after the century of aDate.

	void AdvanceDays(int NumDays);
	//Modify the date by advancing it "NumDays" days into the future.
	//Basic approach for implementing AdvanceDays: 
	//The easiest way to advance the current date some (non-negative) NumDays days 
	//	into the future is to use a loop that repeats for NumDays iterations. 
	//	Inside the loop, write your C++ code such that it can correctly 
	//	just advance the date one day into the future on each iteration of the loop. 
	//Note that in the is approach 
	//	(i) you need to precisely detect whether the current date is in the end of the month, 
	//		and be careful especially about February since it depends on whether it is a leap year, 
	//	(ii) when it is not the end of the month advancing one day into the future is very easy, but 
	//	(iii) when it is the end of the month, you have to carefully advance the date into 
	//		the first day of the next month, be careful especially when it is December 31.

	void BackDays(int NumDays);
	//Modify the date by pushing it back "NumDays" days into the past.
	//The easiest way to back down the current date some (non-negative) NumDays days 
	//	into the past is to use a loop that repeats for NumDays iterations. 
	//	Inside the loop, write your C++ code such that it can correctly just back down the date 
	//	one day into the past on each iteration of the loop. 
	//Note that in the is approach 
	//	(i) you need to precisely detect whether the current date is in the beginning of the month, 
	//	(ii) when it is not the beginning of the month backing down one day into the past is very easy, but 
	//	(iii) when it is the beginning of the month, you have to carefully back down the date into 
	//		the very last day of the previous  month, and you need to be careful 
	//		especially when it is Jan. 1 or March 1 (since the previous day could be Feb. 28 or Feb 29 
	//		depending on whether it is a leap year).

	bool IsValidDate ();
	//Check the input date to make sure it is a valid date.
	//You can reuse what you did in Programming #3 and #5C in CSCI 105 last semester to 
	//	implement this member function. 
	//Essentially, you need to use the if statement or the switch statement to check to return true 
	//	only when the value in the data member day falls in the range of 
	//	(i) 1 to 31 if the data member month  indicates a month of 31 days, or 
	//	(ii) 1 to 30 if the data member month  indicates a month of 30 days, or 
	//	(iii) 1 to 28 if the data member month  indicates it is February while 
	//		the data member year  indicates it is not a leap year, or 
	//	(iv) 1 to 29 if the data member month  indicates it is February while 
	//		the data member year  indicates it is a leap year.
	//
	//How to determine leap years: 
	//	A year is a leap year if it is divisible by 4 except that 
	//		any year divisible by 100 is a leap year only if it is also divisible by 400. 
	//		So 1900 is not a leap year, but 2000 is. 
	//	In other words, 
	//		(i) a year (e.g. 1996) is a leap year if it is divisible by 4 but not by 100, 
	//		(ii) a year (e.g. 2000) is a leap year if it is divisible by 400, 
	//		(iii) otherwise, it is not a leap year.

  private: //The following members can be direclt accessed in DateType.cpp
  int year;
  int month;
  int day;



  //**********************************************************************
  // The following are new public member functions just added into DateType
  //**********************************************************************

  public:

  void SetRandomDate();
	//set the contents to a valid random date

  bool operator> (const DateType & aDate);
	//Define the relationl operator >

  bool operator< (const DateType & aDate);
	//Define the relationl operator <

  bool operator== (const DateType & aDate);
	//Define the relationl operator ==

  bool operator!= (const DateType & aDate);
	//Define the relationl operator !=

  bool operator>= (const DateType & aDate);

      //Define the relationl operator >=

  bool operator<= (const DateType & aDate);

      //Define the relationl operator <=


  DateType operator+ (int numDays);

  DateType operator- (int numDays);

  int operator- (const DateType & aDate);
      
  friend ostream & operator<< (ostream & output, const DateType & aDate);

  friend istream & operator>> (istream & input, DateType & aDate);

};

#endif


