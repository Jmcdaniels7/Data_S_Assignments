#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <map>
#include "set.h"

const int TOP_NUM = 8;

enum toppingType
{
	GRILLONION,
	RAWONION,
	TOMATO,
	LETTUCE,
	BACON,
	MUSHROOM,
	PICKLE,
	NOTOP
};

//we could make a map here to use at() for clang tidy
const std::string toppingStr[] = {"Grilled Onion",
								  "Raw Onion",
								  "Tomato",
								  "Lettuce",
								  "Bacon",
								  "Grilled Mushroom",
								  "Pickle",
								  "None"};
const toppingType toppingList[] = {
	GRILLONION,
	RAWONION,
	TOMATO,
	LETTUCE,
	BACON,
	MUSHROOM,
	PICKLE, NOTOP};

static std::map<toppingType, std::string> topToStr = {
	{GRILLONION, "Grilled Onion"},
	{RAWONION, "Raw Onion"},
	{TOMATO, "Tomato"},
	{LETTUCE, "Lettuce"},
	{BACON, "Bacon"},
	{MUSHROOM, "Grilled Mushroom"},
	{PICKLE, "Pickle"},
	{NOTOP, "None"}
};


class burger
{
public:
	burger(int numPatties);
	std::string getToppings();
	void addTopping(toppingType);
	std::string tostring();
	void setNumPatties(int num);
	int getNumPatties() const;

private:
	set<toppingType> toppings;
	//make a set 
	int numToppings;
	//This should come from the set

	int numPatties;
};
