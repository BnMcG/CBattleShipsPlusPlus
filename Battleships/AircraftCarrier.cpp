#include "stdafx.h"
#include "AircraftCarrier.h"

namespace battleships
{
	AircraftCarrier::AircraftCarrier()
	{
		this->length = 5;
	}

	AircraftCarrier::AircraftCarrier(Coordinates start, Coordinates end)
	{
		this->SetStartCoordinates(start);
		this->SetEndCoordinates(end);
		this->length = 5;
	}


	AircraftCarrier::~AircraftCarrier()
	{
	}
}
