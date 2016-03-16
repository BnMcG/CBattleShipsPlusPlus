#include "stdafx.h"
#include "Fleet.h"
#include <time.h>

#include <iostream>

namespace battleships
{

	Fleet::Fleet()
	{
		this->ships = std::vector<Ship>();
		this->aircraftCarrier = AircraftCarrier();
		this->battleship = Battleship();
		this->cruiser = Cruiser();
		this->destroyer = Destroyer();
		this->submarine = Submarine();

		this->ships.push_back(aircraftCarrier);
		this->ships.push_back(battleship);
		this->ships.push_back(cruiser);
		this->ships.push_back(destroyer);
		this->ships.push_back(submarine);

		this->PositionShips();
	}

	int Fleet::RandInt()
	{
		return 1 + (rand() % (int)(10 - 1 + 1));
	}

	void Fleet::PositionShips()
	{
		for (int i = 0; i < ships.size(); i++)
		{
			bool placed = false;
			while (!placed)
			{
				int posX = this->RandInt();
				int posY = this->RandInt();

				if ((10 - posX) >= ships[i].GetLength())
				{
					ships[i].SetStartCoordinates(Coordinates(posX, posY));
					ships[i].SetEndCoordinates(Coordinates(posX + ships[i].GetLength(), posY));
					placed = true;
				}
				else if ((10 - posY) >= ships[i].GetLength())
				{
					ships[i].SetStartCoordinates(Coordinates(posX, posY));
					ships[i].SetEndCoordinates(Coordinates(posX, posY + ships[i].GetLength()));
					placed = true;
				}
			}
		}
	}

	bool Fleet::IsShipAtPosition(Coordinates coords)
	{
		for each(Ship ship in this->ships)
		{
			// Ship is vertical
			if (ship.GetStartCoordinates().GetX() == ship.GetEndCoordinates().GetX())
			{
				// Check if x coordinate matches, and if so that the given coordinate is within the correct range vertically (IE: not on the same line, but 5 grid spaces below the ship)
				if (coords.GetX() == ship.GetStartCoordinates().GetX() && (coords.GetY() >= ship.GetStartCoordinates().GetY() && coords.GetY() <= ship.GetEndCoordinates().GetY()))
				{
					return true;
				}
			}
			// Ship is horizontal
			else
			{
				// Check if y coordinate matches, and if so that the given coordinate is within the correct range horizontally (IE: not on the same line, but 5 grid spaces to the right the ship)
				if (coords.GetY() == ship.GetStartCoordinates().GetY() && (coords.GetX() >= ship.GetStartCoordinates().GetX() && coords.GetX() <= ship.GetEndCoordinates().GetX()))
				{
					return true;
				}
			}
		}

		// If we got to this point and haven't returned true, it's a blank space
		return false;
	}

	AircraftCarrier Fleet::GetAircraftCarrier()
	{
		return this->aircraftCarrier;
	}

	Battleship Fleet::GetBattleship()
	{
		return this->battleship;
	}

	Cruiser Fleet::GetCruiser()
	{
		return this->cruiser;
	}

	Destroyer Fleet::GetDestroyer()
	{
		return this->destroyer;
	}

	Submarine Fleet::GetSubmarine()
	{
		return this->submarine;
	}

	std::vector<Ship> Fleet::GetShips()
	{
		return this->ships;
	}

	Fleet::~Fleet()
	{
	}
}