#pragma once

#include "Side.h"


class Board {

public:

	Board();

	bool columnNotFull(int);
	bool isFull();
	void doMove(int, Side);

	Side getField(int, int);

	static const int width{ 4 };
	static const int height{ 4 };

private:

	Side fields[width][height];
	int cascade(int);

};