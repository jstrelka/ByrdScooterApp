/*
Program Info
Name: JUSTIN STRELKA
CSC 161-Section: 001 Fa18
Creation Date: 9/4/2018
Program Name: BIRD.CPP (BIRDAPP)
Description: BIRD CLASS DEFINITION
Version: 10/20/2018
Sources: C++ DATA STRUCTURES/ CPLUSPLUS.COM
*/

// INCLUDE BIRD.H FILE
#include "Bird.h"

//NAMESPACE
namespace strelka_bird_1
{
	// CONSTRUCTORS
	// DEFAULT CONSTRUCTOR
	Bird::Bird(int rideLengthIn,
		double rideAmtIn, int idIn,
		int batteryChargeIn, double latitudeIn,
		double longitudeIn)
	{
		// CALL SETTERS FOR CONSTRUCTOR
		setRideLength(rideLengthIn);
		setRideAmt(rideAmtIn);
		setId(idIn);
		setBatteryCharge(batteryChargeIn);
		setLatitude(latitudeIn);
		setLongitude(longitudeIn);
	}

	Bird::Bird(int idIn, double rideAmtIn,
		int rideLengthIn)
	{
		// CALL SETTERS FOR CONSTRUCTOR
		setId(idIn);
		setRideAmt(rideAmtIn);
		setRideLength(rideLengthIn);
	}

	Bird::Bird(double latitudeIn, double longitudeIn,
		int idIn, double rideAmtIn,
		int rideLengthIn)
	{
		// CALL SETTERS FOR CONSTRUCTOR
		setLatitude(latitudeIn);
		setLongitude(longitudeIn);
		setId(idIn);
		setRideAmt(rideAmtIn);
		setRideLength(rideLengthIn);
	}

	// SETTERS
	// Set Bird StartTime date.
	// Function will check string for int. length and parse for setting.(month, day, year)
	bool Bird::setStartDate(std::string dateIn)
	{
		bool success = false;
		int month = 0;
		int day = 0;
		int year = 0;
		// CHECK IF START DATE STRING IS INT AND HAS 2 '/' DELIMITERS.
		success = checkIfDateIsInt(dateIn, dateDelimiter);
		if (success == true)
		{
			success = checkDateLength(dateIn);
			if (success == true)
			{
				success = parseDateString(dateIn, dateDelimiter, month, day, year);
				if (success == true)
				{
					success = setStartMonth(month);
					if (success == true)
					{
						success = setStartDay(day);
						if (success == true)
						{
							return setStartYear(year);
						}
						return false;
					}
					return false;
				}
				return false;
			}
			return false;
		}
		return false;
	}

	// VOID SET BIRD endTime DATE 
	// FUNCTION WILL CHECK DATE STRING FOR INT, LENGTH, AND PARSE INTO (MONTH, DAY, YEAR) FOR SETTING endTime DATE.
	bool Bird::setEndDate(std::string dateIn)
	{
		bool success = false;
		int month = 0;
		int day = 0;
		int year = 0;
		// CHECK IF START DATE STRING IS INT AND HAS 2 '/' DELIMITERS.
		success = checkIfDateIsInt(dateIn, dateDelimiter);
		if (success == true)
		{
			success = checkDateLength(dateIn);
			if (success == true)
			{
				success = parseDateString(dateIn, dateDelimiter, month, day, year);
				if (success == true)
				{
					success = setEndYear(year);
					if (success == true)
					{
						success = setEndMonth(month);
						if (success == true)
						{
							return setEndDay(day);
						}
						return false;
					}
					return false;
				}
				return false;
			}
			return false;
		}
		return false;
	}

	// USE BOOL TO SET INDIVIDUAL STARTTIME AND ENDTIME OBJECTS
	// SET STARTTIME MONTH
	bool Bird::setStartMonth(int startMonthIn)
	{
		return startTime.setMonth(startMonthIn);
	}

	// SET ENDTIME MONTH IF EQUAL TO OR POST STARTTIME DATE
	bool Bird::setEndMonth(int endMonthIn)
	{
		if (endTime.getYear() == startTime.getYear())
		{
			if (endMonthIn < startTime.getMonth())
			{
				return false;
			}
			else
				return endTime.setMonth(endMonthIn);
		}
		else
			return endTime.setMonth(endMonthIn);
	}

