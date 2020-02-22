/*
 * Program Name: Final Project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Extension of the base Space class to describe a room with 
 * fans that need to be enabled.
 */


#include "Space.hpp"
#include "FanRoom.hpp"
#include <iostream>
#include "Player.hpp"

/*
 * Description: set up aspects of a fan Room that are not handled by 
 * generic space
 */
FanRoom::FanRoom()
{
	shortDesc = "Ventilation Room";
	longDesc = "the control room for the ventilation system";
	fanOn = false;
}

/*
 * Description: placeholder
 */
FanRoom::~FanRoom()
{
}

/*
 * Description: generate a map representing currently valid actions to take
 * by the user
 */
void FanRoom::generateMenu()
{
	// get verbs from generic room
	Space::generateMenu();

	//add special verb to valve room
	if (!fanOn)
	{
		verbList["Turn on fans"] = "start";
	}
}

/*
 * Description: display a description of the room to the console
 */
void FanRoom::describeRoom()
{
	//get generic room description
	Space::describeRoom();

	//add special description for valve room
	if(!fanOn)
	{
		std::cout << "The ventilation system is here, disabled.\n"
			<< "You need some wire to connect it to power."
			<< std::endl;
	}
	else
	{
		std::cout << "The ventilation system hums as it clears the "
			<< "toxic gas" << std::endl;
	}
}

/*
 * Description: displays a menu of valid actions to take in this room when 
 * the currentPlayer is in the room. returns the next space the 
 * currentPlayer may me in (this may be the same space the player is 
 * already in
 */
Space* FanRoom::action(Player* currentPlayer)
{
	// allow for default actions
	Space* temp = Space::action(currentPlayer);

	//special tool room actions
	hero = currentPlayer;
	if (!fanOn && (selection == "start"))
	{
		if (hero->hasItem("Jumper Cables"))
		{
			hero->consumeItem("Jumper Cables");
			std::cout << "The electric current welds the "
				"jumper cables in place.\n"
				<< "The fans kick on and attempt to clear "
				<< "the gas." << std::endl;
			fanOn = true;
			hero->setVent(true);
			hero->modifyAir(Space::DEFAULT_COST);
		}
		else
		{
			std::cout << "You need some wire too hook the "
				<< "fans to power" << std::endl;
		}
	}
	//housekeeping
	hero = nullptr;
	return temp;
}

