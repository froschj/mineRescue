/*
 * Program Name: final project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: abstract class defining items that can be found in a text 
 * adevnture game
 */

#include "Item.hpp"
#include <string>

/*
 * Description: create a blank item object
 */
Item::Item()
{
	name = "";
}

/*
 * Description: allow derived classes to define the name/desc variable
 */
Item::Item(std::string newName, std::string newDesc)
{
	setName(newName);
	setDescription(newDesc);
}

/*
 * Description: placeholder definition, no destructor actions needed for 
 * this base class
 */
Item::~Item()
{
}

/*
 * Description: returns the name property of an object as a string
 */
std::string Item::getName()
{
	return name;
}

/*
 * Description: set the name property ofthis item to a string argument
 */
void Item::setName(std::string newName)
{
	this->name = newName;
}

/*
 * Description: returns the description property of an object as a string
 */
std::string Item::getDescription()
{
	return description;
}

/*
 * Description: set the description property of this item to a string 
 * argument
 */
void Item::setDescription(std::string newDesc)
{
	this->description = newDesc;
}
