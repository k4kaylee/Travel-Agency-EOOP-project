#include "TravelAgency.h"
#include "List.h"
#include "Console.hpp"

int main() {
	List<Tour>* listOfTours = new List<Tour>;
	List<Client>* listOfClients = new List<Client>;
	TravelAgency* agency = new TravelAgency(listOfTours, listOfClients);
	Engine terminal(agency);
	return 0;
}