/*
 * Program Name:	Project 1
 * Author:		Jon Frosch
 * Date:		2019-04-05
 * Description:		functions for input validation
 */

#include "inputValidation.hpp"
#include <string>
#include <sstream>
#include <istream>

/*
 * Description: validInteger accpets a string and checks if it is a
 * valid integer. returns true on success and false on a failure.
 */

bool isValidInteger(const std::string input)
{
	bool success = false;
	int test;
	std::istringstream testStream(input);
	testStream >> std::ws;
	testStream >> test;
	if (!testStream.fail() && (testStream.peek() == EOF))
	{
		success = true;
	}
	return success;
}

/*
 * Description: validDouble accpets a string and checks if it is a
 * valid double. returns true on success and false on a failure.
 */

bool isValidDouble(const std::string input)
{
	bool success = false;
	double test;
	std::istringstream testStream(input);
	testStream >> std::ws;
	testStream >> test;
	if (!testStream.fail() && (testStream.peek() == EOF))
	{
		success = true;
	}
	return success;
}
/*
 * Description: checks if an integer is in a specified range. accepts an
 * integer to check and two integers defining an includive range. returns 
 * true if number is between low and high inclusive
 */

bool intInRange(int number, int low, int high)
{
	bool success = false;
	if ((number >= low) && (number <= high))
	{
		success = true;
	}
	return success;
}


/*
 * Description: checks if a double is in a specified range. accepts a
 * double to check and two doubles defining an includive range. returns 
 * true if number is between low and high inclusive
 */

bool doubleInRange(double number, double low, double high)
{
	bool success = false;
	if ((number >= low) && (number <= high))
	{
		success = true;
	}
	return success;
}
