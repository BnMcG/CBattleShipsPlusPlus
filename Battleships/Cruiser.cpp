#include "stdafx.h"
#include "Cruiser.h"

namespace battleships
{

	Cruiser::Cruiser()
	{
		this->length = 3;
	}

	Cruiser::Cruiser(Coordinates start, Coordinates end)
	{
		this->SetEndCoordinates(end);
		this->SetStartCoordinates(start);
		this->length = 3;
	}


	Cruiser::~Cruiser()
	{
	}

}