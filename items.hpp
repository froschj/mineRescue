/*
 * Program Name: final project
 * Author: Jon Frosch
 * Date: 2019-06-11
 * Description: derived items to be used in a text adventure game
 */
#ifndef ITEMS_HPP
#define ITEMS_HPP

#include "Item.hpp"
#include <string>

class Screwdriver : public Item
{
	private:
		static const std::string NAME;
		static const std::string DESCRIPTION;
	public:
		Screwdriver();
		~Screwdriver();
};

class Wrench : public Item
{
	private:
		static const std::string NAME;
		static const std::string DESCRIPTION;
	public:
		Wrench();
		~Wrench();
};

class JumperCables : public Item
{
	private:
		static const std::string NAME;
		static const std::string DESCRIPTION;
	public:
		JumperCables();
		~JumperCables();
};


class Pliers : public Item
{
	private:
		static const std::string NAME;
		static const std::string DESCRIPTION;
	public:
		Pliers();
		~Pliers();
};
#endif
