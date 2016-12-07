#include <iostream>
#include <stdexcept>
#include "Board.h"
#include "utility.h"


Board::Board() {
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			fields[x][y] = Side::NEUTRAL;
		}
	}
}


// pass by value because Side is small, and we dont want the user to be able to change fields
Side Board::getField(int x, int y) {
	if (utility::inside(x, 0, width - 1) && utility::inside(y, 0, width - 1)) {
		return fields[x][y];
	}
	else throw std::invalid_argument("that is not a column");
}


bool Board::columnNotFull(int column) {
	if (utility::inside(column, 0, width-1)) {
		if (fields[column][0] == Side::NEUTRAL) return true;
		else return false;
	}
	else throw std::invalid_argument("that is not a column");
}


void Board::doMove(int column, Side side) {
	if (columnNotFull(column)) {
		int y = cascade(column);
		fields[column][y] = side;
	}
}


bool Board::isFull() {
	return
		fields[0][0] != Side::NEUTRAL &&
		fields[1][0] != Side::NEUTRAL &&
		fields[2][0] != Side::NEUTRAL &&
		fields[3][0] != Side::NEUTRAL;
}


int Board::cascade(int column) {
	if		(fields[column][3] == Side::NEUTRAL) return 3;
	else if (fields[column][2] == Side::NEUTRAL) return 2;
	else if (fields[column][1] == Side::NEUTRAL) return 1;
	else if (fields[column][0] == Side::NEUTRAL) return 0;
	else throw std::invalid_argument("that column is already full");
}