#include <iostream>
#include <string>
#include "input.h"


// returns 0 if no valid letter or number was choosen
char input::getDecision() {
	std::string input;
	std::getline(std::cin, input);
	for (int i = 0; i < input.size(); ++i) {
		char test{ input[i] };
		if (inside(test, 48, 57) || inside(test, 65, 90) || inside(test, 97, 122)) return test;
	}
	return 0;
}
