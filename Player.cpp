/*
 * Program Name: final project
 * Author: Jon Frosch
 * Date 2019-06-11
 * Description: class to represent a player character in a text adventure 
 * game
 */

#include "Item.hpp"
#include <list>
#include <vector>
#include "Player.hpp"
#include <string>
#include "optionMenu.hpp"
#include <iostream>

/*
 * Description: Set player object to starting conditions
 */
Player::Player()
{
	this->airSupply = Player::startingAir;
	inventory.clear();
	this->ventOn = false;
	this->gasOff = false;
	this->quitter = false;
}

/*
 * Description: clean up after a player object
 */
Player::~Player()
{
}

/*
 * Description: return a vector of strings containing the names of the 
 * currently held items. if inventory is empty, return an empty vector
 */
std::vector<std::string> Player::nameInventory()
{
	std::vector<std::string> itemNames;
	if(!(inventory.empty()))
	{
		for (auto it = inventory.begin(); it != inventory.end(); 
			++it)
		{
			itemNames.push_back((*it)->getName());
		}
	}

	return itemNames;
}

/*
 * Description: return a vector of strings with descriptions of the 
 * currently held items. if inventory is empty, return an empty vector
 */
std::vector<std::string> Player::descInventory()
{
	std::vector<std::string> itemDescs;
	if(!(inventory.empty()))
	{
		for (auto it = inventory.begin(); it != inventory.end(); 
			++it)
		{
			itemDescs.push_back((*it)->getDescription());
		}
	}

	return itemDescs;
}
/*
 * Description: return the current air supply remaining
 */
int Player::getAir()
{
	return airSupply;
}

/*
 * Description: add an integer deltaAir to the current air supply
 */
void Player::modifyAir(int deltaAir)
{
	airSupply += deltaAir;
}

/*
 * Description: set a flag for one of the win conditions. true means this
 * element of victory is achieved
 */
void Player:: setVent(bool status)
{
	ventOn = status;
}

/*
 * Description: set a flag for one of the win conditions. true means this
 * element of victory is achieved
 */
void Player::setGas(bool status)
{
	gasOff = status;
}

/*
 * Description: return the current number of items in inventory
 */
int Player::inventorySize()
{
	return inventory.size();
}

/*
 * Description: return true if the player is alive. return false if the 
 * player has died the player dies when they run out of air
 */
bool Player::isAlive()
{
	bool life = false;
	if (airSupply > 0)
	{
		life = true;
	}
	return life;
}

/*
 * Description: determine if the player has met all the win conditions.
 * return false if the player has not won. return true if the player has won
 */
bool Player::isWinner()
{
	bool win = false;
	if (ventOn && gasOff)
	{
		win = true;
	}
	return win;
}

/*
 * Description: set a flag if the user elects to quit. true means the
 * user would like to quit
 */
void Player::setQuit(bool status)
{
	quitter = status;
}

/*
 * Description: determine is a user would like to quit their game. returns
 * true if the player has chose to quit
 */
bool Player::hasQuit()
{
	return quitter;
}

/*
 * Description: return true if the inventory is full, false otherwise
 */
bool Player::inventoryFull()
{
	bool result = true;
	if (inventory.size() < Player::maxInventory)
	{
		result = false;
	}

	return result;
}

/*
 * Description: accept a pointer to an item object and add it to the 
 * inventory list
 */
void Player::addItem(Item* newItem)
{
	inventory.push_back(newItem);
}

/*
 * Description: check if the player has room for an item. if so, allow
 * the user to pick an item in the room from a console menu and send the 
 * item to the player's inventory
 */

Item* Player::drop()
{
	Item* droppedItem = nullptr;
	if (!(inventory.empty()))
	{
		std::vector<std::string> dropList;
		
		for(auto it = inventory.begin(); it != inventory.end(); 
			++it)
		{
			dropList.push_back((*it)->getName());
		}
		
		std::cout << "Which item to drop?" << std::endl;
		int choice = optionMenu(dropList.data(), dropList.size());
		std::string selectedItem = dropList.at(choice);
		
		auto it = inventory.begin();
		while ((it != inventory.end()) && (droppedItem == nullptr))
		{
			if (selectedItem == (*it)->getName())
			{
				droppedItem = *it;
				inventory.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
	return droppedItem;
}

/*
 * Description: return true if the player is currently holding the item 
 * named in the argument
 */
bool Player::hasItem(std::string itemName)
{		
	bool result = false;
	auto it = inventory.begin();
	while ((it != inventory.end()) && (!result))
	{
		if ((*it)->getName() == itemName)
		{
			result = true;
		}
		else
		{
			++it;
		}
	}
	return result;
}
/*
 * Description: remove the item named in the argument from the player's 
 * inventory. should not be called on an item the player does not have.
 * return a pointer to the requested item
 */
Item* Player::consumeItem(std::string itemName)
{
	bool result = false;
	auto it = inventory.begin();
	while ((it != inventory.end()) && (!result))
	{
		if ((*it)->getName() == itemName)
		{
			result = true;
		}
		else
		{
			++it;
		}
	}
	Item* temp = *it;
	inventory.erase(it);
	return temp;
}
