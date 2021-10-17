#pragma once
#include <string>
#include "vector2D.h"
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(std::string uniqueName, vector2D pos, sf::RectangleShape rectangle) 
		: name(uniqueName), position(pos), rect(rectangle) {};

	std::string name;
	vector2D position;
	sf::RectangleShape rect;
	sf::Color colour;
};

