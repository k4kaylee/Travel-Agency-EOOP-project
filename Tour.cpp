#define _CRT_SECURE_NO_WARNINGS
#include "Tour.h"
#include "TravelAgency.h"
#include "List.h"
#include <cstring>
#include <sstream>
#include <iostream>

extern TravelAgency* agency;

Tour::Tour(const char* nm, float prc, const char* strtDt, const char* fnshDt, const char* dscrptn) {
	setName(nm);
	setPrice(prc);
	setDescription(dscrptn);
	setStartDate(strtDt);
	setFinishDate(fnshDt);
}

Tour::~Tour() {
	//Removing all the bookings connected to this tour
	List<Client>* listOfClients = agency->getClientList();
	List<Booking>* listOfBookings;
	for (auto currentClient = listOfClients->getHead(); currentClient != nullptr; currentClient = currentClient->next) {
		listOfBookings = currentClient->ptr->getListOfBookings();
		Booking* toFind = new Booking(this);
		if (listOfBookings->find(toFind)) {
			listOfBookings->remove(toFind);
		}
		delete toFind;
	}
	delete[] name;
	delete[] finishDate;
	delete[] startDate;
	delete[] description;
}

void Tour::setName(const char* nm) {
	delete[] name;
	name = new char[strlen(nm) + 1];
	strcpy(name, nm);
}

void Tour::setFinishDate(const char* fnshDt) {
	delete[] finishDate;
	finishDate = new char[strlen(fnshDt) + 1];
	strcpy(finishDate, fnshDt);
}

void Tour::setPrice(float prc) {
	price = prc;
}

void Tour::setStartDate(const char* strtDt) {
	delete[] startDate;
	startDate = new char[strlen(strtDt) + 1];
	strcpy(startDate, strtDt);
}

void Tour::setDescription(const char* dscrptn) {
	delete[] description;
	description = new char[strlen(dscrptn) + 1];
	strcpy(description, dscrptn);
}

void Tour::print() {
	std::cout << "Name: " << name <<
		"\nPrice: " << price <<
		"\nStart date: " << startDate <<
		"\nFinish date: " << finishDate <<
		"\nDescription: " << description << "\n\n";
}

std::string Tour::toString() {
	std::stringstream ss;
	ss << "Name: " << getName() << "\n";  
	ss << "Price: " << getPrice() << "\n";
	ss << "Start date: " << getStartDate() << "\n";
	ss << "Finish date: " << getFinishDate() << "\n";
	ss << "Description: " << getDescription() << "\n";
	return ss.str();
}

bool Tour::isEqual(Tour* item) {
	return strcmp(this->getName(), item->getName()) == 0;
}