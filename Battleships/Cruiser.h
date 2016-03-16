#pragma once
#include "Ship.h"

namespace battleships
{

	class Cruiser : public battleships::Ship
	{
	public:
		Cruiser();
		Cruiser(Coordinates start, Coordinates end);
		~Cruiser();
	};

}