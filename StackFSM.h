#pragma once
#include "Utility.h"
#include <SFML/Graphics.hpp>

class ScreenState;

class StackFSM
{
public:
	StackFSM() {}
	~StackFSM();

	void Run();

	void ChangeState(ScreenState* state);
	void PushState(ScreenState* state);
	void PopState();

private:
	std::vector<ScreenState*> states;
	sf::RenderWindow* window{ nullptr };
	sf::Event* event{ nullptr };

	void Initialise();
	void Cleanup();

	void HandleInput();
	void Update();
	void Render();
	Utility::DWORD lastFrameUpdateTime{ 0 };
};

