/*
 * Program Name: final project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: class to manage a text adventure game
 */

#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Space.hpp"
#include "Item.hpp"
#include "Corridor.hpp"
#include "items.hpp"
#include "ToolRoom.hpp"
#include "LockRoom.hpp"
#include "FanRoom.hpp"
#include "ValveRoom.hpp"

/*
 * Description: construct the map in which the game will take place and 
 * place all items to be found. Also set up the starting location
 */
Game::Game()
{
	//set up the map, placing items
	for (int i = 0; i < 4; ++i)
	{
		roomList.push_back(new Corridor);
	}
	
	for (int i = 4; i < 6; ++i)
	{
		roomList.push_back(new LockRoom);
	}
	
	roomList.push_back(new ToolRoom);
	roomList.push_back(new ValveRoom);
	roomList.push_back(new FanRoom);

	std::string startInfo;

	//setup for the start room
	startInfo = roomList.at(0)->getLongDesc();
	startInfo += "\nthe sealed airlock to the saferoom is here";
	roomList.at(0)->setLongDesc(startInfo);
	startLocation = roomList.at(0);
	location = startLocation;

	//setup map, assign all spaces their correct neighbors
	roomList.at(0)->setNeighbor('e',roomList.at(1));

	roomList.at(1)->setNeighbor('w',roomList.at(0));
	roomList.at(1)->setNeighbor('n',roomList.at(6));
	roomList.at(1)->setNeighbor('e',roomList.at(7));

	roomList.at(2)->setNeighbor('w',roomList.at(4));
	roomList.at(2)->setNeighbor('u',roomList.at(3));
	
	roomList.at(3)->setNeighbor('d',roomList.at(2));
	roomList.at(3)->setNeighbor('n',roomList.at(5));

	roomList.at(4)->setNeighbor('n',roomList.at(7));
	roomList.at(4)->setNeighbor('e',roomList.at(2));

	roomList.at(5)->setNeighbor('s',roomList.at(3));
	roomList.at(5)->setNeighbor('n',roomList.at(8));

	roomList.at(6)->setNeighbor('s',roomList.at(1));

	roomList.at(7)->setNeighbor('w',roomList.at(1));
	roomList.at(7)->setNeighbor('s',roomList.at(4));
	
	roomList.at(8)->setNeighbor('s',roomList.at(5));

	//place items
	itemList.push_back(new Screwdriver);
	itemList.push_back(new Wrench);
	itemList.push_back(new Pliers);

	for (auto it = itemList.begin(); it != itemList.end(); ++it)
	{
		static_cast<ToolRoom*>(roomList.at(6))->addToCabinet(*it);
	}
	
	itemList.push_back(new JumperCables);
	roomList.at(6)->addItem(itemList.at(3));

	//lock appropriate doors
	static_cast<LockRoom*>(roomList.at(4))->lock('e');
	static_cast<LockRoom*>(roomList.at(5))->lock('n');

}

/*
 * Description: free the memory allocated for all the spaces and items
 */
Game::~Game()
{
	location = nullptr;
	
	for(auto it = roomList.begin(); it != roomList.end(); ++it)
	{
		delete *it;
	}

	for(auto it = itemList.begin(); it != itemList.end(); ++it)
	{
		delete *it;
	}
}

/*
 * Description: control the flow of the game. calls the current spaces 
 * action function to give a list of actions avalaible to the player, and 
 * gets the space to be used next. After each action, checks the player 
 * for game end conditions. an appropriate message is printed if the game 
 * ends
 */
void Game::playGame()
{
	//welcome message
	std::cout << "Welcome to the Mine Rescuer game. An accident in\n"
		<< "the mine has caused a pipe to burst filling the mine\n"
		<< "with toxic gas. Luckily, you have your breathing gear\n"
		<< "handy. Before your limited supply of air runs out,\n"
		<< "you must shut off the gas flow and turn on the\n"
		<< "ventilation fans to clear the air so that your fellow\n"
		<< "miners can be rescued from their saferoom" << std::endl;

	//play the game until win/loss/quit
	while (rescuer.isAlive() && !rescuer.isWinner() 
		&& !rescuer.hasQuit())
	{
		std::cout << std::endl;
		location->describeRoom();
		std::cout << "Air remaining: " << rescuer.getAir() 
			<< std::endl << std::endl;
		location = location->action(&rescuer);
	}

	//display appropriate status message
	if (rescuer.isWinner())
	{
		std::cout << "The ventilation fans succeed in clearing\n"
			<< "the last of the toxic gas, and the day is\n"
			<< "saved! Congratulations, you're a hero! The\n"
			<< "other miners can be rescued from the saferoom\n"
			<< "and all lives are saved." << std::endl;
	}
	else if (!(rescuer.isAlive()))
	{
		std::cout << "Your air supply runs out and you succumb to\n"
			<< "the toxic fumes. Hopefully another member of\n"
			<< "the rescue team can complete your mission"
			<< std::endl;
	}
	else
	{
		std::cout << "Exited this playthrough" << std::endl;
	}
	std::cout << std::endl;
}
