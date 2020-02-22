/*
 * Program Name: final project
 * Author: Jon Frosch
 * Date 2019-06-11
 * Description: class to represent a player character in a text adventure 
 * game
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Item.hpp"
#include <vector>
#include <list>
#include <string>

class Player
{
	private:
		int airSupply; //track the air supply for the player
		const int startingAir = 100;
		const unsigned maxInventory = 2;
		
		//conditions to win the game
		bool ventOn;
		bool gasOff;
	
		//flag for exiting before the game is over
		bool quitter;

		std::list<Item*> inventory; //container to hold items the
			//player is carrying
	public:
		Player(); //constructor
		~Player(); //destructor

		//life management
		int getAir(); //return the current air supply
		void modifyAir(int deltaAir); //add the value deltaAir
			//to the current air supply
		
		//game end conditions
		void setVent(bool status); //set win condition
		void setGas(bool status); //set win condition
		void setQuit(bool status); //set quit condition
		bool isAlive(); //return false if the Player is dead
		bool isWinner(); //return true if the win conditions are met
		bool hasQuit(); //return true if the user wants to quit
		
		//inventory management
		int inventorySize(); //return the current number of items 
			//the player is carrying
		std::vector<std::string> nameInventory(); //describe
			//held items, returning a vector of strings with 
			//their names
		std::vector<std::string> descInventory(); //describe
			//held items, returning a vector of strings with 
			//their descriptions
		bool inventoryFull(); //return true if the inventory is full
			// false otherwise
		void addItem(Item* newItem); //accept a pointer to an Item
			//and add it to the inventory
		Item* drop(); //remove an item from inventory and 
			//return a pointer to it. choose the item to drop
			//via a console menu
		bool hasItem(std::string itemName); //return true if the 
			//named item is in inventory
		Item* consumeItem(std::string itemName); // remove a given
			//item from the player's inventory. check if the
			//player has the item before calling this. returns 
			//a pointer to the requested item
};
#endif
