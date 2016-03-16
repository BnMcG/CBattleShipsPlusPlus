#pragma once

#include "Renderer.h"

class CliGridRenderer : public Renderer
{
// Inherit constructor from parent (since C++ 11)
// This lets us get the fleet to use in the renderer (we do this in the parent class)
public:
	CliGridRenderer();
	void RenderGame(battleships::Fleet *fOne, battleships::Fleet *fTwo); 
private:
	char letters[11];
};

