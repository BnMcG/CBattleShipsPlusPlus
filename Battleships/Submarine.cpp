#include "stdafx.h"
#include "Submarine.h"

namespace battleships
{

	Submarine::Submarine()
	{
		this->length = 1;
	}

	Submarine::Submarine(Coordinates start, Coordinates end)
	{
		this->length = 1;
		this->SetStartCoordinates(start);
		this->SetEndCoordinates(end);
	}

	Submarine::~Submarine()
	{
	}

}