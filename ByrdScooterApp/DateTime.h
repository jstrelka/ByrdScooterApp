/*
Program Info
Name: JUSTIN STRELKA
CSC 161-Section: 001 Fa18
Creation Date: 9/4/2018
Program Name: DATETIME.H (BIRDAPP)
Description: DATETIME CLASS DECLARATION
Version: 10/20/2018
Sources: C++ DATA STRUCTURES/ CPLUSPLUS.COM
*/

/*
FILE: DATETIME.H
CLASS PROVIDED: DateTime (PART OF THE NAMESPACE strelka_bird_1)

CONSTANTS:
NONE

CONSTRUCTORS:

DEFAULT CONSTRUCTOR:
DateTime(int monthIn = 1, int dayIn = 1,
int yearIn = 2000, int hourIn = 0,
int minuteIn = 0);
POSTCONDITION: DateTime class is initiated and member variables are set to default.

OTHER CONSTRUCTORS:
DateTime(int hourIn);

DateTime(int hourIn, int minuteIn);

DateTime(int monthIn, int dayIn, int yearIn);

MODIFICATION MEMBER FUNCTIONS:

SETTERS:
void setDate(int monthIn, int dayIn, int yearIn);
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object month, day, year will be set to input.
void setTime(int hourIn, int minuteIn);
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object hour, minute will be set to input.
bool setMonth(int monthIn);
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object month will be set to input. (True if sucessful)
bool setDay(int dayIn);
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object day will be set to input. (True if sucessful)
bool setYear(int yearIn);
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object year will be set to input. (True if sucessful)
bool setHour(int hourIn);
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object hour will be set to input. (True if sucessful)
bool setMinute(int minuteIn);
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object minute will be set to input. (True if sucessful)

CONSTANT MEMBER FUNCS:

GETTERS:
int getMonth() const
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object month will be returned.
int getDay() const
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object day will be returned.
int getYear() const
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object year will be returned.
int getHour() const
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object hour will be returned.
int getMinute() const
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object minute will be returned.

OTHER MEMBER FUNCS:

std::string toString() const;
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object will be put into string formatt for user viewing purposes.

std::string toFileString() const;
PRECONDITION: DateTime class initialized.
POSTCONDITION: DateTime object will be put into string formatt for file building purposes (COMMA DELIMITED).

bool readFile(std::string fileName);
PRECONDITION: DateTime class initialized and infile variable initialized.
POSTCONDITION: A DateTime object is returned containing the information for each field from the infile.

FRIEND FUNCS
friend bool operator==(const DateTime& compareTime,
const DateTime& dataTime);
PRECONDITION: A DateTime equality comparison must be initiated.
POSTCONDITION: Function returns true or false as to whether two DateTimes compared are equal.

friend bool operator!=(const DateTime& compareTime,
const DateTime& dataTime);
PRECONDITION: A DateTime in-equality comparison must be initiated.
POSTCONDITION: Function returns true or false as to whether two DateTimes compared are in-equal.

friend bool operator>(const DateTime& compareTime,
const DateTime& dataTime);
PRECONDITION: A DateTime greater than a DateTime comparison must be initiated.
POSTCONDITION: Function returns true or false as to whether a DataTime is greater than another.

friend bool operator>=(const DateTime& compareTime,
const DateTime& dataTime);
PRECONDITION: A DateTime greater than or equal to another DateTime comparison must be initiated.
POSTCONDITION: Function returns true or false as to whether a DataTime is greater or equal to another.

friend bool operator<(const DateTime& compareTime,
const DateTime& dataTime);
PRECONDITION: A DateTime less than a DateTime comparison must be initiated.
POSTCONDITION: Function returns true or false as to whether a DataTime is less than another.

friend bool operator<=(const DateTime& compareTime,
const DateTime& dataTime);
PRECONDITION: A DateTime less than or equal to another DateTime comparison must be initiated.
POSTCONDITION: Function returns true or false as to whether a DataTime is less than or equal to another.

friend int operator-(const DateTime compareTime,
const DateTime dataTime);
PRECONDITION: A difference of DateTimes must be initiated.
POSTCONDITION: Function returns the value in minutes of the difference of DateTime.

friend int operator+(const DateTime compareTime,
const DateTime dataTime);
PRECONDITION: A sum of DateTimes must be initiated.
POSTCONDITION: Function returns the value in minutes of the sum of two DateTimes.

friend std::ostream& operator<<(std::ostream& os, DateTime& dateTmp);
PRECONDITION: An ostream of DateTime must be initiated.
POSTCONDITION: Function returns contents of a DateTime in user format.

friend std::ofstream& operator<<(std::ofstream& ofs, DateTime& dateTmp);
PRECONDITION: An ofstream of DateTime must be initiated.
POSTCONDITION: Function returns contents of a DateTime in file format (COMMA DELIMITED).

friend std::istream& operator>>(std::istream& is, DateTime& dateTmp);
PRECONDITION: An istream of DateTime must be initiated.
POSTCONDITION: Function places user input into DateTime format.

friend std::ifstream & operator>>(std::ifstream & ifs, DateTime & dateTmp);
PRECONDITION: An ifstream of DateTime must be initiated.
POSTCONDITION: Function places contents of a file (COMMA DELIMITED) into DateTime format.
*/

