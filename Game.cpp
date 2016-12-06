#include <iostream>
#include <thread>
#include <chrono>
#include "Game.h"
#include "input.h"



Game::Game() {
}


Game::~Game() {
}


void Game::run() {
	system("cls");
	chooseSide();

	system("cls");
	board.draw();
	board.drawNumbers();

	while (!board.isFull()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		doTurn(computer);
		system("cls");
		board.draw();
		board.drawNumbers();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		doTurn(human);
		system("cls");
		board.draw();
		board.drawNumbers();
	}

	std::cout << "done" << std::endl;

	std::cin.get();
}


void Game::doTurn(Player& player) {

	while (true) {
		int move = player.getMove();
		if (board.isValid(move)) {
			board.doMove(move, player.getSide());
			break;
		}
	}
}


void Game::chooseSide() {
	std::cout << "Choose your side, X or O: "; //<< std::endl;
	while (true) {
		char choice = input::getDecision();
		if (choice != 0) {
			if (choice == 'X' || choice == 'x') {
				human.setSide(Side::X);
				computer.setSide(Side::O);
				return;
			}
			else if (choice == 'O' || choice == 'o') {
				human.setSide(Side::O);
				computer.setSide(Side::X);
				return;
			}
			else {
				std::cout << "Thats not X or O" << std::endl;
			}
		}
	}
}