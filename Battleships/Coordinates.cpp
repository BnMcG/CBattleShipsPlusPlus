#include "stdafx.h"
#include "Coordinates.h"


Coordinates::Coordinates()
{
	this->x = 0;
	this->y = 0;
}

Coordinates::Coordinates(int x, int y)
{
	this->x = 0;
	this->y = 0;

	this->x = x;
	this->y = y;
}

int Coordinates::GetX()
{
	return this->x;
}

int Coordinates::GetY()
{
	return this->y;
}

void Coordinates::SetX(int x)
{
	this->x = x;
}

void Coordinates::SetY(int y)
{
	this->y = y;
}


Coordinates::~Coordinates()
{
}
