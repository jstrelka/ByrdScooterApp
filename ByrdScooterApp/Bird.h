/*
Program Info
Name: JUSTIN STRELKA
CSC 161-Section: 001 Fa18
Creation Date: 9/4/2018
Program Name: BIRD.H (BIRDAPP)
Description: BIRD CLASS DECLARATION
Version: 10/20/2018
Sources: C++ DATA STRUCTURES/ CPLUSPLUS.COM
*/

/*
FILE: BIRD.H
CLASS PROVIDED: Bird (PART OF THE NAMESPACE strelka_bird_1)

CONSTANTS:

ACTIVATION_AMT: used to set initial activation cost of Bird
CHARGE_PER_MIN: used to set the charge per minute of bird use

CONSTRUCTORS:

//DEFAULT CONSTRUCTOR
Bird(int rideLengthIn = 0,
double rideAmtIn = 0.0, int idIn = 0,
int batteryChargeIn = 0, double latitudeIn = 0.0,
double longitudeIn = 0.0)
POSTCONDITION: Bird class is initiated and member variables are set
to default. startTime and endTime call DateTime default
constructor.

// OTHER CONSTRUCTORS
Bird(int idIn,
double rideAmtIn = 0.0,
int rideLengthIn = 0);

Bird(double latitudeIn, double longitudeIn,
int idIn, double rideAmtIn = 0.0,
int rideLengthIn = 0);

MODIFICATION MEMBER FUNCTIONS:

SETTERS:
void setStartDate(int startMonthIn, int startDayIn,
int startYearIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of startTime month, day, year will be set to the
values going into the function.
void setEndDate(int endMonthIn, int endDayIn,
int endYearIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of endTime month, day, year will be set to the
values going into the function.
bool setStartMonth(int startMonthIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of startTime month will be set to the
value going into the function. (True if successful)
bool setEndMonth(int endMonthIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of endTime month will be set to the
value going into the function. (True if successful)
bool setStartDay(int startDayIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of startTime day will be set to the
value going into the function. (True if successful)
bool setEndDay(int endDayIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of endTime day will be set to the
value going into the function. (True if successful)
bool setStartYear(int startYearIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of startTime year will be set to the
value going into the function. (True if successful)
bool setEndYear(int endYearIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of endTime year will be set to the
value going into the function. (True if successful)
void setStartTime(int startHourIn, int startMinuteIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of startTime hour, minute will be set to the
values going into the function.
void setEndTime(int endHourIn, int endMinuteIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of endTime hour, minute will be set to the
values going into the function.
bool setStartHour(int startHourIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of startTime hour will be set to the
value going into the function. (True if successful)
bool setEndHour(int endHourIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of endTime hour will be set to the
value going into the function. (True if successful)
bool setStartMinute(int startMinuteIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of startTime minute will be set to the
value going into the function. (True if successful)
bool setEndMinute(int endMinuteIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of endTime minute will be set to the
value going into the function. (True if successful)
void setRideLength(int rideLengthIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of rideLength will be set to the value
input into the function. ***(INPUT MUST BE IN MINUTES)***
void setRideAmt(double rideAmtIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of rideAmt will be set to the value
input into the function. ***(INPUT MUST BE IN DOLLARS)***
void setId(int idIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of ID will be set to the value
input into the function.
bool prepBatteryCharge(std::string batteryChargeIn);
PRECONDITION: Bird class initialized and batteryCharge data obtained.
POSTCONDITION: Input data for batteryCharge will be checked for int value
and returned as an int.
bool setBatteryCharge(int batteryChargeIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of batteryCharge will be set to the value
input into the function.
bool setLatitude(double latitudeIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of birdLatitude will be set to the value
input into the function. ***(INPUT IN LATITUDE DEGREES)***
bool setLongitude(double longitudeIn);
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of birdLongitude will be set to the value
input into the function. ***(INPUT IN LONGITUDE DEGREES)***

COSTANT MEMBER FUNCTIONS

GETTERS:
DateTime getStartTime() const
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of startTime will be returned.
DateTime getEndTime() const
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of endTime will be returned.
double getRideLength() const
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of rideLength will be returned.
double getRideAmt() const
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of rideAmt will be returned.
int getId() const
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of id will be returned.
int getBatteryCharge() const
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of batteryCharge will be returned.
double getLatitude() const
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of birdLatitude will be returned.
double getLongitude() const
PRECONDITION: Bird class initialized.
POSTCONDITION: The value of birdLongitude will be returned.

OTHER MEMBER FUNCS:
double calculateRideAmt();
PRECONDITION: Bird class initialized.
POSTCONDITION: The cost of the bird ride will be returned in ***DOLLARS***.

int calculateRideLength();
PRECONDITION: Bird class initialized.
POSTCONDITION: The length of of the bird ride will be returned in ***MINUTES***.

int createId();
PRECONDITION: Bird class initialized.
POSTCONDITION: The random id between 0 and ***desired range*** will be created.
***Note change value following % modolus to set top end of desired range.***

bool checkIfDateIsInt(std::string dateToCheck, char dateDelimiter);
PRECONDITION: Date check if date is int instance must be initiated.
POSTCONDITION: Bool condition of if date string is int will be returned.
bool checkDateLength(std::string dateToCheck);
PRECONDITION: Date check date string length instance must be initiated.
POSTCONDITION: Bool condition of if date string is correct length will be returned.
bool parseDateString(std::string dateToParse, char dateDelimiter, int& monthOut, int& dayOut, int& yearOut);
PRECONDITION: Date parse date string instance must be initiated.
POSTCONDITION: Bool condition of if date string was parsed properly will be returned.
bool checkIfTimeIsInt(std::string timeToCheck, char timeDelimiter);
PRECONDITION: Time check if time is int instance must be initiated.
POSTCONDITION: Bool condition of if time string is int will be returned.
bool checkTimeLength(std::string timeToCheck);
PRECONDITION: Time check time string length instance must be initiated.
POSTCONDITION: Bool condition of if time string is correct length will be returned.
bool parseTimeString(std::string timeToParse, char timeDelimiter, int& hourOut, int& minuteOUt);
PRECONDITION: Time parse time string instance must be initiated.
POSTCONDITION: Bool condition of if time string was parsed properly will be returned.
bool checkIfStringIsInt(std::string stringToCheck);
PRECONDITION: String check if string is int instance must be initiated.
POSTCONDITION: Bool condition of if string is int will be returned.
bool checkIfLocationIsInt(std::string locationToCheck, char locationDelimiter);
PRECONDITION: Location check if location string is int instance must be initiated.
POSTCONDITION: Bool condition of if location string is int will be returned.
bool parseLocationString(std::string locationToParse, char locatonDelimiter, double& latitudeOut, double& longitudeOut);
PRECONDITION: Location parse location string instance must be initiated.
POSTCONDITION: Bool condition of if location string was parsed properly will be returned.

std::string toString() const;
PRECONDITION: Bird class initialized.
POSTCONDITION: The bird class data variables will be put into string formatt for user viewing
purposes.

std::string toFileString() const;
PRECONDITION: Bird class initialized.
POSTCONDITION: The bird class data variables will be put into file formatting for file writting
purposes (COMMA DELIMITED).

ASSIGNMENT OPERATOR
Bird operator=(const Bird& birdTmp);
PRECONDITION: Bird object initialized and "=" called.
POSTCONDITION: Invoking Bird of "=" operator will be an exact replica
of argument Bird.

FRIEND FUNCS

friend bool operator==(const Bird& compareBird,	const Bird& dataBird);
PRECONDITION: Bird object initialized and "==" called.
POSTCONDITION: Invoking Bird of "==" operator will be compared to
argument Bird. True or false will be returned accordingly.

friend bool operator==(const int compareInt, const Bird& dataBird);
PRECONDITION: Int value initialized and "==" called.
POSTCONDITION: Invoking int of "==" operator will be compared to
argument Bird unique identifier. True or false will be returned accordingly.

friend bool operator!=(const Bird& compareBird, const Bird& dataBird);
PRECONDITION: Bird object initialized and "!=" called.
POSTCONDITION: Invoking Bird of "!=" operator will be compared to
argument Bird. True or false will be returned accordingly.

friend std::ostream& operator<<(std::ostream& os, const Bird& birdTmp);
PRECONDITION: Bird object initialized and "<<" called.
POSTCONDITION: Invoking Bird of "<<" operator will be formated into user output.

friend std::ofstream& operator<<(std::ofstream& ofs, Bird& birdTmp);
PRECONDITION: Bird object initialized and "<<" called.
POSTCONDITION: Invoking Bird of "<<" operator will be formatted into file output.
(COMMA DELIMITED)

friend std::istream& operator>>(std::istream& is, Bird& birdTmp);
PRECONDITION: Bird object initialized and ">>" called.
POSTCONDITION: Invoking Bird of ">>" operator will recieve input from the console to
set private member variables.

friend std::ifstream& operator>>(std::ifstream& ifs, Bird& birdTmp);
PRECONDITION: Bird object initialized and ">>" called.
POSTCONDITION: Invoking Bird of ">>" operator will receive input from comma delimited
file to set private member variables.
*/

