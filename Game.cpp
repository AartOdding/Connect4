#include <iostream>
#include <thread>
#include <chrono>
#include "Game.h"
#include "console.h"
#include "utility.h"



Game::Game() {
}


Game::~Game() {
}


void Game::run() {
	console::clear();
	chooseSide();

	console::clear();
	console::drawBoard(board);
	console::drawNumbers();

	while (!board.isFull()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		doTurn(computer);
		console::clear();
		console::drawBoard(board); 
		console::drawNumbers();
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
		doTurn(human);
		console::clear();
		console::drawBoard(board);
		console::drawNumbers();
	}

	std::cout << "done" << std::endl;

	std::cin.get();
}


void Game::doTurn(Player& player) {

	while (true) {
		
		int move = player.getMove();

		while (!utility::inside(move, 0, 3)) {
			move = player.getMove();
		}

		if (board.columnNotFull(move)) {
			board.doMove(move, player.getSide());
			break;
		}
		else {
			std::cout << "That column is already full" << std::endl;
		}
	}
	
}


void Game::chooseSide() {
	std::cout << "Choose your side, X or O: "; //<< std::endl;
	while (true) {
		char choice = console::getChoice();
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
			std::cout << "Thats not X or O ..." << std::endl;
		}
	}
}