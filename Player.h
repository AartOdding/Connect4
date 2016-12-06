#pragma once

#include <random>
#include "Side.h"



class Player {

public:

	Player();
	~Player();

	void setSide(Side);
	Side getSide();
	virtual int getMove() = 0; // should always be overridden

private:

	Side side;

};



class HumanPlayer : public Player {

public:

	int getMove();

};



class ComputerPlayer : public Player {

public:

	ComputerPlayer();
	int getMove();

private:

	std::mt19937 generator;
	std::uniform_int_distribution<> distribution;

};