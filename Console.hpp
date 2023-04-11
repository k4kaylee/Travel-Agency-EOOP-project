﻿#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <regex>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <conio.h>
#include "TravelAgency.h"
#include "Client.h"
#include "Tour.h"
#define gotoxy(x,y) std::cout << "\033[" << y << ";" << x << "H"


TravelAgency* agency;

enum Command {
	EXIT = 0,
	HELP = 1,
	RUNTESTS = 2,
	ADDCLIENT = 3,
	ADDTOUR = 4,
	SHOWCLIENTS = 5,
	SHOWTOURS = 6,
	SEARCH = 7
};

std::unordered_map<std::string, int> commandMap{
	{"exit", EXIT},
	{"--help", HELP},
	{"runalltests", RUNTESTS},
	{"addnewclient", ADDCLIENT},
	{"addnewtour", ADDTOUR},
	{"showclientlist", SHOWCLIENTS},
	{"showtourlist", SHOWTOURS},
	{"search", SEARCH}
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

	std::vector<std::string> vec;
	std::stringstream stream(input);

	std::string word;
	while (stream >> word) {
		vec.push_back(word);
	}

	if (!vec.empty()) {
		for (char& letter : vec[0]) {
			letter = std::tolower(letter);
		}
	}

	return vec;
}

std::string getDescription() {
	clear();
	std::cout << "Description: ";
	std::string description;
	std::getline(std::cin, description);
	clear();
	return description;
}


void help() {
	std::cout << "Commands:\n";
	std::cout << "'runalltests' - simply observe all possible tests done automatically. No other interactions needed.\n";
	std::cout << "'showclientlist' - prints list of clients at its current state.\n";
	std::cout << "'showtourlist' - prints list of tours at its current state.\n";
	std::cout << "'addnewclient <clientName> <clientLastName> <clientPhoneNumber> <clientEmail>' - add new Client to Travel Agency client base.\n";
	std::cout << "'addnewtour <tourName> <price> <startDate> <finishDate>' - add new Tour to Travel Agency tour list.\n";
	std::cout << "'search <option>' - runs search engine to find client or tour.\n\t\t<option> may be equal to 'tour' or 'client'.\n\t\tNOTE: to exit search, press ESC.\n";
}

void runTests() {
	Client* client1 = new Client("Nikolai", "Borutko", "+124134674122", "10256381@wxample.com");
	Client* client2 = new Client("Pavel", "Fuggy", "+612567487291", "012412495@example.com");
	Client* client3 = new Client("Eugene", "Smith", "+039528736481", "18258924@wxample.com");
	Client* client4 = new Client("Jakub", "Kowalski", "+347902478299", "1958195145@example.com");
	Client* client5 = new Client("Maria", "Garcia", "+44123456789", "1524742325@example.com");

	List<Client>* listOfClients = new List<Client>;
	listOfClients->add(client1);
	listOfClients->add(client2);
	listOfClients->add(client3);
	listOfClients->add(client4);


	Tour* tour1 = new Tour("Hawaii Paradise",
		2500.0,
		"21.05.2023",
		"23.05.2023",
		"Experience the best of Hawaii with this 7-day tour that takes you\
\nfrom Honolulu to Maui. Enjoy stunning beaches, tropical rainforests,\
\nsand breathtaking landscapes.\n");

	Tour* tour2 = new Tour("European Adventure",
		4500.0,
		"15.02.2021",
		"26.02.2021",
		"Embark on a 14-day adventure through Europe, starting in Paris and\
\nending in Barcelona. Discover the beauty of the continent with this\
\nexciting tour that covers 6 different countries.\n");

	Tour* tour3 = new Tour("African Safari",
		3500.0,
		"21.02.2024",
		"23.03.2024",
		"Experience the ultimate adventure with this 10-day safari tour\
\nthat takes you through the heart of Kenya and Tanzania. Get up close\
\nand personal with some of Africa's most majestic wildlife.\n");

	Tour* tour4 = new Tour("Paris Tour",
		1200.0,
		"01.07.2023",
		"05.07.2023",
		"Experience the culture and beauty of Paris in this four-day tour.\n");

	Tour* tour5 = new Tour("Australia Tour",
		3500.0,
		"30.08.2023",
		"10..09.2023",
		"Explore the stunning natural wonders and iconic landmarks\
\nof Australia in this ten-day tour.\n");

	List<Tour>* listOfTours = new List<Tour>;
	listOfTours->add(tour1);
	listOfTours->add(tour2);
	listOfTours->add(tour3);
	listOfTours->add(tour4);

	TravelAgency* agency = new TravelAgency(listOfTours, listOfClients);

	agency->getTourList()->print();
	client5->book(tour1);
	client4->book(tour2);
	agency->getClientList()->add(client5);
	agency->getClientList()->print();

}

