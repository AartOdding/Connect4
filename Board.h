#pragma once

#include "Side.h"


class Board {

public:

	Board();

	bool columnNotFull(int);
	bool isFull();
	void doMove(int, Side);

	Side getField(int, int);
	Side hasWinner();

	static const int width{ 4 };
	static const int height{ 4 };

	static int cascade(Board&, int);

private:

	Side fields[width][height];

};