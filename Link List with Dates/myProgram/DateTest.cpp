#include "DateType.h"
#include <fstream>
#include <ctime>


int main()
{

	//*********************************************
	// Setting the seed for the random function
	//*********************************************
	srand( (unsigned int)time( NULL ) );


	DateType date1, date2;		//Two DateType objects for testing
	ofstream fout;				//for file output
	ifstream fin;				//for file input
	char fileName[50];			//for storing the file name


	int i;	//For storing integers

		
	bool inMenu = true;	// while the user is using the program this var is set to true and the menu keeps looping.
						// when the user wants to quit, it is set to false and the loop ends.

	char keyPressed;	// This var stores which menu selection the user picks.

	while ( inMenu )
	{
		cout<< endl << endl << endl;
		cout << "****************************************************" << endl;
		cout  <<"**  MENU:(press a character to select an option)  **" << endl;
 		cout << "****************************************************" << endl;
		cout<<"Q. [QUIT]     Quit."<<endl;
		cout << endl;

		cout<<"S. [Set random dates] Test the SetRandomDate method,"<<endl;
		cout << endl;


		cout<<"R. [Relational Opetators]  Test all the relational operators"<<endl;
		cout << endl;

		cout<<"A. [Arithmatic Operatos]    Test all the arithmatic operators" << endl;
		cout << endl;
		cout<<"C. [Console input / output]  Test \"cout << date\" and \"cin >> date\" "<<endl;
		cout << endl;
		cout<<"F. [File input / output]  Test \"fout << date\" and \"fin >> date\" "<<endl;
		cout << endl;

		cout << "****************************************************" <<endl<< endl;

		cout<<"Your choice is: ";
		cin >> keyPressed ;



		switch(keyPressed) {
		case 'Q': case 'q'://Quit
			cout << "[QUIT]:" << endl;
			inMenu = false;
			break;

		case 'S': case 's':
			cout << endl << endl 
				  << "******************************************************************" << endl
				  << "***   Test 1: Call date1, a DateType object declared in the main function,"  << endl
				  << "***		to perform the SetRandomDate method 10 times " << endl
				  << "***		to generate 10 random dates." << endl
				  << "******************************************************************" << endl << endl;

			for (i=0; i<10; i++)
			{
				date1.SetRandomDate();
				cout << endl << "Set a new random date: "<<endl;
				date1.PrintDate();

			}

			cout << endl << endl 
				 << "*****************************************" << endl
				 << "*  Do the dates above really look random? " << endl
				 << "*****************************************" << endl;

			system("pause\n");
			break;

		case 'R': case 'r':
			cout << endl << endl 
				  << "******************************************************************" << endl
				  << "***   Test 2: test all the relational operators " << endl
				  << "***		on two DateType objects, date1 and date2 declared " << endl
 				  << "***		in the main function                           " << endl
				  << "******************************************************************" << endl;

			cout << endl << endl << "Read a date into date1:" << endl ;
			date1.ReadDate();
			if (date1.IsValidDate())
				cout << "**That date is valid**\n";
			else
			{
				cout << "**That is an invalid date, please try again**\n";
				system("pause");
				main();
			}
			cout << endl << endl << "Read a date into date2:" << endl ;
			date2.ReadDate();
			if (date2.IsValidDate())
				cout << "**That date is valid**\n";
			else
			{
				cout << "**That is an invalid date, please try again**\n";
				system("pause");
				main();
			}
			cout << endl << endl << "Test whether date1 > date2" << endl ; // > overloaded operator test
			if (date1 > date2)
				cout << "Yes. (date1 > date2) is true " << endl;
			else
				cout << "No. (date1 > date2) is false " << endl;

		    
			cout << endl << endl << "Test whether date1 < date2" << endl ; // < overloaded operator test
			if (date1 < date2)
				cout << "Yes. (date1 < date2) is true " << endl;
			else
				cout << "No. (date1 < date2) is false " << endl;


			cout << endl << endl << "Test whether date1 == date2" << endl ; // == overloaded operator test
			if (date1 == date2)
				cout << "Yes. (date1 == date2) is true " << endl;
			else
				cout << "No. (date1 == date2) is false " << endl;


			cout << endl << endl << "Test whether date1 != date2" << endl ; // != overloaded operator test
			if (date1 != date2)
				cout << "Yes. (date1 != date2) is true " << endl;
			else
				cout << "No. (date1 != date2) is false " << endl;



			cout << endl << endl << "Test whether date1 >= date2" << endl ; // >= overloaded operator test
			if (date1 >= date2)
				cout << "Yes. (date1 >= date2) is true " << endl;
			else
				cout << "No. (date1 >= date2) is false " << endl;


			cout << endl << endl << "Test whether date1 <= date2" << endl ; // <= overloaded operator test
			if (date1 <= date2)
				cout << "Yes. (date1 <= date2) is true " << endl;
			else
				cout << "No. (date1 <= date2) is false " << endl;


			break;

		case 'A': case 'a':
			cout << endl << endl
				<< "******************************************************************" << endl
				<< "***   Test 3: test all the arithmetic operators " << endl
				<< "***		on two DateType objects, date1 and date2 declared " << endl
				<< "***		in the main function                           " << endl
				<< "******************************************************************" << endl;

			cout << endl << endl << "Read a date into date1:" << endl;
			date1.ReadDate();
			if (date1.IsValidDate())
				cout << "**That date is valid**\n";
			else
			{
				cout << "**That is an invalid date, please try again**\n";
				system("pause");
				main();
			}
			cout << endl << endl << "Read a date into date2:" << endl;
			date2.ReadDate();
			if (date2.IsValidDate())
				cout << "**That date is valid**\n";
			else
			{
				cout << "**That is an invalid date, please try again**\n";
				system("pause");
				main();
			}
			cout << endl << endl << "Test the result of date1 - date2" << endl; // - overloaded operator test
			cout << "(date1 - date2) equals " << date1 - date2 << endl;


			cout << endl << endl << "Test the result of date2 = date1 - i;" << endl; // - overloaded operator test
			cout << "(Give me an integer i, i=" << endl;
			cin >> i;
			cout << "Let date2 = date1 - " << i << endl;
			date2 = date1 - i;

			cout << " Now after \"date2 = date1 - i;\" we have date1 as " << endl;
			date1.PrintDate();
			cout << " Now after \"date2 = date1 - i;\" we have date2 as " << endl;
			date2.PrintDate();


			cout << endl << endl << "Test the result of date2 = date1 + i;" << endl; // + overloaded operator test
			cout << "(Give me an integer i, i=" << endl;
			cin >> i;
			cout << "Let date2 = date1 + " << i << endl;
			date2 = date1 + i;


			cout << " Now after \"date2 = date1 - i;\" we have date1 as " << endl;
			date1.PrintDate();
			cout << " Now after \"date2 = date1 - i;\" we have date2 as " << endl;
			date2.PrintDate();

			break;


		default:
			cout << "[?? UNKNOWN COMMAND]:" << endl;
			// Unrecognized key, do nothing
			break;
		}
	}

	return 0;
}
