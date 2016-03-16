#pragma once
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

