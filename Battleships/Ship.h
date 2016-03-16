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

		// either the X or Y value should be the same in both start and end coordinates
		// This is because ships can't move diagonally
		Coordinates GetStartCoordinates(); // Where this ship starts
		Coordinates GetEndCoordinates(); // Where this ship ends

		void SetStartCoordinates(Coordinates c);
		void SetEndCoordinates(Coordinates c);

		bool GetSunk(); // Has this ship been sunk
		void SetSunk(bool s); // Sink this ship / Or unsink it, Davey Jones style.

		int GetLength(); // Find out how long ths ship is

	private:
		Coordinates startCoordinates;
		Coordinates endCoordinates;
		bool sunk; // Sunk or not status
	protected:
		int length; // Length
	};

}