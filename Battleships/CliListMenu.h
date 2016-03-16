#pragma once

#include "Menu.h"
#include "Fleet.h"

class CliListMenu : public Menu
{
public:
	CliListMenu(battleships::Fleet *playerOneFleet, battleships::Fleet *playerTwoFleet, std::vector<Coordinates> *playerOneShots, std::vector<Coordinates> *playerTwoShots);
	void RenderMenu();
	void ProcessInput(std::string input);
	~CliListMenu();
private:
	battleships::Fleet *playerOneFleet;
	battleships::Fleet *playerTwoFleet;
	std::vector<Coordinates> *playerOneShots; // Shots fired by player one
	std::vector<Coordinates> *playerTwoShots; // Shots fired by player two
};