void addNewClient(std::vector<std::string> command) {
	if (command.size() >= 5) {
		const std::regex email("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		const std::regex phone("^\\+?[0-9]{1,3}-?[0-9]{3,}-?[0-9]{4,}$");
		if (!std::regex_match(command[3], phone)) {
			std::cerr << "ERROR: '" << command[3] << "' - incorrect phone input\n";
			return;
		}
		if (!std::regex_match(command[4], email)) {
			std::cerr << "ERROR: '" << command[4] << "' - incorrect email input\n";
			return;
		}
		Client* client = new Client(command[1].c_str(), command[2].c_str(), command[3].c_str(), command[4].c_str());
		if (agency->getClientList()->find(client)) {
			std::cerr << "ERROR: cliemt '" << command[1] << "' already exists.";
			return;
		}
		agency->getClientList()->add(client);
		client->print();
		return;
	}
	std::cout << "ERROR: not enough arguments.\n\nFrom '--help':\naddnewclient <clientName> <clientLastName> <clientPhoneNumber> <clientEmail>' - add new Client to Travel Agency client base.\n\n";
	return;
}

std::string getCurrentDate() {
	auto now = std::chrono::system_clock::now();
	auto time = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;

	struct tm* timeinfo;
	timeinfo = localtime(&time);

	ss << std::setfill('0') << std::setw(2) << timeinfo->tm_mday << "."
		<< std::setfill('0') << std::setw(2) << timeinfo->tm_mon + 1 << "."
		<< std::setw(4) << timeinfo->tm_year + 1900;

	return ss.str();
}

bool compareDate(std::string date1, std::string date2) {
	tm tm1 = {};
	std::istringstream ss1(date1);
	ss1 >> std::get_time(&tm1, "%d.%m.%Y");
	time_t time1 = mktime(&tm1);

	tm tm2 = {};
	std::istringstream ss2(date2);
	ss2 >> std::get_time(&tm2, "%d.%m.%Y");
	time_t time2 = mktime(&tm2);

	return difftime(time1, time2) < 0;
}

void addNewTour(std::vector<std::string> command) {
	if (command.size() >= 5) {
		const std::regex date("^(?:(?:31(\\/|-|\\.)(?:0?[13578]|1[02]))\\1|(?:(?:29|30)(\\/|-|\\.)(?:0?[13-9]|1[0-2])\\2))(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$|^(?:29(\\/|-|\\.)0?2\\3(?:(?:(?:1[6-9]|[2-9]\\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\\d|2[0-8])(\\/|-|\\.)(?:(?:0?[1-9])|(?:1[0-2]))\\4(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$");



		if (!std::regex_match(command[3], date)) {
			std::cerr << "ERROR: '" << command[3] << "' - incorrect data input.\nProper format: 'DD.MM.YYYY'.";
			return;
		}
		else if (compareDate(command[3], getCurrentDate())) {
			std::cerr << "ERROR: '" << command[3] << "' is before current date (" << getCurrentDate() << ").";
			return;
		}
		else if (!std::regex_match(command[4], date)) {
			std::cerr << "ERROR: '" << command[4] << "' - incorrect data input.\nProper format: 'DD.MM.YYYY'.";
			return;
		}
		else if (!compareDate(command[3], command[4])) {
			std::cerr << "ERROR: '" << command[4] << "' is before '" << command[3] << "'.";
			return;
		}

		Tour* tour = new Tour(command[1].c_str(), std::stof(command[2]), command[3].c_str(), command[4].c_str(), getDescription().c_str());
		if (agency->getTourList()->find(tour)) {
			std::cerr << "ERROR: tour '" << command[1] << "' already exists.";
			return;
		}
		agency->getTourList()->add(tour);
		tour->print();
		return;
	}
	std::cout << "ERROR: not enough arguments.\n\nFrom '--help':\naddnewtour <tourName> <price> <startDate> <finishDate>' - add new Tour to Travel Agency tour list.\n\n";
	return;
}

void showClientList() {
	std::cout << "Current version of Client List:\n\n";
	agency->getClientList()->print();
}

void showTourList() {
	std::cout << "Current version of tour list: \n";
	agency->getTourList()->print();
}

void search(std::vector<std::string> command) {
	if (command.size() >= 2) {
		char letter;
		std::string ListDemo = "ListDemo\nBanana\nApple\nMakintosh\nSumakin";
		std::string search;
		std::string storage;
		gotoxy(0, 3);

		storage = ListDemo;
		std::cout << storage;
		while (true) {
			if (search.empty()) {
				gotoxy(0, 3);
				std::cout << ListDemo;
			}
			gotoxy(search.length() + 1, 0);

			letter = _getch();
			
			if (letter == 27) {
				clear();
				std::cout << "What do you want me to do?\n";
				return;
			}

			if (letter == 8 && !search.empty()) {
				clear();
				search.pop_back();
				if (search.empty()) {
					continue;
				}
				gotoxy(0, 3);
				std::string highlighted;
				for (size_t pos = 0; pos < ListDemo.length(); pos++) {
					if (ListDemo.substr(pos, search.length()) == search) {
						// Если подстрока совпадает с search, то выделяем ее красным цветом
						highlighted += "\033[31m" + ListDemo.substr(pos, search.length()) + "\033[0m";
						pos += search.length() - 1;
					}
					else {
						highlighted += ListDemo[pos];
					}
				}
				std::cout << highlighted;
				gotoxy(0, 0);
				std::cout << search;
			}

			if (isalpha(letter) || isdigit(letter) || isspace(letter)) {
				search += letter;
				int length = search.length();
				gotoxy(0, 3);
				std::string highlighted;
				for (size_t pos = 0; pos < ListDemo.length(); pos++) {
					if (ListDemo.substr(pos, search.length()) == search) {
						// Если подстрока совпадает с search, то выделяем ее красным цветом
						highlighted += "\033[31m" + ListDemo.substr(pos, search.length()) + "\033[0m";
						pos += search.length() - 1;
					}
					else {
						highlighted += ListDemo[pos];
					}
				}
				clear();
				gotoxy(0, 3);
				std::cout << highlighted;

				storage = highlighted;

				gotoxy(0, 0);
				std::cout << search;
				continue;
			}
		}




	}
	std::cerr << "ERROR: not enough arguments. From '--help':\n'search <option>' - runs search engine to find client or tour. <option> may be equal to 'tour' or 'client'.\n";
	return;
}

void Engine::run() {
	command = getCommand();
	while (true) {
		clear();
		if (commandMap.count(command[0])) {
			int commandId = commandMap[command[0]];
			switch (commandId) {
			case EXIT:
				return;
			case HELP:
				help();
				break;
			case RUNTESTS:
				runTests();
				break;
			case ADDCLIENT:
				addNewClient(command);
				break;
			case ADDTOUR:
				addNewTour(command);
				break;
			case SHOWCLIENTS:
				showClientList();
				break;
			case SHOWTOURS:
				showTourList();
				break;
			case SEARCH:
				search(command);
				break;
			default:
				std::cout << "'" << command[0] << "' is not recognised as an existing command.\nUse '--help' to check the list of available commands.\n";
			}
		}
		else {
			std::cout << "'" << command[0] << "' is not recognised as an existing command.\nUse '--help' to check the list of available commands.\n";
		}
		command = getCommand();
	}
}

Engine::Engine() {
	std::cout << "Welcome to Travel Agency|EOOP project!\nIf you are new to the console, run '--help'\n";
	run();
}
