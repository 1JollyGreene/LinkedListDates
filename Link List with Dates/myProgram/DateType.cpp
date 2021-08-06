// Define member functions of class DateType.
// This is file DateType.cpp.

#include "DateType.h" // gain access to specification of class
#include <iostream>
#include <vector>
using namespace std;

//The first constructor method to initialize a DateType object
//  initialize day, month, year in the object
//  to 1, 1, and 2000 representing 1/1/2000
DateType::DateType()
{
	year = 2000;
	month = 1;
	day = 1;
}


//The second constructor method to initialize a DateType object
//Check whether newMonth, newDay, newYear compose a valid date first.
//If they do Not compose a valid date,
//  initialize day, month, year in the object
//  to 1, 1, and 2000 representing 1/1/2000
//If they do compose a valid date,
//   use newMonth, newDay, newYear to update day, month, year in the object,
DateType::DateType(int newMonth, int newDay, int newYear)
{
	year = newYear;
	month = newMonth;
	day = newDay;
}



//A method to set a new date for the DateType object.
//Check whether newMonth, newDay, newYear compose a valid date first.
//If they do Not compose a valid date,
//   do not change the date stored in the object and then return false.
//If they do compose a valid date,
//   use newMonth, newDay, newYear to update day, month, year in the object,
//   and then return true.
bool DateType::SetDate(int newMonth, int newDay, int newYear)
{
	year = newYear;
	month = newMonth;
	day = newDay;


	return true;
}

int DateType::MonthIs()
// Accessor function for data member month.
{
	return month;
}

int DateType::YearIs()
// Accessor function for data member year.
{
	return year;
}


int DateType::DayIs()
// Accessor function for data member day.
{
	return day;
}


void DateType::ReadDate()
{
	cout << endl
		<< "Read in the information of a date: ";

	cout << endl << "The month is: ";
	cin >> month;
	cout << endl << "The day is: ";
	cin >> day;
	cout << endl << "The year is: ";
	cin >> year;

	
}

void DateType::PrintDate()
{
	cout << "" << month << " / " << day << " / " << year << "\n"; // this will print out what date is currently stored.
}


int DateType::ComparedTo(DateType aDate)
{
	if (year == aDate.year)
	{
		if (month == aDate.month)
		{
			if (day == aDate.day)
				return 0;       //This is to see if they are the same date, if so return 0
		}
	}
	if (year < aDate.year)  //all this checks if it is earlier than aDate. if so return -1
		return -1;
	if (year == aDate.year)
		if (month < aDate.month)
			return -1;
	if (year == aDate.year)
		if (month == aDate.month)
			if (day < aDate.day)
				return -1;
			else return 1;   // if neither -1 or 0, return 1 which means aDate is earlier than year
}

int DateType::ComparedCentury(DateType aDate)
{
	int Bcheck = 0;
	int Acheck = 0;
	for (int B = 0; B < 101; B++) //check to see if the year is 100 years before year
	{
		Bcheck = year - B;
		if (Bcheck == aDate.year)
			return 0; //return that they are in the same century
	}
	for (int A = 0; A < 101; A++) //check to see if the year is 100 years after year
	{
		Acheck = year + A;
		if (Acheck == aDate.year)
			return 0;   //return that they are in the same century
	}
	if (year > aDate.year)
		return 1;  //return that they are in different centuries
	else return -1;
}

