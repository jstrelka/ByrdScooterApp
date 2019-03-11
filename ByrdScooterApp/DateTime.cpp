/*
Program Info
Name: JUSTIN STRELKA
CSC 161-Section: 001 Fa18
Creation Date: 9/4/2018
Program Name: DATETIME.CPP (BIRDAPP)
Description: DATETIME CLASS DEFINITION
Version: 10/20/2018
Sources: C++ DATA STRUCTURES/ CPLUSPLUS.COM
*/

// INCLUDE DATETIME HEADER FILE
#include "DateTime.h" 

// NAMESPACE
namespace strelka_bird_1
{
	//CONSTRUCTORS
	// DEFAULT CONSTRUCTOR
	DateTime::DateTime(int monthIn, int dayIn, int yearIn,
		int hourIn, int minuteIn)
	{
		// CALL SETTER FOR CONSTRUCTOR
		setDate(monthIn, dayIn, yearIn);
		setTime(hourIn, minuteIn);
	}

	DateTime::DateTime(int hourIn)
	{
		// CALL SETTER FOR CONSTRUCTOR
		setHour(hourIn);
	}

	DateTime::DateTime(int hourIn, int minuteIn)
	{
		// CALL SETTERS FOR CONSTRUCTOR
		setTime(hourIn, minuteIn);
	}

	DateTime::DateTime(int monthIn, int dayIn, int yearIn)
	{
		// CALL SETTERS FOR CONSTRUCTOR
		setDate(monthIn, dayIn, yearIn);
	}

	// SETTERS
	// VOID SET DATE
	void DateTime::setDate(int monthIn, int dayIn, int yearIn)
	{
		setMonth(monthIn);
		setDay(dayIn);
		setYear(yearIn);
	}

	// VOID SET TIME
	void DateTime::setTime(int hourIn, int minuteIn)
	{
		setHour(hourIn);
		setMinute(minuteIn);
	}

	// USE BOOL TO SET EACH INDIVIDUAL PRIVATE VARIABLE
	// SET MONTH
	bool DateTime::setMonth(int monthIn)
	{
		if (monthIn >= 1 && monthIn <= 12)
		{
			month = monthIn;
			return true;
		}
		else
			return false;
	}

	// SET DAY
	bool DateTime::setDay(int dayIn)
	{
		if (dayIn >= 1 && dayIn <= 31)
		{
			day = dayIn;
			return true;
		}
		else
			return false;
	}

	// SET YEAR
	bool DateTime::setYear(int yearIn)
	{
		if (yearIn >= 2000)
		{
			year = yearIn;
			return true;
		}
		else
			return false;
	}

	// SET HOUR
	bool DateTime::setHour(int hourIn)
	{
		if (hourIn >= 0 && hourIn <= 24)
		{
			hour = hourIn;
			return true;
		}
		else
			return false;
	}

	// SET MINUTE
	bool DateTime::setMinute(int minuteIn)
	{
		if (minuteIn >= 0 && minuteIn < 60)
		{
			minute = minuteIn;
			return true;
		}
		else
			return false;
	}

	// OTHER MEMBER FUNCS
	// TO STRING FOR USER PURPOSES
	std::string DateTime::toString() const
	{
		std::string userFormat;

		userFormat = std::to_string(month) + "/" +
			std::to_string(day) + "/" +
			std::to_string(year) + " " +
			std::to_string(hour) + ":" +
			std::to_string(minute);

		return userFormat;
	}

	// TO STRING FOR FILE WRITING PURPOSES (COMMA DELIMITED)
	std::string DateTime::toFileString() const
	{
		std::string fileFormat;

		fileFormat = std::to_string(month) + "," +
			std::to_string(day) + "," +
			std::to_string(year) + "," +
			std::to_string(hour) + "," +
			std::to_string(minute) + ",";

		return fileFormat;
	}

	// READ FROM FILE TO FILL ARRAY (COMMA DELIMITED)
	bool DateTime::readFile(std::string fileName)
	{
		std::ifstream inFile;
		inFile.open(fileName);
		// CHECK FILE OPEN
		if (!inFile)
		{
			return false;
		}
		else if (inFile)
		{
			std::string line_string;

			// TEMPORARY PLACE HOLDERS FOR EACH FIELD NAME
			DateTime tempDateTime;// CALLS DEFAULT CONSTRUCTOR

								  // READ LINES FROM FILE COMMA DELIMITED
								  // SET EACH DATETIME FIELD EQUAL TO CORRESPONDING FILE LINE READ.
			std::getline(inFile, line_string, ',');
			tempDateTime.setMonth(std::stoi(line_string));
			std::getline(inFile, line_string, ',');
			tempDateTime.setDay(std::stoi(line_string));
			std::getline(inFile, line_string, ',');
			tempDateTime.setYear(std::stoi(line_string));
			std::getline(inFile, line_string, ',');
			tempDateTime.setHour(std::stoi(line_string));
			std::getline(inFile, line_string, ',');
			tempDateTime.setMinute(std::stoi(line_string));
		}
		// CLOSE FILE AFTER EOF IS FOUND
		inFile.close();
		return true;
	}

	// DATE TIME COMPARISON OPERARTOR DATETIME TO DATETIME EQUALITY
	bool operator==(const DateTime& compareTime,
		const DateTime& dataTime)
	{
		if (compareTime.month == dataTime.month &&
			compareTime.day == dataTime.day &&
			compareTime.year == dataTime.year &&
			compareTime.hour == dataTime.hour &&
			compareTime.minute == dataTime.minute)
			return true;
		return false;
	}

