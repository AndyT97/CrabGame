#pragma once
class Worm
{
	unsigned int sprite;
	float x, y;

public:
	Worm();

	void update();
	float get_x() const;
	float get_y() const;
};

