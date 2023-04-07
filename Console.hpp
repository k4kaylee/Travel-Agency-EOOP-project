#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <unordered_map>



std::unordered_map<std::string, int> commandMap{
	{"--help", 1},	
	{"runAllTests", 2},
	{"addNewClient", 3},
	{"addNewTour", 4}
};

void clear() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}







class Engine {
	std::vector<std::string> command;
public:
	Engine();
	std::vector<std::string> getCommand();
	void run();
};

std::vector<std::string> Engine::getCommand() {
	std::string input;
	std::cout << "\n>>";
	std::getline(std::cin, input);
	for (char& letter : input) {
		letter = std::tolower(letter);
	}

	std::vector<std::string> vec;
	std::stringstream stream(input);

	std::string word;
	while (stream >> word) {
		vec.push_back(word);
	}
	return vec;
}

void Engine::run() {
	command = getCommand();
	int commandId = commandMap[command[0]];
	while (true) {
		clear();
		switch (commandId) {
		default:
			std::cout << "'" << command[0] << "' is not recognised as an existing command.\nUse '--help' to check the list of available commands.\n";
		}
		command = getCommand();
	}
}

Engine::Engine() {
	std::cout << "Welcome to Travel Agency|EOOP project!\nIf you are new to the console, run '--help'\n";
	run();
}