/*
 * Program Name: Final Project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Extension of the base Space class to describe a room with 
 * a with some disabled fans that need power supplied
 */

#ifndef FAN_ROOM_HPP
#define FAN_ROOM_HPP

#include "Space.hpp"
#include "Player.hpp"

class FanRoom : public Space
{
	private:
		virtual void generateMenu(); // build a list of possible 
			//actions to take able to be displayed in a menu
			//be taken by the player
		bool fanOn;
	public:
		FanRoom();
		~FanRoom();
		virtual void describeRoom(); // print a description of the
			//room to the console
		virtual Space* action(Player* currentPlayer); //returns the 
			//location of the Player after the selected action 
			//is taken accepts a ponter to a player object
			//representing the player currently in the room

};
#endif
