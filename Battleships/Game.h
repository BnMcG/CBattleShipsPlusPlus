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
	void SetupCliMenu(); // Method to add fleets and attempted shots to the CLI menu system, add a method like this for all menu systems you want to use
private:
	Renderer *renderer; // Rendering system
	Menu *menu; // Menu system
	battleships::Fleet *playerOneFleet;
	battleships::Fleet *playerTwoFleet;
	std::vector<Coordinates> *playerOneShots; // Shots fired by P1
	std::vector<Coordinates> *playerTwoShots; // Shots fired by P2

};