void DateType::AdvanceDays(int numDays)
{
	for (int i = 0; i < numDays; i++) //advance the number of days through the year
	{
		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10))
		{
			day++;
			if (day == 32)//make sure the days dont advance beyond the month
			{
				day = 1;  //Set the days to 1 to start the next calander month
				month++;
			}
		}
		else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		{
			day++;
			if (day == 31) //make sure the days dont advance beyond the month
			{
				day = 1;
				month++;
			}
		}
		else if (month == 2)
		{
			day++;
			if (((year % 4) == 0) && ((year % 100) != 0) || (year % 400) == 0) //The unique case of a leap year
			{
				if (day == 30)  //make sure the days dont advance beyond the month
				{
					day = 1;
					month++;
				}
			}
			else if (day == 29) //make sure the days dont advance beyond the month
			{
				day = 1;
				month++;
			}
		}
		else if (month == 12) //if the month is december the year must change to accomidate the advancement of days
		{
			day++;
			if (day == 32)
			{
				day = 1;
				month = 1; //change the month to January and start the calander over
				year++; //advance the year 1.
			}
		}
	}
	return;
}
void DateType::BackDays(int numDays)
{
	for (int i = 0; i < numDays; i++) //advance the number of days through the year
	{
		if ((month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
		{
			day--;
			if (day == 0) //make sure the days dont advance beyond the month
			{
				month--;
				day = 30;
				if (month == 2)
				{
					if (((year % 4) == 0) && ((year % 100) != 0) || (year % 400) == 0)
						day = 29;
					else
						day = 28;
				}

			}
		}
		else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		{
			day--;
			if (day == 0) //make sure the days dont advance beyond the month
			{
				month--;
				day = 31;
			}
		}
		else if (month == 2)
		{
			day--;
			if (day == 0)  //make sure the days dont advance beyond the month
			{
				month--;
				day = 31;
			}
		}
		else if (month == 1) //if the month is January the year must change to accomidate the advancement of days
		{
			day--;
			if (day == 0)
			{
				month = 12; //change the month to December to move backwards in the calander year.
				day = 31; //start the day off in December to advance backwards
				year--; //subtract 1 year.
			}
		}
	}
	return;
}

bool DateType::IsValidDate()
{
	int status, leapyear;

	if (year > 0 && year < 2019)
	{
		if (month > 0 && month < 13)        //Figure out which month is selected
		{
			if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12)
			{
				if (day > 0 && day < 32)  //if it is one of these months it can only be this many days
					status = true;
				else
					status = false;
				return status;
			}
			if (month == 2)
			{
				if (((year % 4) == 0) && ((year % 100) != 0) || (year % 400) == 0)
				{
					if (day > 0 && day < 29);  //can be the 28th if a leap year
				}
				if (day > 0 && day < 30)
					status = true;
				else
					status = false;
				return status;
			}
			if (month == 4 || 6 || 9 || 11)
			{
				if (day > 0 && day < 31)  //If one of these months it can only be this many days
					status = true;
				else
					status = false;
				return status;
			}
			else
				status = false;
			return status;
		}
		else
			status = false;
		return status;
	}
	else
		status = false;
	return status;
}

void DateType::SetRandomDate() //set the contents to a valid random date
{
	year = (rand() % 2019);
	month = (rand() % 12);

	if (year > 0 && year < 2019)
	{
		if (month > 0 && month < 13)        //Figure out which month is selected
		{
			if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12)
			{
				day = (rand() % 31);
			}
			else if (month == 2)
			{
				if (((year % 4) == 0) && ((year % 100) != 0) || (year % 400) == 0)
				{
					day = (rand() % 29);  //can be the 28th if a leap year
				}
				else
				{
					day = (rand() % 28);
				}
					
			}
			else if (month == 4 || 6 || 9 || 11)
			{
				day = (rand() % 30);
			}
		}
	}
}



bool DateType::operator> (const DateType & aDate)  //Define the relationl operator >
{
	int status;
	if (year > aDate.year)  //all this checks if it is earlier than aDate. if so return -1
	{
		status = true;
	 if (year == aDate.year)
	{
		if (month > aDate.month)
			status = true;
	}
	 if (year == aDate.year)
	{
		if (month == aDate.month)
			if (day > aDate.day)
				status = true;

	}
	}
	else status = false;
	return status;
}

bool DateType::operator< (const DateType & aDate)
{
	int status;
	if (year < aDate.year)  //all this checks if it is earlier than aDate. if so return -1
	{
		status = true;
		if (year == aDate.year)
		{
			if (month < aDate.month)
				status = true;
		}
		if (year == aDate.year)
		{
			if (month == aDate.month)
				if (day < aDate.day)
					status = true;
		}
	}
	else status = false;
	return status;
}

bool DateType::operator== (const DateType & aDate) //Define the relationl operator ==
{
	int status = false;
	if (year == aDate.year)
	{
		if (month == aDate.month)
			if (day == aDate.day)
		     	status = true;       //This is to see if they are the same date, if so return 0
	}
   return status;
}

