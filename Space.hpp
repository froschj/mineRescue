/*
 * Program Name: Final Project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Abstract base class for a "room" in a text adventure-style 
 * game. derived classes will expand on this functionality.
 */

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <map>
#include <list>
#include <vector>
#include "Player.hpp"
#include "Item.hpp"

class Space
{
	protected:
		// direction pointers to allow spaces to be linked together
		// in a game map
		Space* north;
		Space* east;
		Space* south;
		Space* west;
		Space* up;
		Space* down;

		// text to describe a room
		std::string shortDesc;
		std::string longDesc;

		//pointer to a player present in a room
		Player* hero;

		//movement control
		virtual Space* move(); //return a pointer to a space the 
			//user wants to move to
		std::map<char,Space*> directions;
		std::vector<std::string> exits(); //return a vector of 
			//strings naming the valid exits from the room
		std::map<int,char> exitList;
		
		//inventory management
		std::list<Item*> roomItems; //container for items in a room
		void take(); //send an item from a space to a Player

		//menus
		std::map<std::string,std::string> verbList;
		virtual void generateMenu(); //build a list of possible
			//actions able to be displayed in a menu
		std::string getSelection(); // get the user's selected 
			//action from the console via a menu
		std::string selection; //hold the current action to take
		
		//set up cost for actions in the game
		static const int DEFAULT_COST = -1; //default cost to walk
			//to another room( in air)
	public:
		Space(); // default constructor
		virtual ~Space() = 0; //pure virtual destructor

		virtual Space* action(Player* currentPlayer); //returns the 
			//location of the Player after the selected action 
			//is taken accepts a ponter to a player object
			//representing the player currently in the room
		virtual void describeRoom(); //print a description of the 
			//room to the console
		
		//used for map creation
		void setNeighbor(char direction, Space* neighbor);
			//accepts a pointer to a space object and a 
			//character representing the direction it is from 
			//this space. valid characters are n,e,s,w,u,d and
		void addItem(Item* newItem); // add an item to a room
			//are mapped to the direction pointers
		
		//get/set methods
		std::string getShortDesc();
		std::string getLongDesc();
		void setShortDesc(std::string name);
		void setLongDesc(std::string description);
};
#endif
