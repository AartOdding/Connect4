#pragma once

#include "Board.h"
#include "Player.h"
#include "Input.h"
#include "Output.h"


class Game {

public:

	Game();
	~Game();

	void run();

private:

	Output output;

	Board board;
	HumanPlayer human;
	ComputerPlayer computer;

	void chooseSide();
	void doTurn(Player&);

};