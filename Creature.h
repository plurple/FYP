#pragma once
#include <SFML/Graphics.hpp>

class Creature
{
public:
	Creature(int size, int numSides);

	sf::CircleShape body;

	void RandomColour();

};

