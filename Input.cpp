#include <iostream>

#include "Input.h"
#include "utility.h"



Input input;


Input::Input() {
	stop_thread = false;
	input_desired = false;
	input_thread = std::thread(&Input::main, this);
}


Input::~Input() {

	// this runs after main exits
	stop_thread = true;
	
	if (input_thread.joinable()) {
		input_thread.join();
	}
}


int Input::main() {

	while (!stop_thread) {

		std::string input;
		std::getline(std::cin, input);

		if (input_desired) {
			std::unique_lock<std::mutex> lock(input_mutex);
			buffer = input;
			lock.unlock();
			input_desired = false;
			data_ready.notify_all();
		}

	}

	return 0;
}



// returns first letter or digit entered by the user
char Input::getChoice() {
	
	while (true) {		// we only want to return in the for loop
		std::string input = getLine();
		for (int i = 0; i < input.size(); ++i) {
			char test{ input[i] };
			if (utility::inside(test, 'a', 'z') || utility::inside(test, 'A', 'Z') || utility::inside(test, '0', '9')) {
				return test;
			}
		}
	}
}


// doesn't give any gaurantees to what is in the line, it could be only "\n"
std::string Input::getLine() {

	std::unique_lock<std::mutex> lock(input_mutex);
	input_desired = true;

	// need some way to check if wakeup wasn't spurous
	// because main resets input_desired to false when input is ready, we can only escape loop when !input_desired
	while (input_desired) {
		data_ready.wait(lock);
	}

	return buffer;
}