bool DateType::operator!= (const DateType & aDate) //Define the relationl operator !=
{
	int status;
	if (year != aDate.year)
	{
		status = true;
		if (month != aDate.month)
			status = true;
		if (day != aDate.month)
			status = true;
	}
	else status = false;
	return status;
}
bool DateType::operator>= (const DateType & aDate) //Define the relationl operator >=
{
	if (year == aDate.year)
	{
		if (month == aDate.month)
		{
			if (day == aDate.day)
				return true;       //This is to see if they are the same date, if so return 0
		}
	}
	if (year > aDate.year)  //all this checks if it is earlier than aDate. if so return -1
		return true;
	if (year == aDate.year)
		if (month > aDate.month)
			return true;
	if (year == aDate.year)
		if (month == aDate.month)
			if (day > aDate.day)
				return true;
	return false;   // if neither -1 or 0, return 1 which means aDate is earlier than year
			
}


bool DateType::operator<= (const DateType & aDate) //Define the relationl operator <=
{
	if (year == aDate.year)
	{
		if (month == aDate.month)
		{
			if (day == aDate.day)
				return true;       //This is to see if they are the same date, if so return 0
		}
	}
	if (year < aDate.year)  //all this checks if it is earlier than aDate. if so return -1
		return true;
	if (year == aDate.year)
		if (month < aDate.month)
			return true;
	if (year == aDate.year)
		if (month == aDate.month)
			if (day < aDate.day)
				return true;
	return false;   // if neither -1 or 0, return 1 which means aDate is earlier than year

}
int DateType::operator- (const DateType & aDate)
{
	cout << "The year difference is " << year - aDate.year;
	cout << "\nThe month difference is " << month - aDate.month;
	cout << "\nThe day difference is " << day - aDate.day;

		return year, month, day;

}
 


DateType DateType::operator+ (int numDays)
{
	for (int i = 0; i < numDays; i++) //advance the number of days through the year
	{
		if ((month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
		{
			day--;
			if (day == 0) //make sure the days dont advance beyond the month
			{
				month--;
				day = 30;
				if (month == 2)
				{
					if (((year % 4) == 0) && ((year % 100) != 0) || (year % 400) == 0)
						day = 29;
					else
						day = 28;
				}

			}
		}
		else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		{
			day--;
			if (day == 0) //make sure the days dont advance beyond the month
			{
				month--;
				day = 31;
			}
		}
		else if (month == 2)
		{
			day--;
			if (day == 0)  //make sure the days dont advance beyond the month
			{
				month--;
				day = 31;
			}
		}
		else if (month == 1) //if the month is January the year must change to accomidate the advancement of days
		{
			day--;
			if (day == 0)
			{
				month = 12; //change the month to December to move backwards in the calander year.
				day = 31; //start the day off in December to advance backwards
				year--; //subtract 1 year.
			}
		}
	}
	return *this;
	

}
DateType DateType::operator- (int numDays)
{
	for (int i = 0; i < numDays; i++) //advance the number of days through the year
	{
		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10))
		{
			day++;
			if (day == 32)//make sure the days dont advance beyond the month
			{
				day = 1;  //Set the days to 1 to start the next calander month
				month++;
			}
		}
		else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		{
			day++;
			if (day == 31) //make sure the days dont advance beyond the month
			{
				day = 1;
				month++;
			}
		}
		else if (month == 2)
		{
			day++;
			if (((year % 4) == 0) && ((year % 100) != 0) || (year % 400) == 0) //The unique case of a leap year
			{
				if (day == 30)  //make sure the days dont advance beyond the month
				{
					day = 1;
					month++;
				}
			}
			else if (day == 29) //make sure the days dont advance beyond the month
			{
				day = 1;
				month++;
			}
		}
		else if (month == 12) //if the month is december the year must change to accomidate the advancement of days
		{
			day++;
			if (day == 32)
			{
				day = 1;
				month = 1; //change the month to January and start the calander over
				year++; //advance the year 1.
			}
		}
	}
	return *this;
	
}
ostream & operator<< (ostream & output, const DateType & aDate)
{

	if (&output == &cout)
	{
		output << aDate.month << '/' << aDate.day << '/' << aDate.year << " ";
	}
	else
	{
		output << aDate.month << ' ' << aDate.day << ' ' << aDate.year << " ";
	}

	return output;
}
istream & operator>> (istream & input, DateType & aDate)
{
	if (&input == &cin)
	{
		aDate.ReadDate();
		if (aDate.IsValidDate())
			cout << "**That date is valid**\n";
		else
		{
			cout << "**That is an invalid date, please try again**\n";
			system("pause");
			int main();
		}
	}
	else
	{
		input >> aDate.month >> aDate.day >> aDate.year;
	}
	return input;
}
