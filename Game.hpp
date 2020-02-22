/*
 * Program Name: final project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: class to manage a text adventure game
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"
#include "Player.hpp"
#include <vector>
class Game
{
	private:
		Space *location; //hold the player's current location
		Space *startLocation; //handle to access starting room
		Player rescuer;
		std::vector<Space*> roomList; //list of rooms in the world
		std::vector<Item*> itemList; //list of items in the world

	public:
		Game(); //create a new game and build the world
		~Game(); //free all memory
		void playGame(); //run a game
};
#endif