	// DATE TIME COMPARISON OPERARTOR DATETIME TO DATETIME IN-EQUALITY
	bool operator!=(const DateTime & compareTime, const DateTime & dataTime)
	{
		return (!(compareTime == dataTime));
	}

	// DATE TIME COMPARISON OPERARTOR DATETIME TO DATETIME GREATER THAN.
	bool operator>(const DateTime & compareTime, const DateTime & dataTime)
	{
		if (compareTime.year > dataTime.year)
		{
			return true;
		}
		else if (compareTime.year == dataTime.year)
		{
			if (compareTime.month > dataTime.month)
			{
				return true;
			}
			else if (compareTime.month == dataTime.month)
			{
				if (compareTime.day > dataTime.day)
				{
					return true;
				}
				else if (compareTime.day == dataTime.day)
				{
					if (compareTime.hour > dataTime.hour)
					{
						return true;
					}
					else if (compareTime.hour == dataTime.hour)
					{
						if (compareTime.minute > dataTime.minute)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	// DATE TIME COMPARISON OPERARTOR DATETIME TO DATETIME GREATER THAN OR EQUAL TO.
	bool operator>=(const DateTime & compareTime, const DateTime & dataTime)
	{
		return (compareTime > dataTime || compareTime == dataTime);
	}

	// DATE TIME COMPARISON OPERARTOR DATETIME TO DATETIME LESS THAN.
	bool operator<(const DateTime & compareTime, const DateTime & dataTime)
	{
		return (!(compareTime > dataTime));
	}

	// DATE TIME COMPARISON OPERARTOR DATETIME TO DATETIME LESS THAN OR EQUAL TO.
	bool operator<=(const DateTime & compareTime, const DateTime & dataTime)
	{
		return (compareTime < dataTime || compareTime == dataTime);
	}

	// DATE TIME DIFFERENCE OPERARTOR DATETIME TO DATETIME DIFFERENCE.
	int operator-(const DateTime compareTime, const DateTime dataTime)
	{
		int totalTime = 0;
		totalTime = (((compareTime.getYear() - dataTime.getYear()) * 365 * 24 * 60) + ((compareTime.getMonth() - dataTime.getMonth()) * 30 * 24 * 60) +
			((compareTime.getDay() - dataTime.getDay()) * 24 * 60) + ((compareTime.getHour() - dataTime.getHour()) * 60) + (compareTime.getMinute() - dataTime.getMinute()));
		return totalTime;
	}

	// DATE TIME SUM OPERATOR DATETIME TO DATETIME SUM. 
	int operator+(const DateTime compareTime, const DateTime dataTime)
	{
		int totalTime = 0;
		totalTime = (((compareTime.getYear() + dataTime.getYear()) * 365 * 24 * 60) + ((compareTime.getMonth() + dataTime.getMonth()) * 30 * 24 * 60) +
			((compareTime.getDay() + dataTime.getDay()) * 24 * 60) + (compareTime.getMinute() + dataTime.getMinute()));
		return totalTime;
	}

	// OSSTREAM OPERATOR FOR << DateTime
	std::ostream & operator<<(std::ostream & os, DateTime & dateTmp)
	{
		os << dateTmp.toString();
		return os;
	}

	// OFSTREAM OPERATOR FOR << DateTime
	std::ofstream & operator<<(std::ofstream & ofs, DateTime & dateTmp)
	{
		ofs << dateTmp.toFileString();
		return ofs;
	}

	// ISSTREAM OPERATOR FOR >> DateTime
	std::istream & operator>>(std::istream & is, DateTime & dateTmp)
	{
		int monthIn = 0;
		int dayIn = 0;
		int yearIn = 0;
		int hourIn = 0;
		int minuteIn = 0;
		std::cout << "Enter month: ";
		is >> monthIn;
		dateTmp.setMonth(monthIn);

		std::cout << "Enter day: ";
		is >> dayIn;
		dateTmp.setDay(dayIn);

		std::cout << "Enter year: ";
		is >> yearIn;
		dateTmp.setYear(yearIn);

		std::cout << "Enter hour: ";
		is >> hourIn;
		dateTmp.setMonth(hourIn);

		std::cout << "Enter minute: ";
		is >> minuteIn;
		dateTmp.setMinute(minuteIn);
		return is;
	}

	// IFSTREAM OPERATOR FOR >> DateTime
	std::ifstream & operator>>(std::ifstream & ifs, DateTime & dateTmp)
	{
		// INITIALIZE AND SET FIELD POINTERS AND VARIABLES
		std::string line_string;
		ifs >> line_string;
		Field field(line_string);
		std::string* fields = field.split(',');

		// CHECK TO ENSURE ALL VALUES OF DATETIME ARE ACCOUNTED FOR TO PREVENT CORRUPTED DATA.
		if (field.getArraySize() == 5)
		{
			// IF ALL FIELDS ARE ACCOUNTED FOR SET DATETIME PRIVATE DATA VARIABLES BY SETTER CALLS
			dateTmp.setMonth(std::stoi(fields[0]));
			dateTmp.setDay(std::stoi(fields[1]));
			dateTmp.setYear(std::stoi(fields[2]));
			dateTmp.setHour(std::stoi(fields[3]));
			dateTmp.setMinute(std::stoi(fields[4]));
		}
		// DELETE FIELDS ARRAY TO PREVENT DATA LEAKS
		delete[] fields;
		// SET FIELDS POINTER TO NULL
		fields = NULL;
		return ifs;
	}
}
