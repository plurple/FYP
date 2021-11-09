#pragma once
#include "ScreenState.h"

class Creature;

class NewEnvironment : public ScreenState
{
public:
	~NewEnvironment();

	void Initialise(sf::RenderWindow* window);
	void Cleanup();

	void HandleInput(StackFSM* screen, sf::RenderWindow* window, sf::Event* event);
	void Update(StackFSM* screen, sf::RenderWindow* window);
	void Render(StackFSM* screen, sf::RenderWindow* window);

	static NewEnvironment* Instance() { return &environment; }

protected:
	NewEnvironment() {}

private:
	static NewEnvironment environment;

	std::vector<std::shared_ptr<Creature>> creatures;

};


