/*
Program Info
Name: JUSTIN STRELKA
Creation Date: 10/1/2018
Program Name: FIELD.H (BIRDAPP)
Description: FIELD CLASS DECLARATION
Version: 10/20/2018
Sources: C++ DATA STRUCTURES/ CPLUSPLUS.COM
*/

// MACRO GUARD
#ifndef FIELD_H
#define FIELD_H

// INCLUDE LIBRARIES
#include <string>
#include <fstream>   // ifstream
#include <iostream>  // istream

// NAMESPACE
namespace strelka_bird_1
{
	// Field (sub) is a string (super)
	class Field : public std::string //field is a string. W/ public inheritance so all string funcs are available. though constructors are not inherited
	{
	public:
		// constructors
		Field(); // default  constructor: Field address;
		Field(std::string& str);
		Field(const char* cStr);

		//new features of field not found in string.

		// split function will parse string on each comma found into an array.
		std::string* split(char delimiter = ',');
		// function will capitalize all of input string.
		std::string strToUpper(std::string& inputString);
		// fucntion will make all of input string lower case.
		std::string strToLower(std::string& inputString);

		// fucntion will return the size of the field array.
		int getArraySize() const { return arraySize; }

	private:

		int arraySize;
	};

	// istream operartor >> for field
	std::istream& operator>>(std::istream& is, Field & fld);
	// ifstream operartor >> for field
	std::ifstream& operator>>(std::ifstream& ifs, Field & fld);
}
#endif
