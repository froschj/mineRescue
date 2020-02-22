/*
 * Program Name: Project1
 * Author:	Jon Frosch
 * Date:	2019-04-14
 * Description: function to display a menu, get the user's choice and 
 * returns an integer corresponding to the user's choice. accepts an
 * array of strings, each element describing an option, and the number of
 * options
 */

#include "optionMenu.hpp"
#include <string>
#include <iostream>
#include "inputValidation.hpp"

/*
 * Description: prints a menu (numbers and descriptions) to the console.
 * accepts a pointer to an array of strings representing possible choices
 * and a integer number of choices. 
 */
void displayMenu(const std::string *descriptions, const int numChoices)
{
	for (int i = 0; i < numChoices; ++i)
	{
		std::cout << i + 1 << ": " << 
		descriptions[i] << std::endl;
	}
}

/*
 * Description: accepts an array of strings representing a list of possible
 * choices and an integer representing the number of possible choices.
 * returns an integer representing a valid choice gotten from the console
 */
int optionMenu(const std::string *optionList, const int numOptions)
{
	std::string choiceInput;
	int testValue;
	bool goodChoice = false;
	while (!goodChoice)
	{
		displayMenu(optionList, numOptions);
		std::cout << "Enter integer corresponding to choice. ";
		std::cout << "(1 through ";
		std::cout << numOptions << ")" << std::endl;
		getline(std::cin, choiceInput);
		if (isValidInteger(choiceInput))
		{
			testValue = std::stoi(choiceInput);
			if (intInRange(testValue, 1, numOptions))
			{
				goodChoice = true;
			}
			else
			{
				std::cout << "Selection out of range. ";
				std::cout << "Try again." << std::endl;
			}
		}
		else
		{
			std::cout << "Selection not an integer. ";
			std::cout << "Try again." << std::endl;
		}
	}

	return (testValue - 1);
}
