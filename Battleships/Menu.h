#pragma once

#include <string>

class Menu
{
public:
	Menu();
	~Menu();
	bool GameShouldExit();
	virtual void RenderMenu() = 0;
	virtual void ProcessInput(std::string input) = 0;
protected:
	bool exit;
};