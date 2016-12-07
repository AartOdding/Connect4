#include <iostream>
#include <string>
#include <limits>
#include "console.h"
#include "utility.h"



// returns first letter or digit entered by the user
char console::getChoice() {

	while (true) {
		std::string input;
		std::getline(std::cin, input);
		for (int i = 0; i < input.size(); ++i) {
			char test{ input[i] };
			if (utility::inside(test, 'a', 'z') || utility::inside(test, 'A', 'Z') || utility::inside(test, '0', '9')) {
				return test;
			}
		}
	}
	
}


void console::clear() {
	//system("cls");
	for (int i = 0; i < 50; ++i) std::cout << '\n';
}


void console::drawBoard(Board& board) {
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


void console::drawNumbers() {
	std::cout << "\n";
	std::cout << "\t  ^   ^   ^   ^  \n";
	std::cout << "\t  1   2   3   4  \n";
	std::cout << "\n";
}