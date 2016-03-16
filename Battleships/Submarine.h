#pragma once
#include "Ship.h"

namespace battleships
{

	class Submarine : public battleships::Ship
	{
	public:
		Submarine();
		Submarine(Coordinates start, Coordinates end);
		~Submarine();
	};

}