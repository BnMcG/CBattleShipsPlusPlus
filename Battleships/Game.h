#pragma once
#include "Renderer.h"
#include "Menu.h"

class Game
{
public:
	Game();
	// Pointer required since menu is an abstract class
	//
	// Pointers anywhere are a threat to code everywhere. 
	// Martin Luther King, Jr.
	Game(Renderer *r);
	void Start();
	~Game();
	battleships::Fleet *GetPlayerOneFleet();
	battleships::Fleet *GetPlayerTwoFleet();
	std::vector<Coordinates> *GetPlayerOneShots();
	std::vector<Coordinates> *GetPlayerTwoShots();
	void SetupCliMenu();
private:
	Renderer *renderer;
	Menu *menu;
	battleships::Fleet *playerOneFleet;
	battleships::Fleet *playerTwoFleet;
	std::vector<Coordinates> *playerOneShots;
	std::vector<Coordinates> *playerTwoShots;

};

