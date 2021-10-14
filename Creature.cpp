#include "Utility.h"
#include "Creature.h"

Creature::Creature(int size, int numSides)
{
	body = sf::CircleShape(size, numSides);
	RandomColour();
}

void Creature::RandomColour()
{
	body.setFillColor(sf::Color(Utility::RandomInt(0, 255), Utility::RandomInt(0, 255), Utility::RandomInt(0, 255)));
}
