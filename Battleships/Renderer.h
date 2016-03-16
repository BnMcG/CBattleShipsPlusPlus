#pragma once

#include "Fleet.h"

// Designed as an abstract class that can be used so we can render the game in different ways if we wanted to
// This class can be inherited and then the game can be rendered in any way we like, since the positions of the
// ships and shots attempted is totally independent from how they are displayed (IE: it's not all stored in one large array)
class Renderer
{
public:
	Renderer();
	~Renderer();
	virtual void RenderGame(battleships::Fleet *fOne, battleships::Fleet *fTwo, std::vector<Coordinates> *pOneShots, std::vector<Coordinates> *pTwoShots) = 0;
};

