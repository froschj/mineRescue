/*
 * Program Name: final project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: abstract class defining items that can be found in a text 
 * adevnture game
 */

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
class Item
{
	protected:
		std::string name;
		std::string description;
		Item(std::string newName, std::string newDesc);
	public:
		Item();
		virtual ~Item() = 0; //make this class abstract
		
		//get/set methods
		std::string getName();
		void setName(std::string newName);
		std::string getDescription();
		void setDescription(std::string newDesc);
};

#endif
