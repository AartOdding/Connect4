#include <iostream>

#include "Output.h"


void output::clear() {
	//system("cls");
	for (int i = 0; i < 50; ++i) std::cout << '\n';
}


void output::drawBoard(Board& board) {
	std::cout << "\n\n";
	std::cout << "\t+---+---+---+---+\n";
	for (int y = 0; y < Board::height; ++y) {
		std::cout << "\t|";
		for (int x = 0; x < Board::width; ++x) {
			if (board.getField(x, y) == Side::O)		std::cout << " O |";
			else if (board.getField(x, y) == Side::X)	std::cout << " X |";
			else										std::cout << "   |";
		}
		std::cout << "\n\t+---+---+---+---+\n";
	}
}


void output::drawNumbers() {
	std::cout << "\n";
	std::cout << "\t  ^   ^   ^   ^  \n";
	std::cout << "\t  1   2   3   4  \n";
	std::cout << "\n";
}