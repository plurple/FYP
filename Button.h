#pragma once
#include <string>
#include "vector2D.h"
#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
public:
	Button(vector2D pos, sf::RectangleShape rectangle, sf::Text tex);
	bool Hover(vector2D mousePos);
	void ChangeColour(sf::Color);

	std::string name;
	vector2D position;
	sf::RectangleShape rect;
	sf::Color colour;
	sf::Text text;
};

