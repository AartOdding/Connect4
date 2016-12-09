#include <iostream>

#include "Input.h"
#include "utility.h"



Input input;		// right now thread might never close?

Input::Input() {
	stop_thread = false;
	input_desired = false;
	buffer = "nonsense";
	input_thread = std::thread(&Input::main, this);
}


Input::~Input() {

	// cout some message to press any key to quit
	stop_thread = true;
	
	if (input_thread.joinable()) {		// thread main needs to finish 
		input_thread.join();
	}
	std::cout << "closes" << std::endl;
	std::cin.get();

}


int Input::main() {

	while (!stop_thread) {

		std::string input;
		std::getline(std::cin, input);
		// do stuff :D

		if (input_desired) {
			input_mutex.lock();
			buffer = input;
			input_mutex.unlock();
			input_desired = false;
			data_ready.notify_one();
		}

	}

	return 0;
}



// returns first letter or digit entered by the user
char Input::getChoice() {

	while (true) {
		std::unique_lock<std::mutex> lock(input_mutex);

		input_desired = true;	// buffer will get data once.

		while (input_desired) {		//  need some way to check if wakeup wasn't spurous
			data_ready.wait(lock);
		}

		std::string input;
		input = buffer;

		lock.unlock();

		for (int i = 0; i < input.size(); ++i) {
			char test{ input[i] };
			if (utility::inside(test, 'a', 'z') || utility::inside(test, 'A', 'Z') || utility::inside(test, '0', '9')) {
				return test;
			}
		}
	}
	
}

