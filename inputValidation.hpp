/*
 * Program Name:	Input Validation Functions
 * Author:		Jon Frosch
 * Date:		2019-04-05
 * Description:		Functions to validate various console inputs
 */

// accepts a string and checks to see if ic can be construed as an integer
// returns true if yes, false if no.

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP

#include <string>

bool isValidInteger(const std::string); //returns true if string represents 	an integer

bool isValidDouble(const std::string); //returns true if string represents 	a double

//returns true if number is between high and low inclusive
bool intInRange(int number, int low, int high);

//returns true if number is between high and low inclusive
bool doubleInRange(double number, double low, double high);
#endif
