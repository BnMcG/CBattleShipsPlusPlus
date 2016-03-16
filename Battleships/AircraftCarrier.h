#pragma once
#include "Ship.h"

namespace battleships
{
	class AircraftCarrier : public Ship
	{
	public:
		AircraftCarrier();
		AircraftCarrier(Coordinates start, Coordinates end);
		~AircraftCarrier();
	};
}
