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
		std::vector<Ship> GetShips();
		bool IsShipAtPosition(Coordinates pos);
	private:
		std::vector<Ship> ships;
		AircraftCarrier aircraftCarrier;
		Battleship battleship;
		Cruiser cruiser;
		Destroyer destroyer;
		Submarine submarine;
		void PositionShips();
		int RandInt();
	};

}