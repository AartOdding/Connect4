#include <iostream>
#include <string>
#include "console.h"
#include "utility.h"



// returns 0 if no valid letter or number was choosen
char console::getDecision() {
	std::string input;
	std::getline(std::cin, input);
	for (int i = 0; i < input.size(); ++i) {
		char test{ input[i] };
		if (utility::inside(test, 48, 57) || utility::inside(test, 65, 90) || utility::inside(test, 97, 122)) return test;
	}
	return 0;
}