#pragma once

#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>

#include <string>

#include "Board.h"



class Input {

public:

	Input();
	~Input();

	char getChoice();

private:

	int main();

	std::atomic_bool input_desired;
	std::atomic_bool stop_thread;

	std::thread input_thread;
	std::mutex input_mutex;
	std::condition_variable data_ready;

	std::string buffer;

};


extern Input input;