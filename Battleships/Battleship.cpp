#include "stdafx.h"
#include "Battleship.h"

namespace battleships
{

	Battleship::Battleship()
	{
		this->length = 4;
	}

	Battleship::Battleship(Coordinates start, Coordinates end)
	{
		this->length = 4;
		this->SetStartCoordinates(start);
		this->SetEndCoordinates(end);
	}

	Battleship::~Battleship()
	{
	}

}