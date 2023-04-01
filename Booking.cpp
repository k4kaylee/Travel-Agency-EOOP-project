#define _CRT_SECURE_NO_WARNINGS
#include "Booking.h"
#include <cstring>



Booking::Booking(char* bDate, char* stDate, int numOfCl, List<Client>* lOfClients, Tour* tr) {
	setBookingDate(bDate);
	setStartDate(stDate);
	setListOfClients(lOfClients);
	setTour(tr);
}

Booking::~Booking() {
	delete[] bookingDate;
	delete[] startDate;
	listOfClients->free();
	delete tour;
}

// Getters
char* Booking::getBookingDate() { return bookingDate; }
char* Booking::getStartDate() { return startDate; }
int Booking::getNumberOfClients() { return numberOfClients; }
List<Client>* Booking::getListOfClients() { return listOfClients; }
Tour* Booking::getTour() { return tour; }

//Setters
void Booking::setBookingDate(char* bd) {
    delete[] bookingDate;
    bookingDate = new char[strlen(bd) + 1];
    strcpy(bookingDate, bd);
}

void Booking::setStartDate(char* sd) {
    delete[] startDate;
    startDate = new char[strlen(sd) + 1];
    strcpy(startDate, sd);
}

void Booking::setNumberOfClients(int n) { numberOfClients = n; }
void Booking::setListOfClients(List<Client>* lc) { listOfClients = lc; }
void Booking::setTour(Tour* t) { tour = t; }