#include "Utility.h"
#include "Creature.h"
#include "Vector2D.h"

Creature::Creature(int size, int numSides)
{
	body = sf::CircleShape(size, numSides);
	body.setOrigin(size, size);
	RandomColour();
	size *= .2;
	eye = sf::CircleShape(size, 30);
	eye.setOrigin(size, size);
	eye.setFillColor(sf::Color::White);
}

void Creature::RandomColour()
{
	body.setFillColor(sf::Color(Utility::RandomInt(0, 255), Utility::RandomInt(0, 255), Utility::RandomInt(0, 255)));
}

#define PI 3.14159265

void Creature::Move(int forward, int back, int left, int right)
{
	vector2D speed(right - left, forward - back);
	vector2D direction;
	direction.X = (float)cos(body.getRotation()*PI/180);
	direction.Y = (float)sin(body.getRotation()*PI/180);
	if (direction.length() > 0) {
		direction = direction.normalize();
	}

	/*multiply the amount you are going in the magnitude of the cardinal 4 directions by the facing of the
	creature so that it moves forward, back, left and right depending on how the creature is facing*/
	body.move(speed.Y * direction.Y + speed.X * direction.X, speed.X * direction.Y - speed.Y * direction.X);
	eye.move(speed.Y * direction.Y + speed.X * direction.X, speed.X * direction.Y - speed.Y * direction.X);
}

void Creature::Rotate(int angle)
{
	body.rotate(angle);
	eye.rotate(angle);
}
