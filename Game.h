#pragma once

#include "Board.h"
#include "Player.h"


class Game {

public:

	Game();
	~Game();

	void run();

private:

	Board board;
	HumanPlayer human;
	ComputerPlayer computer;

	void chooseSide();
	void doTurn(Player&);

};