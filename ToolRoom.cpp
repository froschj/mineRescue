/*
 * Program Name: Final Project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Extension of the base Space class to describe a room with 
 * a cabinet that conceals items until the player opens it.
 */

#include "Space.hpp"
#include <list>
#include "ToolRoom.hpp"
#include "Item.hpp"
#include <iostream>
#include <string>

/*
 * Description: set up aspects of a Tool Room that are not handled by 
 * generic space
 */
ToolRoom::ToolRoom()
{
	cabinetOpened = false;
	cabinetItems.clear();
	shortDesc = "Tool Room";
	longDesc = "a storage room with a closed cabinet";
}

/*
 * Description: placeholder
 */
ToolRoom::~ToolRoom()
{
}

/*
 * Description: generate a map representing currently valid actions to take
 * by the user
 */
void ToolRoom::generateMenu()
{
	// get verbs fromg generic room
	Space::generateMenu();

	//add special verb to tool room
	if (!cabinetOpened)
	{
		verbList["Open cabinet"] = "open";
	}
}

/*
 * Description: display a description of the room to the console
 */
void ToolRoom::describeRoom()
{
	//get generic room description
	Space::describeRoom();

	//add special description for tool room
	if (!cabinetOpened)
	{
		std::cout << "There is a closed storage cabinet on the "
			<< "wall here." << std::endl;
	}
	else
	{
		std::cout << "An irreparably broken cabinet hangs open "
			<< "from the wall here." << std::endl;
	}
}

/*
 * Description: displays a menu of valid actions to take in this room when 
 * the currentPlayer is in the room. returns the next space the 
 * currentPlayer may me in (this may be the same space the player is 
 * already in
 */
Space* ToolRoom::action(Player* currentPlayer)
{
	// allow for default actions
	Space* temp = Space::action(currentPlayer);

	//special tool room actions
	hero = currentPlayer;
	if ((!cabinetOpened) && (selection == "open"))
	{
		std::cout << "The cabinet springs open and immediately "
			<< "springs out of shape.\nIts contents spill to "
			<< "the floor (It must have been damaged in the "
			<< "accident),\nadding ";
		longDesc = "a storage room with a broken cabinet";
		for (auto it = cabinetItems.begin(); 
			it != cabinetItems.end(); ++it)
		{
			if (it != cabinetItems.begin())
			{
				std::cout << ", ";
			}

			std::cout << (*it)->getName();
		
			roomItems.push_back(*it);
		}
		cabinetItems.clear();
		cabinetOpened = true;
		std::cout << " to the floor." << std::endl;
		hero->modifyAir(Space::DEFAULT_COST);
	}
	//housekeeping
	hero = nullptr;
	return temp;
}


/*
 * Description: accept a pointer to an item object and add it to the list of
 * items in the room
 */
void ToolRoom::addToCabinet(Item* newItem)
{
	if (!cabinetOpened)
	{
		cabinetItems.push_back(newItem);
	}
	else
	{
		roomItems.push_back(newItem);
	}
}