	// SET STARTTIME DAY
	bool Bird::setStartDay(int startDayIn)
	{
		return startTime.setDay(startDayIn);
	}

	// SET ENDTIME DAY IF EQUAL TO OR POST STARTTIME DATE
	bool Bird::setEndDay(int endDayIn)
	{
		if (endTime.getYear() == startTime.getYear())
		{
			if (endTime.getMonth() == startTime.getMonth())
			{
				if (endDayIn >= startTime.getDay())
				{
					return endTime.setDay(endDayIn);
				}
				else
					return false;
			}
			else
				return endTime.setDay(endDayIn);
		}
		else
			return endTime.setDay(endDayIn);
	}

	// SET STARTTIME YEAR
	bool Bird::setStartYear(int startYearIn)
	{
		return startTime.setYear(startYearIn);
	}

	// SET ENDTIME YEAR IF EQUAL TO OR POST STARTTIME DATE
	bool Bird::setEndYear(int endYearIn)
	{
		if (endYearIn < startTime.getYear())
			return false;
		else
			return endTime.setYear(endYearIn);
	}

	// VOID STARTTIME SETTER
	// FUNCTION WILL CHECK IS startTime TIME STRING IS INT, LENGTH, AND PARSE FOR SETTING startTime TIME.
	bool Bird::setStartTime(std::string timeIn)
	{
		int hour = 0;
		int minute = 0;
		bool success = false;
		// CHECK IF START TIME STRING IS INT AND HAS ':' DELIMITERS.
		success = checkIfTimeIsInt(timeIn, timeDelimiter);
		if (success == true)
		{
			success = checkTimeLength(timeIn);
			if (success == true)
			{
				success = parseTimeString(timeIn, timeDelimiter, hour, minute);
				if (success == true)
				{
					success = setStartHour(hour);
					if (success == true)
					{
						return setStartMinute(minute);
					}
					return false;
				}
				return false;
			}
			return false;
		}
		return false;
	}

	// VOID SET ENDTIME TIME
	// FUNCTION WILL CHECK IF endTime TIME STRING IS INT, LENGTH, AND PARSE FOR SETTING endTime TIME.
	bool Bird::setEndTime(std::string timeIn)
	{
		bool success = false;
		int hour = 0;
		int minute = 0;
		// CHECK IF START DATE STRING IS INT AND HAS 2 '/' DELIMITERS.
		success = checkIfTimeIsInt(timeIn, timeDelimiter);
		if (success == true)
		{
			success = checkTimeLength(timeIn);
			if (success == true)
			{
				success = parseTimeString(timeIn, timeDelimiter, hour, minute);
				if (success == true)
				{
					success = setEndHour(hour);
					if (success == true)
					{
						return setEndMinute(minute);
					}
					return false;
				}
				return false;
			}
			return false;
		}
		return false;
	}

	// SET STARTTIME HOUR
	bool Bird::setStartHour(int startHourIn)
	{
		return startTime.setHour(startHourIn);
	}

	// SET ENDTIME HOUR IF EQUAL TO OR POST STARTTIME DATE
	bool Bird::setEndHour(int endHourIn)
	{
		if (endTime.getYear() == startTime.getYear())
		{
			if (endTime.getMonth() == startTime.getMonth())
			{
				if (endTime.getDay() == startTime.getDay())
				{
					if (endHourIn < startTime.getHour())
					{
						return false;
					}
					else
						return endTime.setHour(endHourIn);
				}
				else
					return endTime.setHour(endHourIn);
			}
			else
				return endTime.setHour(endHourIn);
		}
		else
			return endTime.setHour(endHourIn);
	}

	// SET STARTTIME MINUTE
	bool Bird::setStartMinute(int startMinuteIn)
	{
		return startTime.setMinute(startMinuteIn);
	}

	// SET ENDTIME MINUTE IF EQUAL TO OR POST STARTTIME DATE
	bool Bird::setEndMinute(int endMinuteIn)
	{
		if (endTime.getYear() == startTime.getYear())
		{
			if (endTime.getMonth() == startTime.getMonth())
			{
				if (endTime.getDay() == startTime.getDay())
				{
					if (endTime.getHour() == startTime.getHour())
					{
						if (endMinuteIn < startTime.getMinute())
						{
							return false;
						}
						else
							return endTime.setMinute(endMinuteIn);
					}
					else
						return endTime.setMinute(endMinuteIn);
				}
				else
					return endTime.setMinute(endMinuteIn);
			}
			else
				return endTime.setMinute(endMinuteIn);
		}
		else
			return endTime.setMinute(endMinuteIn);
	}