// MACRO GUARD
#ifndef DATETIME_H
#define DATETIME_H

// #INCLUDE LIBRARIES GO HERE
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Field.h"

// NAMESPACE
namespace strelka_bird_1
{
	//DEFINE DATETIME CLASS
	class DateTime
	{
		// PUBLIC MEMBER FUNCTIONS
	public:
		// CONSTRUCTORS
		DateTime(int monthIn = 1, int dayIn = 1,
			int yearIn = 2000, int hourIn = 0,
			int minuteIn = 0); //DEFAULT CONSTRUCTOR

		DateTime(int hourIn);

		DateTime(int hourIn, int minuteIn);

		DateTime(int monthIn, int dayIn, int yearIn);

		// SETTERS
		void setDate(int monthIn, int dayIn, int yearIn);
		void setTime(int hourIn, int minuteIn);
		bool setMonth(int monthIn);
		bool setDay(int dayIn);
		bool setYear(int yearIn);
		bool setHour(int hourIn);
		bool setMinute(int minuteIn);

		// GETTERS
		int getMonth() const { return month; }
		int getDay() const { return day; }
		int getYear() const { return year; }
		int getHour() const { return hour; }
		int getMinute() const { return minute; }

		//OTHER MEMBER FUNCTIONS
		// CONVERT OBJECT TO STRING FOR USER PURPOSES.
		std::string toString() const;

		// CONVERT OBJECT TO STRING FOR FILE WRITING PURPOSES (COMMA DELIMITED).
		std::string toFileString() const;

		// READ DATA FROM FILE (COMMA DELIMITED) AND FILL DATETIME
		bool readFile(std::string fileName);

		// FRIEND FUNCS
		// DATETIME COMPARISON OPERATOR EQUALITY
		friend bool operator==(const DateTime& compareTime,
			const DateTime& dataTime);

		// DATETIME COMPARISON OPERATOR NOT EQUAL
		friend bool operator!=(const DateTime& compareTime,
			const DateTime& dataTime);

		// DATETIME COMPARISON OPERATOR (>) GREATER THAN
		friend bool operator>(const DateTime& compareTime,
			const DateTime& dataTime);

		// DATETIME COMPARISON OPERATOR (>=) GREATER THAN OR EQUAL TO
		friend bool operator>=(const DateTime& compareTime,
			const DateTime& dataTime);

		// DATETIME COMPARISON OPERATOR (>) LESS THAN
		friend bool operator<(const DateTime& compareTime,
			const DateTime& dataTime);

		// DATETIME COMPARISON OPERATOR (<=) LESS THAN OR EQUAL TO
		friend bool operator<=(const DateTime& compareTime,
			const DateTime& dataTime);

		// DATETIME ARITHMATIC OPERATOR (-) DIFFERENCE
		friend int operator-(const DateTime compareTime,
			const DateTime dataTime);

		// DATETIME ARITHMATIC OPERATOR (+) SUM
		friend int operator+(const DateTime compareTime,
			const DateTime dataTime);

		// USING OS STREAM WITH A DATETIME << OPERATOR
		friend std::ostream& operator<<(std::ostream& os, DateTime& dateTmp);

		// USING OF STREAM WITH A DATETIME << OPERATOR
		friend std::ofstream& operator<<(std::ofstream& ofs, DateTime& dateTmp);

		// USING IS STREAM WITH A DATETIME >> OPERATOR
		friend std::istream& operator>>(std::istream& is, DateTime& dateTmp);

		// USING If STREAM WITH A DATETIME >> OPERATOR
		friend std::ifstream & operator>>(std::ifstream & ifs, DateTime & dateTmp);

		// PRIVATE DATA MEMBERS
	private:
		int month;
		int day;
		int year;
		int hour;
		int minute;
	};
}
// END OF MACRO GUARD
#endif