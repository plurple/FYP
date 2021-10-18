#pragma once
#include <string>
#include "vector2D.h"
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(vector2D pos, sf::RectangleShape rectangle, sf::Text tex);

	std::string name;
	vector2D position;
	sf::RectangleShape rect;
	sf::Color colour;
	sf::Text text;
};

