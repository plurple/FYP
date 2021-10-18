#include "Button.h"
#include "Utility.h"


Button::Button(vector2D pos, sf::RectangleShape rectangle, sf::Text tex)
	: position(pos), rect(rectangle) , text(tex)
{
	name = text.getString();
	rect.setPosition(position.X, position.Y);
	rect.setFillColor(sf::Color::Cyan);
	text.setPosition(position.X, position.Y);
	text.setFillColor(sf::Color::Black);
};
