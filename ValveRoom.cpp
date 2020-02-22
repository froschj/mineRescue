/*
 * Program Name: Final Project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Extension of the base Space class to describe a room with 
 * locked doors that must be unlocked.
 */


#include "Space.hpp"
#include "ValveRoom.hpp"
#include <iostream>

/*
 * Description: set up aspects of a valve Room that are not handled by 
 * generic space
 */
ValveRoom::ValveRoom()
{
	shortDesc = "Valve Room";
	longDesc = "the main valve room for handling toxic gas";
	valveClosed = false;
}

/*
 * Description: placeholder
 */
ValveRoom::~ValveRoom()
{
}

/*
 * Description: generate a map representing currently valid actions to take
 * by the user
 */
void ValveRoom::generateMenu()
{
	// get verbs from generic room
	Space::generateMenu();

	//add special verb to valve room
	if (!valveClosed)
	{
		verbList["Shut valve"] = "shut";
	}
}

/*
 * Description: display a description of the room to the console
 */
void ValveRoom::describeRoom()
{
	//get generic room description
	Space::describeRoom();

	//add special description for valve room
	if(!valveClosed)
	{
		std::cout << "There is an open valve here spewing toxic "
			<< "gas" <<std::endl;
	}
	else
	{
		std::cout << "There is a valve here with the stem snapped\n"
			<< "Thankfully it is closed" << std::endl;
	}
}

/*
 * Description: displays a menu of valid actions to take in this room when 
 * the currentPlayer is in the room. returns the next space the 
 * currentPlayer may me in (this may be the same space the player is 
 * already in
 */
Space* ValveRoom::action(Player* currentPlayer)
{
	// allow for default actions
	Space* temp = Space::action(currentPlayer);

	//special tool room actions
	hero = currentPlayer;
	if (!valveClosed && (selection == "shut"))
	{
		if (hero->hasItem("Wrench"))
		{
			std::cout << "The valve yields to the leverage of "
				<< "the wrench.\nYour effort closes the "
				<< "valve, but the stem snaps off from the "
				<< "torque.\nThe flow of toxic gas ceases."
				<< std::endl;
			valveClosed = true;
			hero->setGas(true);
		}
		else
		{
			std::cout << "You struggle with the valve but "
				<< "cannot shut it.\nYou need something to "
				<< "give you a lot more leverage"
				<< std::endl;
		}
		hero->modifyAir(Space::DEFAULT_COST);
	}
	//housekeeping
	hero = nullptr;
	return temp;
}

