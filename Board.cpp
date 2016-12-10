#include <iostream>
#include "Board.h"
#include "utility.h"


Board::Board() {

	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			fields[x][y] = Side::NEUTRAL;
		}
	}
}


Side Board::getField(int x, int y) const {	// pass by value because Side is small, and we dont want the user to be able to change fields

	utility::assert_inside(x, 0, width - 1);
	utility::assert_inside(y, 0, height - 1);

	return fields[x][y];
}


bool Board::columnFull(int column) const {

	utility::assert_inside(column, 0, width - 1);

	return fields[column][0] != Side::NEUTRAL;
}


void Board::move(int column, Side side) {

	utility::assert_inside(column, 0, width - 1);
	utility::assert_false(columnFull(column));

	fields[column][cascade(column)] = side;
}


bool Board::boardFull() const {

	for (int x = 0; x < width; ++x) {
		if (fields[x][0] == Side::NEUTRAL) {
			return false;
		}
	}
	return true;
}


int Board::cascade(int column) const {

	utility::assert_inside(column, 0, width - 1);

	for (int row{ height - 1 }; row >= 0; --row) {
		if (fields[column][row] == Side::NEUTRAL) {
			return row;
		}
	}
	return height;
}

/*
Side Board::hasWinner() const {
	return Side::O;
}
*/

bool Board::winningMove(Move move) const {



	return true;
}