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

	// Loop through each ship in the player's fleet and randomly position it on the board
	// First making sure that there is enough room to do so
	void Fleet::PositionShips()
	{
		// Loop through ships
		for (int i = 0; i < ships.size(); i++)
		{
			// Keep going until we find somewhere to place the ship
			bool placed = false;
			while (!placed)
			{
				// Randomly pick somewhere on the board
				int posX = this->RandInt();
				int posY = this->RandInt();

				// If there is enough room horizontally on the board, place the ship horizontally here
				if ((10 - posX) >= ships[i].GetLength())
				{
					ships[i].SetStartCoordinates(Coordinates(posX, posY));
					ships[i].SetEndCoordinates(Coordinates(posX + ships[i].GetLength(), posY));
					placed = true;
				}
				// If there is enough room on the  board vertically, place the ship here
				else if ((10 - posY) >= ships[i].GetLength())
				{
					ships[i].SetStartCoordinates(Coordinates(posX, posY));
					ships[i].SetEndCoordinates(Coordinates(posX, posY + ships[i].GetLength()));
					placed = true;
				}

				// If neither of the above were true, we'll loop through again
			}
		}
	}

	// Check whether or not there is a ship at the given coordinates.
	bool Fleet::IsShipAtPosition(Coordinates coords)
	{
		// Since we're not changing anything we can use a for each loop instead of a for loop and the size of the collection
		// For some reason changing things in for each loops don't stick. Probably to do with pointers
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

	/// Below we return each type of ship individually

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

	// Return the vector of all the ships in the fleet
	std::vector<Ship> Fleet::GetShips()
	{
		return this->ships;
	}

	Fleet::~Fleet()
	{
	}
}