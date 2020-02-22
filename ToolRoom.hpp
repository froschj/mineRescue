/*
 * Program Name: Final Project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Extension of the base Space class to describe a room with 
 * a cabinet that conceals items until the player opens it.
 */

#ifndef TOOL_ROOM_HPP
#define TOOL_ROOM_HPP

#include "Space.hpp"
#include <list>
#include "Item.hpp"

class ToolRoom : public Space
{
	private:
		bool cabinetOpened;
		std::list<Item*> cabinetItems;
		virtual void generateMenu(); // build a list of possible 
			//actions to take able to be displayed in a menu
			//be taken by the player
	public:
		ToolRoom();
		~ToolRoom();
		void addToCabinet(Item* newItem); //add the item pointed 
			//to by newItem to the cabinet container
		virtual void describeRoom(); // print a description of the
			//room to the console
		virtual Space* action(Player* currentPlayer); //returns the 
			//location of the Player after the selected action 
			//is taken accepts a ponter to a player object
			//representing the player currently in the room

};
#endif
