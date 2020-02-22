/*
 * Program Name: Project1
 * Author:	Jon Frosch
 * Date:	2019-04-14
 * Description: function to display a menu, get the user's choice and 
 * returns an integer corresponding to the user's choice. accepts an
 * array of strings, each element describing an option, and the number of
 * options
 */

#ifndef OPTION_MENU_HPP
#define OPTION_MENU_HPP


#include <string>

//prints a menu (numbers and descriptions) to the console
//accepts array of strings fr choices and their number
void displayMenu(const std::string *descriptions, const int numChoices);

// accepts a list of options as a array of strings and the number of
// options and returns an integer representing a valid selection
int optionMenu(const std::string *optionList, const int numOptions);

#endif
