/*
 * Program Name: final project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Driver function to run a text adventure game in the console
 * through a game object. allows the player to retry or quit when the game 
 * ends
 */

#include "Game.hpp"
#include <string>
#include "optionMenu.hpp"
#include <iostream>

bool keepPlaying(); //allow the player to restart the game (return true)
	//or exit the program (return false).

/*
 * Description: describes the game and instantiates a game object to allow
 * the player to play the game. after the game exits, allow the player to 
 * elect to either play again or quit
 */
int main()
{
	Game* mineRescue = nullptr;

	do
	{
		mineRescue = new Game;
		mineRescue->playGame();
		delete mineRescue;
	} while (keepPlaying());

	return 0;
}

/*
 * Description: allow the player to restart the game (return true)
 * or exit the program (return false).
 */
bool keepPlaying()
{
	const int numOptions = 2;
	std::string options[numOptions];
	options[0] = "Play Again";
	options[1] = "Exit Program";
	bool result = false;
	
	if (optionMenu(options, numOptions) == 0)
	{
		result = true;
	}
	
	return result;
}
