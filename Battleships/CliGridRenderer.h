#pragma once

#include "Renderer.h"

// Implementation of the Renderer class that renders the game in two grids
// One for the player and one for the AI. The player can't see the AI's 
// ship positions
class CliGridRenderer : public Renderer
{
// Inherit constructor from parent (since C++ 11)
// This lets us get the fleet to use in the renderer (we do this in the parent class)
public:
	CliGridRenderer();
	void RenderGame(battleships::Fleet *fOne, battleships::Fleet *fTwo, std::vector<Coordinates> *pOneShots, std::vector<Coordinates> *pTwoShots);
private:
	bool ShotsAtPosition(std::vector<Coordinates> *shots, Coordinates pos);
	char letters[11];
};

