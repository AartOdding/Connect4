#pragma once

#include "Side.h"


class Board {

public:

	Board();
	~Board();

	void draw();
	void drawNumbers();


	bool isValid(int);
	bool isFull();
	bool doMove(int, Side);

	static const int width{ 4 };
	static const int height{ 4 };

private:

	Side fields[width][height];
	int cascade(int);

};