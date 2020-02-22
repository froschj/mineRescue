/*
 * Program Name: final project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: derived items to be used in a text adventure game
 */

#include "Item.hpp"
#include <string>
#include "items.hpp"

const std::string Screwdriver::NAME = "Screwdriver";
const std::string Screwdriver::DESCRIPTION = "a fairly long flat-head screwdriver";

/*
 * description: pass paramenters to base class constructor
 */
Screwdriver::Screwdriver() : Item(Screwdriver::NAME, 
	Screwdriver::DESCRIPTION)
{
}
/*
 * description: placeholder
 */
Screwdriver::~Screwdriver()
{
}

const std::string Wrench::NAME = "Wrench";
const std::string Wrench::DESCRIPTION = "a large monkey wrench";

/*
 * description: pass paramenters to base class constructor
 */
Wrench::Wrench() : Item(Wrench::NAME, 
	Wrench::DESCRIPTION)
{
}
/*
 * description: placeholder
 */
Wrench::~Wrench()
{
}

const std::string JumperCables::NAME = "Jumper Cables";
const std::string JumperCables::DESCRIPTION = "a set of jumper cables";

/*
 * description: pass paramenters to base class constructor
 */
JumperCables::JumperCables() : Item(JumperCables::NAME, 
	JumperCables::DESCRIPTION)
{
}
/*
 * description: placeholder
 */
JumperCables::~JumperCables()
{
}

const std::string Pliers::NAME = "Pliers";
const std::string Pliers::DESCRIPTION = "a pair of slip-joint pliers";

/*
 * description: pass paramenters to base class constructor
 */
Pliers::Pliers() : Item(Pliers::NAME, 
	Pliers::DESCRIPTION)
{
}
/*
 * description: placeholder
 */
Pliers::~Pliers()
{
}
