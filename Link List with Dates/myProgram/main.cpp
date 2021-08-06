// File: main.cpp

#include <iostream>
#include <string>
#include <ctime>
#include "LinkedList.h"
#include "DateType.h"
using namespace std;

void main()
{
  {
	  List dateDB;
	  clock_t t1, t2;
	  bool inMenu = true;	// while the user is using the program this var is set to true and the menu keeps looping.
	
							// when the user wants to quit, it is set to false and the loop ends.
	  double n;
	  int date;
	  string filename;
	  ifstream fin;
	  ofstream fout;
	  int month, day, year;
	  char keyPressed;	// This var stores which menu selection the user picks.
	  int SetNum1, SetNum2, sortnum;
	  int count = 0;
	  DateType temp;
	  int i = 0;
	  int numDateRecords;
	  int numDates;


	  while (inMenu)
	  {

		  cout << endl << endl << endl;
		  cout << "****************************************************" << endl;
		  cout << "**  MENU:(press a character to select an option)  **" << endl;
		  cout << "****************************************************" << endl;
		  cout << "Q. [QUIT]     Quit." << endl;
		  cout << "K. [ENTER DATES] Enter any dates into the vector," << endl;
		  cout << "B. [Read Batch] Clear vector into empty vector then read a batch of dates from a txt file," << endl;
		  cout << "D. [Display] Display what is currently written in file," << endl;
		  cout << "M. [Modify] Modify One of your dates," << endl;
		  cout << "W. [Write] Write dates into File," << endl;
		  cout << "F. [Find] Find days," << endl;
		  cout << "X. [RANDOM] Insert dates in order" << endl;
		  cout << "Y. [RANDOM] Insert dates" << endl;
		  cout << "Z. [RANDOM] Remove" << endl;
		  cout << "****************************************************" << endl << endl;

		  cout << "Your choice is: ";
		  cin >> keyPressed;
		  switch (keyPressed) {

		  case 'k': case 'K':
		  {
			  dateDB.Clear();
			  cout << "how many dates would you like to enter?\n";
			  cin >> numDates;
			  for (int i = 0; i < numDates; i++)
			  {
				  temp.ReadDate();
				  if (temp.IsValidDate())
					  dateDB.InsertInOrder(temp);
				  else
				  {
					  cout << "Must enter a valid date Please start over.\n";
					  break;
				  }


			  }
			  break;
		  }
		  case 'b': case 'B':
		  {
			
			  cout << "What is the file you would like to open?\n";
			  cin >> filename;
			  fin.open(filename);
			  fin >> dateDB;
			

			  fin.close();
			  cout << "The list now contains that file.\n";
			  break;
		  }
		  case 'd': case 'D':
		  {
			  dateDB.Display();
			  break;
		  }
		  case 'm': case 'M':
		  {
			  DateType datenum;


			  dateDB.Display();

			  cout << "Type in the Date you wish to modify?\n";
			  temp.ReadDate();
			  //cin >> datenum;
			  if (dateDB.Search(temp) == true) {
				  dateDB.Remove(temp);
				  cout << "\nDate has been removed. Please enter new date: ";
				  temp.ReadDate();
				  if (temp.IsValidDate() == true)
					  dateDB.InsertInOrder(temp);
				  else
					  cout << "\nDate entered is not valid";
			  }
			  else
				  cout << "\nDate entered is not in list";
			  break;
		  }
		  case 'w': case 'W':
		  {
			  cout << "What is the file name you would like to write to?\n";
			  cout << "** be sure to type .txt **\n";
			  cin >> filename;
			  fout.open(filename);
				  fout << dateDB;
			  fout.close();
			  break;
		  }
		  case 'f': case 'F':
		  {
			  DateType dBegin, dEnd;
			  cout << "What is the starting date you would like to use to search between?\n";
			  cin >> dBegin;
			  cout << "What is the end date you would like to use?\n";
			  cin >> dEnd;
			  dateDB.FindAndDisplay(dBegin, dEnd);


			  //If the choice is ‘F’, the program should ask the user to provide the beginning date and the ending date of the date range
			 //(i.e.”  cin >> dBegin; ”  and ”  cin >> dEnd;  ”), and then the program should  
			 //set up a loop to check each element dateDB[i] in the vector dateDB and display the contents of dateDB[i]  if dateDB[i]  
			 //is within the range(i.e. if ”  dBegin <= dateDB[i] && dateDB[i] <= dEnd ”  is true)
			  break;
		  }
		  case 'x': case 'X':
		  {
		
			  DateType d;
			  dateDB.Clear();
			  cout << "How many random dates would you like to set in order? : ";
			  cin >> n;
			  t1 = clock();
			  for (int i = 1; i <= n; i++)
			  {
				  d.SetRandomDate();
				  temp = d;
				  dateDB.InsertInOrder(temp);
			  }
			  t2 = clock();
			  printf("%fn", (double)(t2 - t1) / CLOCKS_PER_SEC);
			  break;
		  }
		  case 'y': case 'Y':
		  {
			  
			  DateType d;
			  dateDB.Clear();
			  cout << "How many random dates would you like to set? : ";
			  cin >> n;
			  t1 = clock();
			  for (int i = 0; i <= n; i++)
			  {
				  d.SetRandomDate();
				  temp = d;
				  dateDB.Insert(temp);
			  }
			  t2 = clock();
			  printf("%fn", (double)(t2 - t1) / CLOCKS_PER_SEC);
			  break;
		  }
		  case 'z': case 'Z':
		  {
			  double m;
			  DateType d;
			  cout << "how many would you like to remove?";
			  cin >> m;
			  t1 = clock();
			  for (int i = 0; i <= m; i++)
			  {
				  d.SetRandomDate();
				  dateDB.Remove(d);
			  }
			  t2 = clock();
			  printf("%fn", (double)(t2 - t1) / CLOCKS_PER_SEC);
			  break;
		  }
		  case 'q': case 'Q':
		  {
			  cout << "[QUIT]:" << endl;
			  inMenu = false;
			  break;
		  }

		  }
	  }
  }
}




