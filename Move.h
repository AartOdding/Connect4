#pragma once

enum class Side {
	NEUTRAL,
	X,
	O
};


struct Move {
	int x;
	int y;
	Side side;
};