#pragma once
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
#include <algorithm>
#include <numeric>
#include <limits>
#include "TravelAgency.h"
#include "Client.h"
#include "List.h"
#include "Tour.h"


void gotoxy(int x, int y) {
	std::cout << "\033[0r" << "\033[" << y << ";" << x << "H";
}

const int LINES_PER_PAGE = 15;

TravelAgency* agency;

enum Command {
	EXIT = 0,
	HELP = 1,
	RUNTESTS = 2,
	ADDCLIENT = 3,
	ADDTOUR = 4,
	REMOVETOUR = 5,
	REMOVECLIENT = 6,
	SHOWCLIENTS = 7,
	SHOWTOURS = 8,
	BOOK = 9,
	UNBOOK = 10,
	SEARCH = 11
};

std::unordered_map<std::string, int> commandMap{
	{"exit", EXIT},
	{"--help", HELP},
	{"runalltests", RUNTESTS},
	{"removeclient", REMOVECLIENT},
	{"removetour", REMOVETOUR},
	{"addnewclient", ADDCLIENT},
	{"addnewtour", ADDTOUR},
	{"showclientlist", SHOWCLIENTS},
	{"showtourlist", SHOWTOURS},
	{"book", BOOK},
	{"unbook", UNBOOK},
	{"search", SEARCH}
};

void clear() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

std::string removeQuotes(std::string str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] == '"') {
			str.erase(i--, 1);
		}
	}
	return str;
}

std::string accumulateStrings(std::vector<std::string> command, int index = 2){
	std::string str;
	for (size_t i = index; i < command.size(); i++) {
		if (i == index) {
			str += command[i];
			continue;
		}
		str += " " + command[i];
		if (command[i].back() == '"') {
			break;
		}
	}
	return str;
}

void displayPage(const std::string& search, const std::vector<std::string>& items, int currentPage) {
	clear();
	int totalPages = (items.size() + LINES_PER_PAGE - 1) / LINES_PER_PAGE;
	std::cout << "\nSearch results (" << currentPage + 1 << "/" << totalPages << "):\n\n";

	for (int i = currentPage * LINES_PER_PAGE; i < (currentPage + 1) * LINES_PER_PAGE && i < items.size(); ++i) {
		std::cout << items[i] << std::endl;
	}

	std::cout << "\nPress '->' for next page, '<-' for previous page, type 'exit' to quit, or any other key to continue searching.\n";
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
	std::cout << "'removeclient <name>' - removes client with a given name from the list.\n";
	std::cout << "'removetour <name>' - removes tour with a given name from the list.\n\t\tIf the name consists of several words, it must be included in \"\".\n";
	std::cout << "'addnewclient <clientName> <clientLastName> <clientPhoneNumber> <clientEmail>' - add new Client to Travel Agency client base.\n";
	std::cout << "'addnewtour <tourName> <price> <startDate> <finishDate>' - add new Tour to Travel Agency tour list.\n";
	std::cout << "'book <client_name> <tour_name>' - books tour for a given client. For tours with several words in the name put it in \"\".\n";
	std::cout << "'unbook <client_name> <tour_name>' - unbooks tour for a given client.For tours with\nseveral words in the name put it in \"\".\n";
	std::cout << "'search <option>' - runs search engine to find client or tour.\n\t\t<option> may be equal to 'tour' or 'client'.\n\t\tNOTE: to exit search, press ESC.\n";
}

