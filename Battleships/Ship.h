#pragma once
#include "Coordinates.h"

namespace battleships 
{
	/**
	 * Ship class which outlines the basics needed for every ship, including its starting and ending coordinates on the map, and its length. This data can be used
	 * to calculate its position on the grid. Start and end coordinates must have either the same x or the same y value, as ships can't be placed diagonally.
	 */

	class Ship
	{
	public:
		Ship();
		~Ship();

		Coordinates GetStartCoordinates();
		Coordinates GetEndCoordinates();

		void SetStartCoordinates(Coordinates c);
		void SetEndCoordinates(Coordinates c);

		bool GetSunk();
		void SetSunk(bool s);

		int GetLength();

	private:
		Coordinates startCoordinates;
		Coordinates endCoordinates;
		bool sunk;
	protected:
		int length;
	};

}