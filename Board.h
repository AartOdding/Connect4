#pragma once

#include <array>
#include "Move.h"


typedef std::pair<int, int> Position;

class Board {

public:

	Board();

	void move(int, Side);	// use int, should return winner?

	bool columnFull(int)	const;
	bool boardFull()		const;
	bool winningMove(Move)	const;

	Side getField(int, int)	const;
	//Side hasWinner()		const;

	static const int width{ 4 };
	static const int height{ 4 };

private:

	std::array<std::array<Side, height>, width> fields;
	//std::pair<int, int> last_move;

	int cascade(int)		const;

};