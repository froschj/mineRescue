/*
 * Program Name: final project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: Simple room with no special interactions for use in a text
 * adventure game. requires the Space class to inheirit from
 */

#ifndef CORRODOR_HPP
#define CORRIDOR_HPP

#include "Space.hpp"

class Corridor : public Space
{
	public:
		Corridor(); //default constructor
		~Corridor(); //destructor
};

#endif
