#pragma once

#include <vector>

#include "Ship.h"
#include "AircraftCarrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"

namespace battleships
{

	class Fleet
	{
	public:
		Fleet();
		~Fleet();

		AircraftCarrier GetAircraftCarrier();
		Battleship GetBattleship();
		Cruiser GetCruiser();
		Destroyer GetDestroyer();
		Submarine GetSubmarine();
		std::vector<Ship> GetShips(); // Method to get all the ships in the fleet
		bool IsShipAtPosition(Coordinates pos); // Method to check whether a ship is at the given position
	private:
		std::vector<Ship> ships;
		AircraftCarrier aircraftCarrier;
		Battleship battleship;
		Cruiser cruiser;
		Destroyer destroyer;
		Submarine submarine;
		void PositionShips(); // Method to position ships on board
		int RandInt(); // Method to generate random integer
	};

}