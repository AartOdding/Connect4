#pragma once

#include "Board.h"


// maybe make namespace with static functions
class Output {

public:

	Output();
	~Output();

	void clear();
	void drawBoard(Board&);
	void drawNumbers();

private:



};