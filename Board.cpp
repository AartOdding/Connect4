#include <iostream>
#include "Board.h"
#include "input.h"


Board::Board() {
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			fields[x][y] = Side::NEUTRAL;
		}
	}
}


Board::~Board() {

}


bool Board::isValid(int x) {
	if (input::inside(x, 0, 3)) {
		if (fields[x][0] == Side::NEUTRAL) return true;
	}
	return false;
}


bool Board::doMove(int x, Side side) {
	if (isValid(x)) {
		int y = cascade(x);
		if (y != -1) {
			fields[x][y] = side;
		}
	}
	return false;
}


bool Board::isFull() {
	return
		fields[0][0] != Side::NEUTRAL &&
		fields[1][0] != Side::NEUTRAL &&
		fields[2][0] != Side::NEUTRAL &&
		fields[3][0] != Side::NEUTRAL;
}


// returns -1 of column is already full
int Board::cascade(int x) {
	if		(fields[x][3] == Side::NEUTRAL) return 3;
	else if (fields[x][2] == Side::NEUTRAL) return 2;
	else if (fields[x][1] == Side::NEUTRAL) return 1;
	else if (fields[x][0] == Side::NEUTRAL) return 0;
	else return -1;
}


void Board::draw() {
	std::cout << "\n\n";
	std::cout << "\t+---+---+---+---+\n";
	for (int y = 0; y < height; ++y) {
		std::cout << "\t|";
		for (int x = 0; x < width; ++x) {
			if (fields[x][y] == Side::O)		std::cout << " O |";
			else if(fields[x][y] == Side::X)	std::cout << " X |";
			else										std::cout << "   |";
		}
		std::cout << "\n\t+---+---+---+---+\n";
	}
}


void Board::drawNumbers() {
	std::cout << "\n";
	std::cout << "\t  ^   ^   ^   ^  \n";
	std::cout << "\t  1   2   3   4  \n";
	std::cout << "\n";
}