// MACRO GUARD BEGIN
#ifndef BIRD_H
#define BIRD_H

// INCLUDE LIBRARIES
#include <string>
#include <iostream>
#include "DateTime.h"
#include "Field.h"
#include <stdlib.h>
#include <stdio.h>

// DEFINE CONSTANTS FOR RIDE COST CALCULATIONS
#define ACTIVATION_AMT 1.0
#define CHARGE_PER_MIN .15

// NAMESPACE
namespace strelka_bird_1
{
	// DEFINE BIRD CLASS
	class Bird
	{
		//PUBLIC MEMBER FUNCS
	public:
		//CONSTRUCTORS
		//DEFAULT CONSTRUCTOR
		Bird(int rideLengthIn = 0,
			double rideAmtIn = 0.0, int idIn = 0,
			int batteryChargeIn = 0, double latitudeIn = 0.0,
			double longitudeIn = 0.0);

		Bird(int idIn,
			double rideAmtIn = 0.0,
			int rideLengthIn = 0);

		Bird(double latitudeIn, double longitudeIn,
			int idIn, double rideAmtIn = 0.0,
			int rideLengthIn = 0);

		// SETTERS
		bool setStartDate(std::string dateIn);
		bool setEndDate(std::string dateIn);
		bool setStartMonth(int startMonthIn);
		bool setEndMonth(int endMonthIn);
		bool setStartDay(int startDayIn);
		bool setEndDay(int endDayIn);
		bool setStartYear(int startYearIn);
		bool setEndYear(int endYearIn);
		bool setStartTime(std::string timeIn);
		bool setEndTime(std::string timeIn);
		bool setStartHour(int startHourIn);
		bool setEndHour(int endHourIn);
		bool setStartMinute(int startMinuteIn);
		bool setEndMinute(int endMinuteIn);
		void setRideLength(int rideLengthIn);
		void setRideAmt(double rideAmtIn);
		void setId(int idIn);
		bool prepBatteryCharge(std::string batteryChargeIn);
		bool setBatteryCharge(int batteryChargeIn);
		bool setLocation(std::string locationIn);
		bool setLatitude(double latitudeIn);
		bool setLongitude(double longitudeIn);


