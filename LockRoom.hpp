/*
 * Program Name: Final Project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Extension of the base Space class to describe a room with 
 * locked doors that the player must open
 */

#ifndef LOCK_ROOM_HPP
#define LOCK_ROOM_HPP

#include "Space.hpp"
#include <map>
#include "Item.hpp"
#include <vector>
#include <string>

class LockRoom : public Space
{
	private:
		std::map<char, Space*> lockList; //maintain a list of the
			//locked doors and their directions
		virtual void generateMenu(); // build a list of possible 
			//actions to take able to be displayed in a menu
			//be taken by the player
		void unlock(); //allow the user to pick a door to unlock
			//from a console menu
		std::vector<std::string> locks(); //return a vector 
			//representing the directions with currently locked
			//doors
	public:
		LockRoom();
		~LockRoom();
		virtual void describeRoom(); // print a description of the
			//room to the console
		virtual Space* action(Player* currentPlayer); //returns the 
			//location of the Player after the selected action 
			//is taken accepts a ponter to a player object
			//representing the player currently in the room
		void lock(char dir); //lock the door in a direction

};
#endif
