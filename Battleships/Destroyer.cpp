#include "stdafx.h"
#include "Destroyer.h"

namespace battleships
{

	Destroyer::Destroyer()
	{
		this->length = 2;
	}

	Destroyer::Destroyer(Coordinates start, Coordinates end)
	{
		this->length = 2;
		this->SetStartCoordinates(start);
		this->SetEndCoordinates(end);
	}

	Destroyer::~Destroyer()
	{
	}

}