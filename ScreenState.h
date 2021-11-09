#pragma once
#include <vector>
#include <sstream>
#include "StackFSM.h"
#include <SFML/Graphics.hpp>

class Button;

class ScreenState
{
public:
	virtual void Initialise(sf::RenderWindow* window) = 0;
	virtual void Cleanup() = 0;


	virtual void HandleInput(StackFSM* screen, sf::RenderWindow* window, sf::Event* event) = 0;
	virtual void Update(StackFSM* screen, sf::RenderWindow* window) = 0;
	virtual void Render(StackFSM* screen, sf::RenderWindow* window) = 0;

	void ChangeState(StackFSM* screen, ScreenState* state) { screen->ChangeState(state); }

protected:
	ScreenState();
	std::vector<std::shared_ptr<Button>> buttons;
	int currentButton{ 0 };
	sf::Font font;
};

