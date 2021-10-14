#pragma once
#include <SFML/Graphics.hpp>

class Creature
{
public:
	Creature(int size, int numSides);

	sf::CircleShape body;
	sf::CircleShape eye;

	void RandomColour();
	void Move(int forward, int back, int left, int right);
	void Rotate(int angle);
};