void runTests() {
	Client* Nikolai = new Client("Nikolai", "Borutko", "+124134674122", "10256381@wxample.com");
	Client* Pavel = new Client("Pavel", "Fuggy", "+612567487291", "012412495@example.com");
	Client* Eugene = new Client("Eugene", "Smith", "+039528736481", "18258924@wxample.com");
	Client* Jakub = new Client("Jakub", "Kowalski", "+347902478299", "1958195145@example.com");
	Client* Maria = new Client("Maria", "Garcia", "+44123456789", "1524742325@example.com");
	
	List<Client>* listOfClients = new List<Client>;
	listOfClients->add(Nikolai);
	listOfClients->add(Pavel);
	listOfClients->add(Eugene);
	listOfClients->add(Jakub);


	std::cout << "Creating client list.";
	std::cout << "\nCreating tour list.\n";
	Tour* tour1 = new Tour("Hawaii Paradise",
		2500.0,
		"21.05.2023",
		"23.05.2023",
		"Experience the best of Hawaii with this 7-day tour that takes you\
\nfrom Honolulu to Maui. Enjoy stunning beaches, tropical rainforests,\
\nsand breathtaking landscapes.\n");

	Tour* tour2 = new Tour("European Gorgeous Adventure",
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

	Tour* tour4 = new Tour("Paris City Tour",
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

	std::cout << "Creating 'Agency' object.\n";
	agency = new TravelAgency(listOfTours, listOfClients);

	std::cout << "Printing 'Agency' Client and Tour lists.\n\n";

	agency->getTourList()->print();
	agency->getClientList()->print();


	std::cout << "\n\nAdding client to 'Agency' client list.\n";
	agency->getClientList()->add(Maria);
	std::cout << "Adding bookings for Jakub and Maria\n\n";
	Maria->book(tour1);
	Jakub->book(tour2);

	agency->getClientList()->print();

	std::cout << "\n\nRemoving booking from Maria\n\n";
	List<Booking>* MariaList = listOfClients->getItemByName("Maria")->getListOfBookings();
	MariaList->remove("Hawaii Paradise");
	MariaList->remove("European Gorgeous Adventure");

	std::cout << "\nTrying to book the tour which is already booked:\n";
	Jakub->book(tour2);

	std::cout << "\nRemoving tour from the list.\n";
	listOfTours->remove(tour2->getName());

	listOfTours->print();
	listOfClients->print();
	
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
			std::cerr << "ERROR: client '" << command[1] << "' already exists.";
			return;
		}
		agency->getClientList()->add(client);
		client->print();
		return;
	}
	std::cout << "ERROR: not enough arguments.\n\nFrom '--help':\naddnewclient <clientName> <clientLastName> <clientPhoneNumber> <clientEmail>' - add new Client to Travel Agency client base.\n\n";
	return;
}

void addNewTour(std::vector<std::string> command) {
	if (command.size() >= 5) {
		int closedQuoteIndex;
		std::string tourName;
		if (command[1].front() == '"') {
			tourName = removeQuotes(accumulateStrings(command, 1));
			closedQuoteIndex = 2;
			while (command[closedQuoteIndex].back() != '"') {
				closedQuoteIndex++;
			}
		}
		else {
			tourName = command[2];
			closedQuoteIndex = 1;
		}

		const std::regex date("^(?:(?:31(\\/|-|\\.)(?:0?[13578]|1[02]))\\1|(?:(?:29|30)(\\/|-|\\.)(?:0?[13-9]|1[0-2])\\2))(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$|^(?:29(\\/|-|\\.)0?2\\3(?:(?:(?:1[6-9]|[2-9]\\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\\d|2[0-8])(\\/|-|\\.)(?:(?:0?[1-9])|(?:1[0-2]))\\4(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$");

		if (!std::regex_match(command[closedQuoteIndex + 2], date)) {
			std::cerr << "ERROR: '" << command[closedQuoteIndex + 2] << "' - incorrect data input.\nProper format: 'DD.MM.YYYY'.";
			return;
		}
		else if (compareDate(command[closedQuoteIndex + 2], getCurrentDate())) {
			std::cerr << "ERROR: '" << command[closedQuoteIndex + 2] << "' is before current date (" << getCurrentDate() << ").\n";
			return;
		}
		else if (!std::regex_match(command[closedQuoteIndex + 3], date)) {
			std::cerr << "ERROR: '" << command[closedQuoteIndex + 3] << "' - incorrect data input.\nProper format: 'DD.MM.YYYY'.";
			return;
		}
		else if (!compareDate(command[closedQuoteIndex + 2], command[closedQuoteIndex + 3])) {
			std::cerr << "ERROR: '" << command[closedQuoteIndex + 3] << "' is before '" << command[closedQuoteIndex + 2] << "'.";
			return;
		}

		Tour* tour = new Tour(tourName.c_str(), std::stof(command[closedQuoteIndex + 1]), command[closedQuoteIndex + 2].c_str(), command[closedQuoteIndex + 3].c_str(), getDescription().c_str());
		if (agency->getTourList()->find(tour)) {
			std::cerr << "ERROR: tour '" << tourName << "' already exists.\n";
			return;
		}
		agency->getTourList()->add(tour);
		tour->print();
		return;
	}
	std::cout << "ERROR: not enough arguments.\n\nFrom '--help':\naddnewtour <tourName> <price> <startDate> <finishDate>' - add new Tour to Travel Agency tour list.\n\n";
	return;
}
             
void removeClient(std::vector<std::string> command) {
	if (command.size() >= 2) {
		agency->getClientList()->remove(command[1]);
		return;
	}
	else {
		std::cerr << "ERROR: not enough arguments. From '--help': 'removeclient <name>' - removes client with a given name from the list.\n";
		return;
	}
}

