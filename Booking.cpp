#define _CRT_SECURE_NO_WARNINGS
#include "Booking.h"
#include <cstring>
#include <iostream>



Booking::Booking(const char* bDate, int numOfCl, Tour* tr) {
	setBookingDate(bDate);
	setNumberOfClients(numOfCl);
	setTour(tr);
}

Booking::~Booking() {
	delete[] bookingDate;
	delete tour;
}

// Getters
char* Booking::getBookingDate() { return bookingDate; }
int Booking::getNumberOfClients() { return numberOfClients; }
Tour* Booking::getTour() { return tour; }

//Setters
void Booking::setBookingDate(const char* bd) {
    delete[] bookingDate;
    bookingDate = new char[strlen(bd) + 1];
    strcpy(bookingDate, bd);
}

void Booking::setNumberOfClients(int n) { numberOfClients = n; }
void Booking::setTour(Tour* t) {
	if (tour != nullptr) {
		delete tour;
	}
	tour = t; 
}

void Booking::print() {
	if (status == bookingStatus::ongoing) {
		std::cout << "\tBooking status: ongoing";
	}
	else {
		std::cout << "\tBooking status: finished";
	}
	std::cout << "\n\tBooking date: " << bookingDate <<
			 	 "\n\tClients registered: " << numberOfClients <<
		         "\n\tLinked tour: \n";
	std::cout << "\t\tName: " << tour->getName() <<
		"\n\t\tPrice: " << tour->getPrice() <<
		"\n\t\tStart date: " << tour->getStartDate() <<
		"\n\t\tFinish date: " << tour->getFinishDate() <<
		"\n\t\tDescription: " << tour->getDescription();
}