#include "stdafx.h"
#include "Ship.h"

namespace battleships 
{
	Ship::Ship()
	{
		this->sunk = false;
	}

	int Ship::GetLength()
	{
		return this->length;
	}

	bool Ship::GetSunk()
	{
		return this->sunk;
	}

	void Ship::SetSunk(bool s)
	{
		this->sunk = s;
	}

	void Ship::SetStartCoordinates(Coordinates start)
	{
		this->startCoordinates = start;
	}

	void Ship::SetEndCoordinates(Coordinates end)
	{
		this->endCoordinates = end;
	}

	Coordinates Ship::GetStartCoordinates()
	{
		return this->startCoordinates;
	}

	Coordinates Ship::GetEndCoordinates()
	{
		return this->endCoordinates;
	}

	Ship::~Ship()
	{
	}
}