void removeTour(std::vector<std::string> command) {
	if (command.size() >= 2) {
		if (command[1].front() == '\"') {
			std::string tourName;
			for (size_t i = 2; i < command.size(); i++) {
				if (command[i][command[i].length() - 1] == '"') {
					tourName = std::accumulate(command.begin() + 1,
						command.begin() + i + 1,
						std::string(""),
						[](std::string acc, std::string newWord) {
							if (acc.empty())
								return newWord;
							else
								return acc + " " + newWord;
						}
					);
					tourName = removeQuotes(tourName);
					return;
				}
			}
		}
				
		return;
	}
	else {
		std::cerr << "ERROR: not enough arguments. From '--help': 'removetour <name>' - removes client with a given name from the list.\n";
		return;
	}
}

void showClientList() {
	std::cout << "Current version of Client List:\n\n";
	agency->getClientList()->print();
}

void showTourList() {
	std::cout << "Current version of tour list: \n";
	agency->getTourList()->print();
}

void book(std::vector<std::string> command) {
	if (command.size() >= 3) {
		Client* client = agency->getClientList()->getItemByName(command[1]);
		Tour* tour;
		std::string tourName;
		if (command[2].front() == '"') {
			tourName = removeQuotes(accumulateStrings(command));
			tour = agency->getTourList()->getItemByName(tourName);
		}
		else {
			tourName = command[2];
			tour = agency->getTourList()->getItemByName(command[2]);
		}
		if (client == nullptr) {
			std::cerr << "ERROR: '" << command[1] << "' was not found.\n";
			return;
		}
		else if (tour == nullptr) {
			std::cerr << "ERROR: '" << tourName << "' was not found.\n";
			return;
		}

		client->book(tour);
	}
	else {
		std::cout << "ERROR: not enough arguments.\nFrom '--help': 'book <client_name> <tour_name>' - books tour for a given client. For tours with\nseveral words in the name put it in \"\".\n";
	}
}
 
void unbook(std::vector<std::string> command) {
	if (command.size() >= 3) {
		Client* client = agency->getClientList()->getItemByName(command[1]);
		std::string tourName;
		if (command[2].front() == '"') {
			tourName = removeQuotes(accumulateStrings(command));
		}
		else {
			tourName = command[2];
		}
		if (client == nullptr) {
			std::cerr << "ERROR: '" << command[1] << "' was not found.\n";
			return;
		}

		Tour* toRemove = new Tour(tourName.c_str());
		client->unbook(toRemove);
	}
	else {
		std::cout << "ERROR: not enough arguments.\nFrom '--help': 'unbook <client_name> <tour_name>' - unbooks tour for a given client. For tours with\nseveral words in the name put it in \"\".\n";
	}
}

void search(std::vector<std::string> command) {
	if (command.size() >= 2) {
		for (char& letter : command[1]) {
			letter = std::tolower(letter);
		}

		char letter;
		std::string search;
		gotoxy(0, 3);

		while (true) {
			if (search.empty()) {
				gotoxy(0, 3);
				if (command[1] == "client")
					std::cout << agency->getClientList()->toString();
				else if (command[1] == "tour")
					std::cout << agency->getTourList()->toString();
				else {
					gotoxy(0, 0);
					std::cerr << "'" << command[1] << "' - unknown parameter. Consider using 'client' or 'tour'.\n";
					return;
				}
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
				if (command[1] == "client")
					agency->getClientList()->search(search);
				else if (command[1] == "tour")
					agency->getTourList()->search(search);
				gotoxy(0, 0);
				std::cout << search;
			}

			if (isalpha(letter) || isdigit(letter) || isspace(letter) || letter == '@' || letter == '.') {
				search += letter;
				int length = search.length();
				gotoxy(0, 3);
				clear();
				gotoxy(0, 3);

				if (command[1] == "client")
					agency->getClientList()->search(search);
				else if (command[1] == "tour")
					agency->getTourList()->search(search);

				gotoxy(0, 0);
				std::cout << search;
				continue;
			}
		}
	}
	else {
		std::cerr << "ERROR: not enough arguments. From '--help':\n'search <option>' - runs search engine to find client or tour. <option> may be equal to 'tour' or 'client'.\n";
		return;
	}
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
			case REMOVECLIENT:
				removeClient(command);
				break;
			case REMOVETOUR:
				removeTour(command);
				break;
			case SHOWCLIENTS:
				showClientList();
				break;
			case SHOWTOURS:
				showTourList();
				break;
			case BOOK:
				book(command);
				break;
			case UNBOOK:
				unbook(command);
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
