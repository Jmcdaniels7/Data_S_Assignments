#include "burger.h"
#include "set.h"

burger::burger(int numPatties)
{
	setNumPatties(numPatties);
}

std::string burger::getToppings()
{
	// iterate over the set and add to c
	std::string c;
	// this needs to be set to the first item in the set toppings but I have no way to represent that right now

	auto it = toppings.begin();

	c = toppingStr[toppingList[it.next()]];

	while(it.hasNext())
	{
		// each topping in the set will be added to C
		c += ", " + toppingStr[toppingList[it.next()]];
	}
	return c;
}

void burger::addTopping(toppingType topping)
{
	toppings.insert(topping);

}

void burger::setNumPatties(int num)
{
	if (num > 0)
		numPatties = num;
	else
		std::cout << "The number of patties should be greater than 0." << std::endl;
}

std::string burger::tostring()
{
	std::ostringstream out;
	out << std::setprecision(2) << std::fixed << std::showpoint;
	out << "Number of patties: " << numPatties << std::endl;
	out << "Toppings: " << getToppings();

	return out.str();
}
