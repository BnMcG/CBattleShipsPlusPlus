#include "stdafx.h"
#include "Game.h"
#include "CliListMenu.h"

Game::Game()
{
	this->playerOneFleet = new battleships::Fleet();
	this->playerTwoFleet = new battleships::Fleet();
}

Game::Game(Renderer *r)
{
	// Setup the player fleets and empty vectors of attempted shots
	this->playerOneFleet = new battleships::Fleet();
	this->playerTwoFleet = new battleships::Fleet();
	this->playerOneShots = new std::vector<Coordinates>;
	this->playerTwoShots = new std::vector<Coordinates>;
	this->renderer = r;
}

// Launch the main game loop
// 
void Game::Start()
{
	// Keep looping until the user wants to exit the game
	while (!menu->GameShouldExit())
	{
		// Render the boards using our chosen renderer
		renderer->RenderGame(this->GetPlayerOneFleet(), this->GetPlayerTwoFleet(), this->playerOneShots, this->playerTwoShots);
		// Render the menu using the chosen menu system
		menu->RenderMenu();
	}
}

battleships::Fleet *Game::GetPlayerOneFleet()
{
	return this->playerOneFleet;
}

battleships::Fleet *Game::GetPlayerTwoFleet()
{
	return this->playerTwoFleet;
}

std::vector<Coordinates> *Game::GetPlayerOneShots()
{
	return this->playerOneShots;
}

std::vector<Coordinates> *Game::GetPlayerTwoShots()
{
	return this->playerTwoShots;
}

// Setup a CLI menu with pointers to the two fleets and attempted shots
void Game::SetupCliMenu()
{
	this->menu = new CliListMenu(this->playerOneFleet, this->playerTwoFleet, this->playerOneShots, this->playerTwoShots);
}

Game::~Game()
{
}
