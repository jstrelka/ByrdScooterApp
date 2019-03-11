/*
Program Info
Name: JUSTIN STRELKA
CSC 161-Section: 001 Fa18
Creation Date: 10/1/2018
Program Name: FIELD.CPP (BIRDAPP)
Description: FIELD CLASS DEFINITION
Version: 10/20/2018
Sources: C++ DATA STRUCTURES/ CPLUSPLUS.COM
*/

// INCLUDE DIRECTIVES
#include "Field.h"

// NAMESPACE
namespace strelka_bird_1
{
	Field::Field() // default  constructor
		: std::string()  // calls the string default constructor
	{
		arraySize = 0;
	}
	Field::Field(std::string& str)
		: std::string(str) // calls the string copy constructor
	{
		arraySize = 0;
	}
	Field::Field(const char* cStr)
		: std::string(cStr)  // calls the constructor passes const char*
	{
		arraySize = 0;
	}

	// field split function will parse a string passed into seperate array fields on commas (or delimiter passed).
	std::string * Field::split(char delimiter)
	{
		int commaIndex = 0;
		arraySize = 1;
		std::string* tmpPtr = NULL;
		std::string tmp = *this;
		std::string* fields = new std::string[arraySize]; // creates array with 1 spot because of array size the * is a wild card
		int used = 0; // used is currently 0 because array is initialized but empty

		commaIndex = this->find(delimiter); // looks at the contents of the address pointed to.

		do
		{
			if (used >= arraySize) // if full - no more room DO THIS!!!
			{ // memory allocation at runtime
				arraySize++;
				tmpPtr = new std::string[arraySize];
				for (int i = 0; i < used; i++)
					tmpPtr[i] = fields[i];
				//copy (fields, fields + used, tmpPtr),
				delete[] fields;
				fields = tmpPtr;
			}
			fields[used++] = tmp.substr(0, commaIndex);
			tmp = tmp.erase(0, commaIndex + 1);
			commaIndex = tmp.find(delimiter);
		} while (commaIndex != std::string::npos);
		return fields;
	}

	// function will capitalize all of string passed to it. 
	std::string Field::strToUpper(std::string& inputString)
	{
		for (int i = 0; i < inputString.length(); i++)
		{
			if (inputString[i] <= 'z' && inputString[i] >= 'a')
			{
				inputString[i] -= 32;
			}
			else
			{
				continue;
			}
		}
		return inputString;
	}

	// function will cast to lower case all of string passed to it.
	std::string Field::strToLower(std::string & inputString)
	{
		for (int i = 0; i < inputString.length(); i++)
		{
			if (inputString[i] <= 'Z' && inputString[i] >= 'A')
			{
				inputString[i] += 32;
			}
			else
			{
				continue;
			}
		}
		return inputString;
	}

	// istream >> operator for field
	std::istream& operator>>(std::istream& is, Field & fld)
	{
		// get everything up untill the enter key is pressed
		if (is.peek() == '\n') // check to make sure a newline (enter key)
			is.ignore();       // from previous cin >>..; was not left in the stream
		getline(is, fld, '\n');  // can use getline because field is a string
		return is;
	}

	// ifstream operator for field
	std::ifstream& operator>>(std::ifstream& ifs, Field & fld)
	{
		if (ifs.peek() == '\n')
			ifs.ignore();
		getline(ifs, fld, ',');
		return ifs;
	}
}