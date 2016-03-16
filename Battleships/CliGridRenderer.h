#pragma once

#include "Renderer.h"

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

