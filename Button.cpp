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
}

bool Button::Hover(vector2D mousePos)
{
	sf::FloatRect bounds = rect.getGlobalBounds();
	if (mousePos.X > bounds.left && mousePos.X < bounds.left + bounds.width && mousePos.Y < bounds.top + bounds.height && mousePos.Y > bounds.top)
		return true;
	return false;
}

void Button::ChangeColour(sf::Color colour)
{
	rect.setFillColor(colour);
}