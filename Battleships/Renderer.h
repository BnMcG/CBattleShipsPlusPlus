#pragma once

#include "Fleet.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	virtual void RenderGame(battleships::Fleet *fOne, battleships::Fleet *fTwo) = 0;
};

