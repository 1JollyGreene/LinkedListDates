#include <iostream>
#include <vector>
#include "DateType.h"
#include <string>
#include<fstream>


using namespace std;

bool mergeTwoSortedVectors
(vector<DateType> & vecA, vector<DateType> & vecB, vector<DateType> & vecC)
{
	vector<DateType> checkA;
	vector<DateType> checkB;
	int countA = 0;
	int countB = 0;
	int countC = 0;
	checkA.resize(vecA.size());
	checkB.resize(vecB.size());
	if (vecA.size() >= 1)
	{
		for (int j = 0; j < vecA.size(); j++)
		{
			countA++;
			if (checkA[0] <= vecA[j])
				checkA[0] = vecA[j];
			else
				return 0;
		}

	}

	if (vecB.size() >= 1)
	{
		for (int j = 0; j < vecB.size(); j++)
		{
			countB++;
			if (checkB[0] <= vecB[j])
				checkB[0] = vecB[j];
			else
				return 0;
		}
	}
	vecC.resize(vecA.size() + vecB.size());
	countA = 0;
	countB = 0;

	while (countB != vecB.size() && countA != vecA.size())
	{

		if (vecA[countA] > vecB[countB])
		{
			vecC[countC] = vecB[countB];
			countB++;
			countC++;
		}
		else
		{
			vecC[countC] = vecA[countA];
			countA++;
			countC++;
		}
	}
	if (countB == vecB.size())
	{
		while (vecA.size() != countA)
		{
			vecC[countC] = vecA[countA];
			countA++;
			countC++;
		}
	}
	if (countA == vecA.size())
	{
		while (vecB.size() != countB)
		{
			vecC[countC] = vecB[countB];
			countB++;
			countC++;
		}


	}
	return 1;
}



void mergeSort(vector<DateType> & vecToSort)
{
	vector<DateType> vec1;
	vector<DateType> vec2;
	int count1 = 0;
	int count2 = 0;
	if (vecToSort.size() == 1)
		return;
	if (vecToSort.size() == 2)
	{
		if (vecToSort[0] > vecToSort[1])
		{
			DateType temp = vecToSort[1];
			vecToSort[1] = vecToSort[0];
			vecToSort[0] = temp;
		}
		else
			return;
	}
	vec1.resize(vecToSort.size() / 2);
	vec2.resize(vecToSort.size() - vecToSort.size() / 2);
	while (count1 < vec1.size())
	{
		vec1[count1] = vecToSort[count1];
		count1++;
	}

	while (count2 < vec2.size())
	{

		vec2[count2] = vecToSort[count1];
		count1++;
		count2++;

	}
	mergeSort(vec1);
	mergeSort(vec2);
	mergeTwoSortedVectors(vec1, vec2, vecToSort);



	//vecToSort.size() / 2 and vecToSort.size() - vecToSort.size() / 2 respectively, and copy the first vecToSort.size() / 2 elements 
		//in vecToSort into the first vector and  the remaining vecToSort.size() - vecToSort.size() / 2  into the second vector.
		//·  Call mergeSort(vec1)  to sort the first vector.
		//·  Call mergeSort(vec2) to sort the second vector.
		//·  Call mergeTwoSortedVectors(vec1, vec2, vecToSort)  to merge  the two sorted vectors vec1 and vec2 into vecToSort to make it a sorted vector
}


int main()

{
	bool inMenu = true;	// while the user is using the program this var is set to true and the menu keeps looping.
					// when the user wants to quit, it is set to false and the loop ends.

	vector<DateType> dateDB;
	vector<DateType> emptytest;
	

	int date;
	string filename;
	ifstream fin;
	ofstream fout;
	int month, day, year;
	char keyPressed;	// This var stores which menu selection the user picks.
	int SetNum1, SetNum2, sortnum;
	int count = 0;
	DateType temp;
	DateType Etest;
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
		cout << "S. [Sort] Sort the dates into order." << endl;
		cout << "****************************************************" << endl << endl;

		cout << "Your choice is: ";
		cin >> keyPressed;
		switch (keyPressed) {

		case 'k': case 'K':
		{
			dateDB.clear();
			cout << "how many dates would you like to enter?\n";
			cin >> numDates;
			for (int i = 0; i < numDates; i++)
			{
				temp.ReadDate(); //this is how to create dates
				if (temp.IsValidDate())
				dateDB.push_back(temp); // <
				else
				{
					cout << "Must enter a valid date Please start over.\n";
					system("pause");
					break;
				}

				
			}
			break;
		}
		case 'b': case 'B':
		{
			emptytest.clear();
			cout << "What is the file you would like to open?\n";
			cin >> filename;
			fin.open(filename);
			while (fin >> Etest)
			{
				emptytest.push_back(Etest);
			}
			if (emptytest.size() > 0)
			{
				dateDB.clear();
				dateDB.resize(emptytest.size());
				dateDB = emptytest;
		    }
			
			fin.close();
			cout << "The vector now contains that file.\n";
			break;
		}
		case 'd': case 'D':
		{
			for (DateType temp : dateDB)
				temp.PrintDate();
			break;
		}
		case 'm': case 'M':
		{
			int i = 0;
			int Rstuff = 0;
			int datenum;

			for (DateType temp : dateDB)
			{
				Rstuff++;
				cout << "Date #" << (Rstuff) << " is " << temp << " .\n";

			}

			cout << "What is the Date you wish to modify a score on?\n";
			cin >> datenum;
			while (datenum > Rstuff || datenum < 1)
			{
				cout << "You must enter a number for a Date\n";
				cin >> datenum;
			}

			cout << "Date #" << datenum << ": ";
			cin >> dateDB[datenum - 1];
			break;
		}
		case 'w': case 'W':
		{
			cout << "What is the file name you would like to write to?\n";
			cout << "** be sure to type .txt **\n";
			cin >> filename;
			fout.open(filename);
			cout << filename << " Contains Dates." << endl;
			for (DateType temp : dateDB)
				fout << temp;
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
			for (DateType temp : dateDB)
			{
				if (temp >= dBegin && temp <= dEnd)
					cout << dBegin << temp << dEnd << endl;
			}
			

			 //If the choice is ‘F’, the program should ask the user to provide the beginning date and the ending date of the date range
			//(i.e.”  cin >> dBegin; ”  and ”  cin >> dEnd;  ”), and then the program should  
			//set up a loop to check each element dateDB[i] in the vector dateDB and display the contents of dateDB[i]  if dateDB[i]  
			//is within the range(i.e. if ”  dBegin <= dateDB[i] && dateDB[i] <= dEnd ”  is true)
			break;
		}


		case 's': case 'S':
		{
			mergeSort(dateDB);
			for (DateType val : dateDB)
				cout << val << endl;
			break;
		}
		case 'q': case 'Q':
		{
			cout << "[QUIT]:" << endl;
			inMenu = false;
			break;
		}




		//cout << "**Series Sorting**\n";
		//cout << "Enter size of vector to be sorted.\n";
		//cin >> sortnum;
			//for (int i = 0; i < sortnum; i++)
			//{
				//int tempValue;
				//cout << "Enter a number\n";
				//cin >> tempValue;
				//if (tempValue < 0)
				//{
					//cout << "It must be a positive integer, please start over\n";
					//system("pause");
					//main();
				//}
				//tosort.push_back(tempValue);
			//}
			//mergeSort(tosort);
			//for (int val : tosort)
				//cout << val << endl;

		//for (int val : set1)
			//cout << val << endl;
		//for (int val : set2)
			//cout << val << endl;

		}
	}
}