	// SET RIDE LENGTH
	void Bird::setRideLength(int rideLengthIn)
	{
		if (rideLengthIn >= 0)
			rideLength = rideLengthIn;
	}

	// SET RIDE AMOUNT
	void Bird::setRideAmt(double rideAmtIn)
	{
		if (rideAmtIn >= 0)
			rideAmt = rideAmtIn;
	}

	// SET ID
	void Bird::setId(int idIn)
	{
		if (idIn >= 0)
			id = idIn;
	}

	// FUNCTION WILL ENSURE BATTERYSTRING IN IS INT AND RETURN STRING VALUE AS AN INT.
	bool Bird::prepBatteryCharge(std::string batteryChargeIn)
	{
		bool success = false;
		success = checkIfStringIsInt(batteryChargeIn);
		if (success == true)
		{
			return setBatteryCharge(std::stoi(batteryChargeIn));
		}
		else
			return false;
	}

	// SETTER FOR BATTERYCHARGE
	bool Bird::setBatteryCharge(int batteryChargeIn)
	{
		if (batteryChargeIn >= 0 && batteryChargeIn <= 100)
		{
			batteryCharge = batteryChargeIn;
			return true;
		}
		return false;
	}

	//SETTER FOR LOCATION
	bool Bird::setLocation(std::string locationIn)
	{
		bool success = false;
		double latitude = 0;
		double longitude = 0;

		success = checkIfLocationIsInt(locationIn, locationDelimiter);
		if (success == true)
		{
			success = parseLocationString(locationIn, locationDelimiter, latitude, longitude);
			if (success == true)
			{
				success = setLatitude(latitude);
				if (success == true)
				{
					return setLongitude(longitude);
				}
				return false;
			}
			return false;
		}
		return false;
	}

	// SET BIRD LATITUDE
	bool Bird::setLatitude(double latitudeIn)
	{
		latitude = latitudeIn;
		return true;
	}

	// SET BIRD LONGITUDE
	bool Bird::setLongitude(double longitudeIn)
	{
		longitude = longitudeIn;
		return true;
	}

	// OTHER MEMBER FUNCS
	// CALCULATE RIDE COST WITH CALL TO CALCULATE RIDE LENGHT FUNC
	double Bird::calculateRideAmt()
	{
		double totalCost = 0.0;
		totalCost = ACTIVATION_AMT + (CHARGE_PER_MIN * calculateRideLength());
		return totalCost;
	}

	// CALCULATE RIDE LENGTH IN MINUTES
	int Bird::calculateRideLength()
	{
		int totalMinutesUsed = 0;
		if (endTime.getYear() == startTime.getYear())
		{
			if (endTime.getMonth() == startTime.getMonth())
			{
				if (endTime.getDay() == startTime.getDay())
				{
					if (endTime.getHour() == startTime.getHour())
					{
						if (endTime.getMinute() == startTime.getMinute())
						{
							totalMinutesUsed = 0;
							return totalMinutesUsed;
						}
						else
						{
							totalMinutesUsed = (endTime.getMinute() - startTime.getMinute());
							return totalMinutesUsed;
						}
					}
					else
					{
						totalMinutesUsed = (((endTime.getHour() * 60) + endTime.getMinute()) - ((startTime.getHour() * 60) + startTime.getMinute()));
						return totalMinutesUsed;
					}
				}
				else
				{
					totalMinutesUsed = (((endTime.getDay() * 24 * 60) + (endTime.getHour() * 60) + endTime.getMinute()) - ((startTime.getDay() * 24 * 60) + (startTime.getHour() * 60) + startTime.getMinute()));
					return totalMinutesUsed;
				}
			}
			else
			{
				totalMinutesUsed = (((endTime.getMonth() * 30 * 24 * 60) + (endTime.getDay() * 24 * 60) + (endTime.getHour() * 60) + endTime.getMinute()) - ((startTime.getMonth() * 30 * 24 * 60) + (startTime.getDay() * 24 * 60) + (startTime.getHour() * 60) + startTime.getMinute()));
				return totalMinutesUsed;
			}
		}
		else
		{
			totalMinutesUsed = (((endTime.getYear() * 365 * 24 * 60) + (endTime.getMonth() * 30 * 24 * 60) + (endTime.getDay() * 24 * 60) + (endTime.getHour() * 60) + endTime.getMinute()) - ((startTime.getYear() * 365 * 24 * 60) + (startTime.getMonth() * 30 * 24 * 60) + (startTime.getDay() * 24 * 60) + (startTime.getHour() * 60) + startTime.getMinute()));
			return totalMinutesUsed;
		}
	}

