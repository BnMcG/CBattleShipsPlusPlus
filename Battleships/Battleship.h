#pragma once
#include "Ship.h"

namespace battleships
{

	class Battleship : public battleships::Ship
	{
	public:
		Battleship();
		Battleship(Coordinates start, Coordinates end);
		~Battleship();
	};

}