/*
 * Program Name: Final Project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Abstract base class for a "room" in a text adventure-style 
 * game. derived classes will expand on this functionality.
 */

#include <string>
#include "Space.hpp"
#include <iostream>
#include "optionMenu.hpp"
#include <map>
#include <vector>


/*
 * Description: Create a space object and initialize data memebers to safe
 * defaults. create the mapping from characters to direction pointers
 */
Space::Space()
{
	hero = nullptr;
	north = nullptr;
	east = nullptr;
	south = nullptr;
	west = nullptr;
	up = nullptr;
	down = nullptr;
	shortDesc = "";
	longDesc = "";

	directions[ 'n' ] = this->north;
	directions[ 'e' ] = this->east;
	directions[ 's' ] = this->south;
	directions[ 'w' ] = this->west;
	directions[ 'u' ] = this->up;
	directions[ 'd' ] = this->down;
}

/*
 * Description: clean up a space object
 */
Space::~Space()
{
}

/*
 * Description: Accepts a pointer to a space and a character representing a
 * direction. valid characters are defined in the directions map. sets the 
 * appropriate direction memeber of this space to the neighbor space passed
 * in.
 */
void Space::setNeighbor(char direction, Space* neighbor)
{
	directions.at(direction) = neighbor;
}

/*
 * Description: displays a menu of valid actions to take in this room when 
 * the currentPlayer is in the room. returns the next space the 
 * currentPlayer may me in (this may be the same space the player is 
 * already in
 */
Space* Space::action(Player* currentPlayer)
{
	//housekeeping for memeber variables
	hero = currentPlayer;
	Space* temp = this;

	//set up and show the actions menu
	//enum verb { move, take, drop, inventory};
	verbList.clear();	
	
	this->generateMenu();
	
	selection = getSelection();
	//take appropriate action based on user selection
	if (selection ==  "move")
	{
		temp = move();
	}
	else if (selection == "take")
	{
		take();
	}
	else if (selection == "drop")
	{
		Item* droppedItem = nullptr;
		droppedItem = hero->drop();
		if (droppedItem != nullptr)
		{
			roomItems.push_back(droppedItem);
		}
	}
	else if (selection == "inventory")
	{
		std::vector<std::string> inventory = hero->descInventory();
		if(inventory.empty())
		{
			std::cout << "Your hands are empty." << std::endl;
		}
		else
		{
			std::cout << "You are holding:" << std::endl;
			for (auto it = inventory.begin(); 
				it != inventory.end(); ++it)
			{
				std::cout << *it << std::endl;
			}
		}
	}
	else if (selection == "exit")
	{
		hero->setQuit(true);
	}

	//variable housekeeping
	hero = nullptr;
	return temp;
}

/*
 * Description: display a menu of valid action items to the user via the 
 * console. return a string representing the verb being used.
 */
std::string Space::getSelection()
{
	std::vector<std::string> verbMenu;
	
	for (auto it = verbList.begin(); it != verbList.end(); ++it)
	{
		verbMenu.push_back(it->first);
	}

	int selection = optionMenu(verbMenu.data(), verbMenu.size());

	return verbList.at(verbMenu.at(selection));
	
}

/*
 * Description: generate a map representing currently valid actions to take
 * by the user
 */
void Space::generateMenu()
{
	verbList["Move to an adjacent room"] = "move";
	verbList["Check my inventory"] = "inventory";
	if (!(roomItems.empty()))
	{
		verbList["Take an item from the room"] = "take";
	}
	if ((hero->inventorySize()) > 0)
	{
		verbList["Drop an item"] = "drop";

	}
	verbList["Exit playthrough"] = "exit";

}

/*
 * Description: determine valid exits from a room and resent the user with
 * menu of loactions to move to. return a pointer to the space the user 
 * would like to enter.
 */
Space* Space::move()
{
	//determine exits
	std::vector<std::string> exitNames = exits();
	
	//show a menu and get the users's choice for a movement
	std::cout << "Which direction to move?" <<std::endl;
	int selection = optionMenu(exitNames.data(), exitNames.size());
	
	//deduct the move cost from the player's air supply;
	hero->modifyAir(2 * Space::DEFAULT_COST);

	//return pointer
	return directions.at(exitList.at(selection));
}

/*
 * Directions: generate a vector of strings describing the valid exits from
 * the space. set up a map so that this vecotr can be linked back to space
 * pointers for movement
 */
std::vector<std::string> Space::exits()
{
	exitList.clear();
	std::vector<std::string> directionNames;
	int index = 0;
	for (auto it = directions.begin(); it != directions.end(); ++it)
	{
		if (it->second != nullptr)
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
	}

	return directionNames;
}

/*
 * Description: display a description of the room to the console
 */
void Space::describeRoom()
{
	std::cout << "Room: " << shortDesc << std::endl;
	std::cout << "Description: " << longDesc << std::endl;
	std::cout << "Exits: ";
	std::vector<std::string> exitNames = exits();
	for (auto it = exitNames.begin(); it != exitNames.end(); ++it)
	{
		if (it != exitNames.begin())
		{
			std::cout << ", ";
		}
		std::cout << *it;
	}
	
	std::cout << std::endl;
	
	if (!(roomItems.empty()))
	{
		std::cout << "Items here: ";
		for (auto it = roomItems.begin(); it != roomItems.end(); 
			++it)
		{
			if (it != roomItems.begin())
			{
				std::cout << ", ";
			}

			std::cout << (*it)->getName();
		}
		std::cout << std::endl;
	}
}
/*
 * description: get and set functions for longDesc and shortDesc
 */
std::string Space::getShortDesc()
{
	return shortDesc;
}
std::string Space::getLongDesc()
{
	return longDesc;
}
void Space::setShortDesc(std::string name)
{
	this->shortDesc = name;
}
void Space::setLongDesc(std::string description)
{
	this->longDesc = description;
}

/*
 * Description: check if the player has room for an item. if so, allow
 * the user to pick an item in the room from a console menu and send the 
 * item to the player's inventory
 */

void Space::take()
{
	if (hero->inventoryFull())
	{
		std::cout << "Your hands are full." << std::endl;
	}
	else if (!(roomItems.empty()))
	{
		std::vector<std::string> takeList;
		
		for(auto it = roomItems.begin(); it != roomItems.end(); 
			++it)
		{
			takeList.push_back((*it)->getName());
		}
		
		std::cout << "Which item to take?" << std::endl;
		int choice = optionMenu(takeList.data(), takeList.size());
		std::string selectedItem = takeList.at(choice);
		
		auto it = roomItems.begin();
		Item* takenItem = nullptr;
		while ((it != roomItems.end()) && (takenItem == nullptr))
		{
			if (selectedItem == (*it)->getName())
			{
				takenItem = *it;
				roomItems.erase(it);
			}
			else
			{
				++it;
			}
		}
		if (takenItem != nullptr)
		{
			hero->addItem(takenItem);
		}
		hero->modifyAir(Space::DEFAULT_COST);
	}
	else
	{
		std::cout << "There is nothing here to pick up" <<std::endl;

	}
}

/*
 * Description: accept a pointer to an item object and add it to the list of
 * items in the room
 */
void Space::addItem(Item* newItem)
{
	roomItems.push_back(newItem);
}
