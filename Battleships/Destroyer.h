#pragma once
#include "Ship.h"

namespace battleships
{

	class Destroyer : public battleships::Ship
	{
	public:
		Destroyer();
		Destroyer(Coordinates start, Coordinates end);
		~Destroyer();
	};

}