		// GETTERS
		DateTime getStartTime() const { return startTime; }
		DateTime getEndTime() const { return endTime; }
		double getRideLength() const { return  rideLength; }
		double getRideAmt() const { return rideAmt; }
		int getId() const { return id; }
		int getBatteryCharge() const { return batteryCharge; }
		double getLatitude() const { return latitude; }
		double getLongitude() const { return longitude; }

		// OTHER MEMBER FUNCS
		double calculateRideAmt();
		int calculateRideLength();
		int createId();
		bool checkIfDateIsInt(std::string dateToCheck, char dateDelimiter);
		bool checkDateLength(std::string dateToCheck);
		bool parseDateString(std::string dateToParse, char dateDelimiter, int& monthOut, int& dayOut, int& yearOut);
		bool checkIfTimeIsInt(std::string timeToCheck, char timeDelimiter);
		bool checkTimeLength(std::string timeToCheck);
		bool parseTimeString(std::string timeToParse, char timeDelimiter, int& hourOut, int& minuteOUt);
		bool checkIfStringIsInt(std::string stringToCheck);
		bool checkIfLocationIsInt(std::string locationToCheck, char locationDelimiter);
		bool parseLocationString(std::string locationToParse, char locatonDelimiter, double& latitudeOut, double& longitudeOut);




		// CONVERT OBJECT TO STRING FOR USER PURPOSES
		std::string toString() const;

		// CONVERT OBJECT TO STRING FOR FILE WRITTING PURPOSES
		std::string toFileString() const;

		// BIRD ASSIGNMENT OPERATOR
		Bird operator=(const Bird& birdTmp);

		// FRIEND FUNCS		
		// BIRD TO BIRD EQUALITY
		friend bool operator==(const Bird& compareBird, const Bird& dataBird);

		// ID INT TO BIRD EQUALITY
		friend bool operator==(const int compareInt, const Bird& dataBird);

		// BIRD TO BIRD INEQUALITY
		friend bool operator!=(const Bird& compareBird, const Bird& dataBird);

		// BIRD COMPARISON OPERATOR (>) GREATER THAN
		friend bool operator>(const Bird& compareBird,
			const Bird& dataBird);

		// BIRD COMPARISON OPERATOR (>=) GREATER THAN OR EQUAL TO
		friend bool operator>=(const Bird& compareBird,
			const Bird& dataBird);

		// BIRD COMPARISON OPERATOR (>) LESS THAN
		friend bool operator<(const Bird& compareBird,
			const Bird& dataBird);

		// BIRD COMPARISON OPERATOR (<=) LESS THAN OR EQUAL TO
		friend bool operator<=(const Bird& compareBird,
			const Bird& dataBird);

		// USING OS STREAM WITH A BIRD << OPERATOR
		friend std::ostream& operator<<(std::ostream& os, const Bird& birdTmp);

		// USING OF STREAM WITH A BIRD << OPERATOR
		friend std::ofstream& operator<<(std::ofstream& ofs, Bird& birdTmp);

		// USING IS STREAM WITH A BIRD >> OPERATOR
		friend std::istream& operator>>(std::istream& is, Bird& birdTmp);

		// USING IF STREAM WITH A BIRD >> OPERATOR
		friend std::ifstream& operator>>(std::ifstream& ifs, Bird& birdTmp);

		// PRIVATE DATA MEMBERS
	private:
		DateTime startTime; // CALLS DEFAULT CONSTRUCTOR "DateTime"
		DateTime endTime; // CALLS DEFAULT CONSTRUCTOR "DateTime"
		int rideLength;
		double rideAmt;
		int id;
		int batteryCharge;
		double latitude;
		double longitude;
		const char dateDelimiter = '/';
		const char timeDelimiter = ':';
		const char locationDelimiter = '/';
	};
}
// END OF MACROGUARD
#endif