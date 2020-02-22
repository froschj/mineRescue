/*
 * Program Name: Final Project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Extension of the base Space class to describe a room with 
 * a valve that can be shut using a tool
 */

#ifndef VALVE_ROOM_HPP
#define VALVE_ROOM_HPP

#include "Space.hpp"
#include "Player.hpp"

class ValveRoom : public Space
{
	private:
		virtual void generateMenu(); // build a list of possible 
			//actions to take able to be displayed in a menu
			//be taken by the player
		bool valveClosed;
	public:
		ValveRoom();
		~ValveRoom();
		virtual void describeRoom(); // print a description of the
			//room to the console
		virtual Space* action(Player* currentPlayer); //returns the 
			//location of the Player after the selected action 
			//is taken accepts a ponter to a player object
			//representing the player currently in the room

};
#endif
