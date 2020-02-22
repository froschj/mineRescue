/*
 * Program Name: Final Project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Extension of the base Space class to describe a room with 
 * locked doors that must be unlocked.
 */


#include "Space.hpp"
#include <map>
#include "LockRoom.hpp"
#include <iostream>
#include <string>
#include "optionMenu.hpp"

/*
 * Description: set up aspects of a Lock Room that are not handled by 
 * generic space
 */
LockRoom::LockRoom()
{
	shortDesc = "Corridor";
	longDesc = "a nondescript room";
}

/*
 * Description: placeholder
 */
LockRoom::~LockRoom()
{
}

/*
 * Description: generate a map representing currently valid actions to take
 * by the user
 */
void LockRoom::generateMenu()
{
	// get verbs fromg generic room
	Space::generateMenu();

	//add special verb to lock room
	if (!(lockList.empty()))
	{
		verbList["Open door"] = "open";
	}
}

/*
 * Description: display a description of the room to the console
 */
void LockRoom::describeRoom()
{
	//get generic room description
	Space::describeRoom();

	//add special description for lock room
	if(!lockList.empty())
	{
		std::cout << "There are locked doors:" << std::endl;
		for (auto it = lockList.begin(); it != lockList.end(); ++it)
		{
			switch (it->first)
			{
				case 'n':
					std::cout << "North" << std::endl;
					break;
				case 'e':
					std::cout << "East" << std::endl;
					break;
				case 's':
					std::cout << "South" << std::endl;
					break;
				case 'w':
					std::cout << "West" << std::endl;
					break;
				case 'u':
					std::cout << "Up" << std::endl;
					break;
				case 'd':
					std::cout << "Down" << std::endl;
					break;

			}

		}
	}
}

/*
 * Description: displays a menu of valid actions to take in this room when 
 * the currentPlayer is in the room. returns the next space the 
 * currentPlayer may me in (this may be the same space the player is 
 * already in
 */
Space* LockRoom::action(Player* currentPlayer)
{
	// allow for default actions
	Space* temp = Space::action(currentPlayer);

	//special lock room actions
	hero = currentPlayer;
	if ((!lockList.empty()) && (selection == "open"))
	{
		unlock();
	}
	//housekeeping
	hero = nullptr;
	return temp;
}

/*
 * Description: lock a door in the roomin a given direction dir represented
 * by a character
 */
void LockRoom::lock(char dir)
{
	lockList[dir] = directions.at(dir);
	directions.at(dir) = nullptr;
}

/*
 * Description: allow the user to select a door to unlock from a menu. open
 * the door if the player has an appropriate tool
 */
void LockRoom::unlock()
{
	//determine exits
	std::vector<std::string> lockNames = locks();
	
	//show a menu and get the users's choice for a movement
	std::cout << "Which door to open?" << std::endl;
	int selection = optionMenu(lockNames.data(), lockNames.size());
	if (hero->hasItem("Screwdriver"))
	{
		directions.at(exitList.at(selection)) = 
			lockList.at(exitList.at(selection));
		lockList.erase(exitList.at(selection));
		std::cout << "You pop the latch with your screwdriver.\n"
			<< "The door pops open, and the damage keeps it "
			<< "from shutting again." << std::endl;
		hero->modifyAir(Space::DEFAULT_COST);
	}
	else
	{
		std::cout << "You need something long and narrow to slip "
			<< "the latch." << std::endl;
	}
}


/*
 * Description: return a vector with the names of the current locked door 
 * directions for use in a console menu
 */
std::vector<std::string> LockRoom::locks()
{
	exitList.clear();
	std::vector<std::string> directionNames;
	int index = 0;
	for (auto it = lockList.begin(); it != lockList.end(); ++it)
	{
		switch (it->first)
		{
		case 'n':
			directionNames.push_back("North");
			exitList[index] = 'n';
			break;
		case 'e':
			directionNames.push_back("East");
			exitList[index] = 'e';
			break;
		case 's':
			directionNames.push_back("South");
			exitList[index] = 's';
			break;
		case 'w':
			directionNames.push_back("West");
			exitList[index] = 'w';
			break;
		case 'u':
			directionNames.push_back("Up");
			exitList[index] = 'u';
			break;
		case 'd':
			directionNames.push_back("Down");
			exitList[index] = 'd';
			break;
		}
		++index;
	}

	return directionNames;
}

