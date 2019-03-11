/*
Program Info
Name: JUSTIN STRELKA
CSC 161-Section: 001 Fa18
Creation Date: 9/18/2018
Program Name: BIRDAPP.CPP (BIRDAPP)
Description: CONSOLE APP USING DATETIME/BIRD/MIBIRDRIDES CLASSES
Version: 11/27/2018
Sources: C++ DATA STRUCTURES/ CPLUSPLUS.COM
*/

// INCLUDE LIBRARIES 
#include <fstream>
#include <iostream>
#include <string>

// VISUAL LEAK DETECTOR
#include <vld.h>

// INCLUDE HEADER FILES
#include "BinTree.h"
#include "Bird.h"
#include "BinNode.h"

// NAMESPACE
using namespace strelka_bird_1;

// PROTOTYPE FUNCTIONS
bool checkIfStringIsInt(std::string stringToCheck);


//INITIALIZE INT MAIN
int main()
{
	// INITIALIZE RIDES ARRAY
	BinTree<Bird> rides;

	// INITIALIZE ALL VARIABLES
	std::string programContinue;
	std::string removeId;
	bool loopFinish = false;

	// READ FILE TO FILL RIDES ARRAY
	rides.readFile("my_rides.csv");

	// UI GRETTING MESSAGE
	std::cout << "Welcome to Your Bird Ride Inventory!\n\n";

	// MENU LOOP
	do
	{
		// UI MENU OPTIONS
		std::cout << "What would you like to do?\n\n";
		std::cout << "Enter *** ADD *** to add a ride.\n";
		std::cout << "Enter *** REMOVE *** to remove a ride by Unique Id.\n";
		std::cout << "Enter *** USED *** to view amount of rides in inventory.\n";
		std::cout << "Enter *** PRINT-ALL *** to print entire inventory.\n";
		std::cout << "Enter *** QUIT *** to exit program.\n";
		std::cout << "************************************\n";

		// PLACE USER INPUT INTO VARIABLE FOR BRANCH TESTING
		std::cin >> programContinue;

		// ADD RIDE OPTION
		if (programContinue == "add" || programContinue == "ADD" || programContinue == "a" || programContinue == "A")
		{
			do
			{
				// CREATE BIRD OBJECT TO ADD
				Bird ride;

				// INITIALIZE WHILE LOOP TO GET INPUT FOR ADDING RIDE.
				do
				{
					// CLEAR AND SET ISTREAM BIT
					std::cin.clear();
					// SET ISTREAM BIT TO GOOD
					std::cin.setstate(std::ios_base::goodbit);
					// CALL BIRD >> OPERATOR
					std::cin >> ride;

					// CONTINUE LOOP WHILE ISTREAM BIT IS IN FAIL STATE
				} while (std::cin.fail());

				// MAKE SURE RIDE ID IS UNIQUE AND ADD RIDE TO BIRDS ARRAY
				loopFinish = rides.add(ride);

				// INFORM USER IF ADDING A RIDE FAILED AND INITIALIZE LOOP AGAIN. 
				if (loopFinish == false)
				{
					std::cout << "Whoops something went wrong adding your ride please try again." << std::endl;
				}
			} while (loopFinish == false);
			// INFORM USER OF A SUCCESSFULLY ADDED RIDE.
			std::cout << "I have SUCESSFULLY added your ride to the database. Thank you!.\n\n";
		}
		// PRINT ALL
		else if (programContinue == "print-all" || programContinue == "PRINT-ALL" || programContinue == "print" || programContinue == "PRINT" || programContinue == "p" || programContinue == "P")
		{
			// CALL RIDES PRINTALL FUNC
			rides.printAll();
		}
		
		// USED
		else if (programContinue == "used" || programContinue == "USED" || programContinue == "U" || programContinue == "u")
		{
		// CALL RIDES.GETUSED FUNCTION AND PRINT IT TO CONSOLE
			std::cout << "You currently have " << rides.countItems() << " rides in your inventory.\n\n";
		}

		// REMOVE
		else if (programContinue == "remove" || programContinue == "REMOVE")
		{
			do
			{
				// INITIALIZE "REMOVE" VARIABLES
				std::string removeId;
				loopFinish = false;
				// GET USER INPUT FOR UNIQUE BIRD ID TO REMOVE
				std::cout << "Please enter the Ride ID number you wish to remove from inventory: ";
				std::cin >> removeId;
				// CHECK IF USER INPUT IS OF INT VALUE
				loopFinish = checkIfStringIsInt(removeId);
				if (loopFinish == true)
				{
					// CREATE TEMP BIRD WITH REMOVEID DATA FOR COMPARISON
					Bird ride;
					ride.setId(std::stoi(removeId));
					
					// CALL BINTREE REMOVE FUNCTION
					loopFinish = rides.remove(ride);
					if (loopFinish == true)
					{
					// PRINT SUCCESS MESSAGE TO USER IF SUCCESSFUL
					std::cout << "\nSuccess I have removed ride ID: " << removeId << "\n\n";
					}
					else
					{
					// PRINT ERROR MESSAGE TO USER IF UNSUCCESSFUL
						std::cout << "\nPlease enter a valid ride ID and try again.\n";
					}
				}
				else
				{
					// PRINT ERROR MESSAGE TO USER IF UNSUCCESSFUL
					std::cout << "\nPlease enter a valid ride ID and try again.\n";
				}
			} while (loopFinish == false);
		}
	} while (programContinue != "quit" && programContinue != "QUIT" && programContinue != "q" && programContinue != "Q" && programContinue != "Quit");

	std::cout << "\nHave a great day!! Goodbye!" << std::endl;

	if (std::cin.peek() == '\n')
		std::cin.ignore();
	std::cin.get();

	// WRITE INVENTORY CHANGES TO MY_RIDES.CSV FILE
	rides.writeFile("my_rides.csv");
	return 0;
}

// FUNCTION WILL CHECK IS STRING OF INT TYPE.
bool checkIfStringIsInt(std::string stringToCheck)
{
	for (int i = 0; i < stringToCheck.length(); i++)
	{
		if (isdigit(stringToCheck[i]))
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
