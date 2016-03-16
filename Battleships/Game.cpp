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
	while (!menu->GameShouldExit())
	{
		renderer->RenderGame(this->GetPlayerOneFleet());
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

void Game::SetupCliMenu()
{
	this->menu = new CliListMenu(this->playerOneFleet, this->playerTwoFleet, this->playerOneShots, this->playerTwoShots);
}

Game::~Game()
{
}