	// CALCULATE RANDOM ID FROM 1 TO 5
	int Bird::createId()
	{
		srand(time(NULL));
		id = rand();
		return id;
	}

	// FUNCTION WILL CHECK THAT INPUT STRING CONSISTS OF INTS AND CORRECT DELIMITER FORMAT
	bool Bird::checkIfDateIsInt(std::string dateIn, char dateDelimiter)
	{
		int delimiterCounter = 0;
		for (int i = 0; i < dateIn.length(); i++)
		{
			if (isdigit(dateIn[i]) || dateIn[i] == dateDelimiter)
			{
				if (dateIn[i] == dateDelimiter)
				{
					delimiterCounter++;
				}
				continue;
			}
			else
			{
				return false;
			}
		}
		if (delimiterCounter != 2)
		{
			return false;
		}
		return true;
	}

	// CHECKS LENGHT OF DATE STRING IN
	bool Bird::checkDateLength(std::string dateIn)
	{
		if ((dateIn.length() > 10) || (dateIn.length() < 8))
		{
			return false;
		}
		else
			return true;
	}

	// PARSES DATESTRING IN INTO MONTH DAY YEAR FOR SETTING.
	bool Bird::parseDateString(std::string dateIn, char dateDelimiter, int& monthOut, int& dayOut, int& yearOut)
	{
		int parsePos = 0;
		parsePos = dateIn.find(dateDelimiter);
		if (parsePos <= 2)
		{
			monthOut = std::stoi(dateIn.substr(0, parsePos));
			dateIn.erase(0, parsePos + 1);
			parsePos = dateIn.find(dateDelimiter);
			if (parsePos <= 2)
			{
				dayOut = std::stoi(dateIn.substr(0, parsePos));
				dateIn.erase(0, parsePos + 1);
				if (dateIn.length() == 4)
				{
					yearOut = std::stoi(dateIn);
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}

	// FUNCTION WILL CHECK IF TIME STRING IS OF INTS.
	bool Bird::checkIfTimeIsInt(std::string timeIn, char timeDelimiter)
	{
		int delimiterCounter = 0;
		for (int i = 0; i < timeIn.length(); i++)
		{
			if (isdigit(timeIn[i]) || timeIn[i] == timeDelimiter)
			{
				if (timeIn[i] == timeDelimiter)
				{
					delimiterCounter++;
				}
				continue;
			}
			else
			{
				return false;
			}
		}
		if (delimiterCounter != 1)
		{
			return false;
		}
		return true;
	}

	// FUNCTION WILL CHECK TIMESTRING LENGHT
	bool Bird::checkTimeLength(std::string timeIn)
	{
		if ((timeIn.length() > 5) || (timeIn.length() < 4))
		{
			return false;
		}
		else
			return true;
	}

	// FUNCTION WILL PARSE TIME STRING INTO HOUR MINUTE FOR SETTING
	bool Bird::parseTimeString(std::string timeIn, char timeDelimiter, int& hourOut, int& minuteOut)
	{
		int parsePos = 0;

		parsePos = timeIn.find(timeDelimiter);
		if (parsePos <= 2)
		{
			hourOut = std::stoi(timeIn.substr(0, parsePos));
			timeIn.erase(0, parsePos + 1);
			if (timeIn.length() == 2)
			{
				minuteOut = std::stoi(timeIn);
				return true;
			}
			return false;
		}
		return false;
	}

	// FUNCTION WILL CHECK IF STANDARD STRING IS INT
	bool Bird::checkIfStringIsInt(std::string stringToCheck)
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

	// FUNCTION WILL CHECK IF DATE STRING IS INT.
	bool Bird::checkIfLocationIsInt(std::string locationToCheck, char locationDelimiter)
	{
		int delimiterCounter = 0;
		for (int i = 0; i < locationToCheck.length(); i++)
		{
			if ((isdigit(locationToCheck[i])) || (locationToCheck[i] == locationDelimiter) || (locationToCheck[i] == '-') || (locationToCheck[i] == '.'))
			{
				if (locationToCheck[i] == locationDelimiter)
				{
					delimiterCounter++;
				}
				continue;
			}
			else
			{
				return false;
			}
		}
		if (delimiterCounter != 1)
		{
			return false;
		}
		return true;
	}

	// FUNCTION WILL PARSE LOCATION STRING INTO LATITUDE AND LONGITUDE FOR SETTING.
	bool Bird::parseLocationString(std::string locationToParse, char locatonDelimiter, double & latitudeOut, double & longitudeOut)
	{
		double latitude = 0, longitude = 0;
		int parsePos = 0;

		parsePos = locationToParse.find(locationDelimiter);
		latitudeOut = std::stod(locationToParse.substr(0, parsePos));
		locationToParse.erase(0, parsePos + 1);

		longitudeOut = stod(locationToParse);
		return true;
	}

	// CONVERT BIRD TO STRING FOR USER PURPOSES
	std::string Bird::toString() const
	{
		std::string userFormat;

		userFormat = "Ride Start Time & Date: " + startTime.toString() + "\n" +
			"Ride End Time & Date: " + endTime.toString() + "\n"
			"Ride Length: " + std::to_string(rideLength) + " Minutes\n" +
			"Ride Amount: $" + std::to_string(rideAmt) + "\n" +
			"Bird ID: " + std::to_string(id) + "\n" +
			"Bird Battery Charge: " + std::to_string(batteryCharge) + "%\n" +
			"Bird Latitude: " + std::to_string(latitude) + "\n" +
			"Bird Longitude: " + std::to_string(longitude) + "\n";
		return userFormat;
	}

	// CONVERT BIRD TO STRING FOR FILE WRITE PURPOSES (COMMA DELIMITED)
	std::string Bird::toFileString() const
	{
		std::string fileFormat;

		fileFormat = startTime.toFileString() +
			endTime.toFileString() +
			std::to_string(rideLength) + "," +
			std::to_string(rideAmt) + "," +
			std::to_string(id) + "," +
			std::to_string(batteryCharge) + "," +
			std::to_string(latitude) + "," +
			std::to_string(longitude) + ",";
		return fileFormat;
	}

	// BIRD ASSIGNMENT OPERATOR
	Bird Bird::operator=(const Bird& birdTmp)
	{
		startTime = birdTmp.startTime;
		endTime = birdTmp.endTime;
		rideLength = birdTmp.rideLength;
		rideAmt = birdTmp.rideAmt;
		id = birdTmp.id;
		batteryCharge = birdTmp.batteryCharge;
		latitude = birdTmp.latitude;
		longitude = birdTmp.longitude;
		return Bird(rideLength, rideAmt, id, batteryCharge, latitude, longitude);
	}

	// BIRD COMPARISON OPERATOR BIRD TO BIRD BY UNIQUE ID
	bool operator==(const Bird& compareBird, const Bird& dataBird)
	{
		if (compareBird.id == dataBird.id)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// ID INT TO BIRD COMPARISON OPERATOR BY UNIQUE ID
	bool operator==(const int compareInt, const Bird & dataBird)
	{
		if (compareInt == dataBird.id)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// BIRD TO BIRD NOT EQUAL COMPARISON OPERATOR BY UNIQUE ID
	bool operator!=(const Bird& compareBird, const Bird& dataBird)
	{
		return(!(compareBird == dataBird));
	}

	// BIRD (>) COMPARISON OPERATOR BIRD TO BIRD BY UNIQUE ID
	bool operator>(const Bird & compareBird, const Bird & dataBird)
	{
		if (compareBird.id > dataBird.id)
		{
			return true;
		}
		else
			return false;
	}

	// BIRD (>=) COMPARISON OPERATOR BIRD TO BIRD BY UNIQUE ID
	bool operator>=(const Bird & compareBird, const Bird & dataBird)
	{
		return (compareBird > dataBird || compareBird == dataBird);
	}

	// BIRD (<) COMPARISON OPERATOR BIRD TO BIRD BY UNIQUE ID
	bool operator<(const Bird & compareBird, const Bird & dataBird)
	{
		return (!(compareBird > dataBird));
	}

	// BIRD (<=) COMPARISON OPERATOR BIRD TO BIRD BY UNIQUE ID
	bool operator<=(const Bird & compareBird, const Bird & dataBird)
	{
		return (compareBird < dataBird || compareBird == dataBird);
	}

	// OS STREAM OPERATOR FOR << BIRD
	std::ostream & operator<<(std::ostream & os, const Bird& birdTmp)
	{
		os << birdTmp.toString();
		return os;
	}

	// OF STREAM OPERATOR FOR << BIRD
	std::ofstream & operator<<(std::ofstream & ofs, Bird& birdTmp)
	{
		ofs << birdTmp.toFileString();
		return ofs;
	}

	// IS STREAM OPERATOR FOR >> BIRD
	std::istream & operator>>(std::istream & is, Bird& birdTmp)
	{
		bool loopFinish = false;

		do
		{
			std::string rideStartDate;
			loopFinish = false;
			// GET USER INPUT FOR START DATE
			std::cout << "Please enter ride START DATE (mm/dd/yyyy): ";
			is >> rideStartDate;
			loopFinish = birdTmp.setStartDate(rideStartDate);
			// IF LOOP FINISH IS FALSE PRINT ERROR MESSAGE TO USER.
			if (loopFinish == false)
			{
				std::cout << "\nThe 'START DATE' you entered is not in (mm/dd/yyyy) format and/or does not only contain 'INTEGERS' and the '/' delimiter character.\n\n";
			}
			// CONTINUE WHILE LOOP IF FALSE
		} while (loopFinish == false);

		std::cout << "I have set the START DATE for your ride.\n\n";

		// GET 'START TIME' AND PARSE USER INPUT INTO 'INT' FORMATTING FOR SETTING BIRD TIME VARIABLES.
		do
		{
			// CLEAR START TIME VARIABLES
			std::string rideStartTime;
			loopFinish = false;

			// GET USER INPUT FOR START TIME
			std::cout << "Please enter ride START TIME (hh:mm): ";
			is >> rideStartTime;
			loopFinish = birdTmp.setStartTime(rideStartTime);
			// IF LOOP FINISH IS FALSE PRINT ERROR MESSAGE TO USER.
			if (loopFinish == false)
			{
				std::cout << "\nThe 'START TIME' you entered is not in (hh:mm) format and/or does not only contain 'INTEGERS' and a single ':' delimiter character.\n\n";
			}
			// CONTINUE WHILE LOOP IF FALSE
		} while (loopFinish == false);

		std::cout << "I have set the START TIME for your ride.\n\n";

		// GET 'END DATE' AND PARSE USER INPUT INTO 'INT' FORMATTING FOR SETTING BIRD DATE VARIABLES.
		do
		{
			// CLEAR END DATE VARIABLES
			std::string rideEndDate;
			loopFinish = false;

			// GET USER INPUT FOR END DATE
			std::cout << "Please enter ride END DATE (mm/dd/yyyy): ";
			is >> rideEndDate;
			loopFinish = birdTmp.setEndDate(rideEndDate);

			// IF LOOPFINISH FALSE PRINT ERROR MESSAGE TO USER
			if (loopFinish == false)
			{
				std::cout << "\nThe 'END DATE' you entered is not in (mm/dd/yyyy) format and/or does not only contain 'INTEGERS' and the '/' parse character.\n";
				std::cout << "Or the 'END DATE' you entered precedes the 'START DATE' entered.\n\n";
			}
			// CONTINUE WHILE LOOP IF FALSE
		} while (loopFinish == false);

		std::cout << "I have set the END DATE for your ride.\n\n";

		// GET 'END TIME' AND PARSE USER INPUT INTO 'INT' FORMATTING FOR SETTING BIRD TIME VARIABLES.
		do
		{
			// CLEAR END TIME VARIABLES
			std::string rideEndTime;
			loopFinish = false;

			// GET USER INPUT FOR 'END TIME'
			std::cout << "Please enter ride END TIME (hh:mm): ";
			is >> rideEndTime;
			loopFinish = birdTmp.setEndTime(rideEndTime);

			// IF LOOP FINISH FALSE PRINT ERROR MESSAGE TO USER.
			if (loopFinish == false)
			{
				std::cout << "\nThe 'END TIME' you entered is not in (hh:mm) format and/or does not only contain 'INTEGERS' and the ':' parse character.\n";
				std::cout << "Or the 'END TIME' you entered precedes the 'START TIME' entered.\n\n";
			}
			// CONTINUE WHILE LOOP IF FALSE
		} while (loopFinish == false);

		std::cout << "I have set the END TIME for your ride.\n\n";

		// GET 'BATTERY CHARGE' AND PARSE USER INPUT INTO 'INT' FORMATTING FOR SETTING BIRD BATTERY CHARGE VARIABLES.
		do
		{
			// CLEAR BATTERY CHARGE VARIABLES
			std::string rideBatteryCharge;
			loopFinish = false;

			// GET USER INPUT FOR 'BATTERY CHARGE'
			std::cout << "Please enter Bird BATTERY CHARGE integer from 0 - 100: ";
			is >> rideBatteryCharge;
			loopFinish = birdTmp.prepBatteryCharge(rideBatteryCharge);

			// IF LOOPFINISH FALSE PRINT ERROR MESSAGE
			if (loopFinish == false)
			{
				std::cout << "\nPlease enter an integer between 0 - 100 for BatteryCharge.\n\n";
			}
			// IF FALSE CONTINUE WHILE LOOP
		} while (loopFinish == false);

		std::cout << "I have set the BATTERY CHARGE for your ride.\n\n";

		// GET 'BIRD LOCATION' AND PARSE USER INPUT INTO 'INT' FORMATTING FOR SETTING BIRD LOCATION VARIABLES.
		do
		{
			// CLEAR LOCATION VARIABLES
			std::string birdLocation;
			loopFinish = false;

			// GET USER INPUT FOR 'LOCATION'
			std::cout << "Please enter Bird LOCATION (latitude/longitude): ";
			is >> birdLocation;
			loopFinish = birdTmp.setLocation(birdLocation);

			// IF LOOP FINISH FALSE PRINT ERROR MESSAGE TO USER
			if (loopFinish == false)
			{
				std::cout << "\nThe 'LOCATION' you entered is not in (latitude/longitude) format.\n\n";
			}
			// CONTINUE WHILE LOOP IF FALSE
		} while (loopFinish == false);

		std::cout << "I have set the LOCATION for your ride.\n\n";

		// CALCULATE AND SET RIDE LENGTH
		birdTmp.setRideLength(birdTmp.calculateRideLength());

		// CALCULATE AND SET RIDE AMOUNT
		birdTmp.setRideAmt(birdTmp.calculateRideAmt());

		// CREATE RIDE ID
		birdTmp.setId(birdTmp.createId());

		return is;
	}

	// IF STREAM OPERATOR FOR >> BIRD
	std::ifstream & operator>>(std::ifstream & ifs, Bird& birdTmp)
	{
		// INITIALIZE VARIABLES AND FEILD POINTER
		std::string line_string;
		ifs >> line_string;
		Field field(line_string);
		std::string* fields = field.split(',');

		// CHECK THAT ALL PLACEHOLDERS ARE FILLED FOR BIRD OBJECT TO PREVENT
		// CORRUPT DATA INPUT.
		if (field.getArraySize() == 16)
		{
			// IF ALL PLACEHOLDERS ARE ACCOUNTED FOR SET EACH 
			// PRIVATE MEMBER VARIABLE WITH SETTERS.
			birdTmp.setStartMonth(std::stoi(fields[0]));
			birdTmp.setStartDay(std::stoi(fields[1]));
			birdTmp.setStartYear(std::stoi(fields[2]));
			birdTmp.setStartHour(std::stoi(fields[3]));
			birdTmp.setStartMinute(std::stoi(fields[4]));
			birdTmp.setEndMonth(std::stoi(fields[5]));
			birdTmp.setEndDay(std::stoi(fields[6]));
			birdTmp.setEndYear(std::stoi(fields[7]));
			birdTmp.setEndHour(std::stoi(fields[8]));
			birdTmp.setEndMinute(std::stoi(fields[9]));
			birdTmp.setRideLength(std::stoi(fields[10]));
			birdTmp.setRideAmt(std::stod(fields[11]));
			birdTmp.setId(std::stoi(fields[12]));
			birdTmp.setBatteryCharge(std::stoi(fields[13]));
			birdTmp.setLatitude(std::stod(fields[14]));
			birdTmp.setLongitude(std::stod(fields[15]));
		}
		// DELET FIELDS ARRAY TO PREVENT DATA LEAKS
		delete[] fields;
		// SET FIELDS POINTER TO NULL
		fields = NULL;
		return ifs;
	}

}