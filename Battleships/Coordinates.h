#pragma once

// Essentially a wrapper to store x and y values in since we use them so often.
class Coordinates
{
public:
	Coordinates();
	Coordinates(int x, int y);

	~Coordinates();

	int GetX();
	int GetY();

	void SetX(int x);
	void SetY(int y);

private:
	int x;
	int y;
};

