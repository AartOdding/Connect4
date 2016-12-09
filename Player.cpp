#include <iostream>
#include "Player.h"
#include "Input.h"



Player::Player() {
	side = Side::NEUTRAL;
}


Player::~Player() {

}


void Player::setSide(Side _side) {
	side = _side;
}


Side Player::getSide() {
	return side;
}


int HumanPlayer::getMove() {
	std::cout << "Choose the column you want to play: ";

	while (true) {
		char choice{ input.getChoice() };
		if (choice == '1') return 0;
		if (choice == '2') return 1;
		if (choice == '3') return 2;
		if (choice == '4') return 3;
		std::cout << "That's not a choice!" << std::endl;
	}

}


ComputerPlayer::ComputerPlayer() {
	std::random_device random;
	generator = std::mt19937(random());
	distribution = std::uniform_int_distribution<>(0, 3);
}


int ComputerPlayer::getMove() {
	return distribution(generator);
}