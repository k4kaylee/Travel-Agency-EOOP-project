#define _CRT_SECURE_NO_WARNINGS
#include "Booking.h"
#include <cstring>
#include <iostream>
#include <sstream>




Booking::Booking(Tour* tr, bookingStatus st) {
	setBookingDate(getCurrentDate());
	setTour(tr);
	setStatus(st);
}

Booking::~Booking() {
	delete[] bookingDate;
}

// Getters
char* Booking::getBookingDate() { return bookingDate; }
char* Booking::getName() { return tour->getName(); }
Tour* Booking::getTour() { return tour; }
bookingStatus Booking::getStatus() { return status; }
char* Booking::getCurrentDate() {
	std::time_t now = std::time(nullptr);
	char currentTime[20];
	std::strftime(currentTime, 20, "%Y-%m-%d %H:%M:%S", std::localtime(&now));
	return currentTime;
}

//Setters
void Booking::setBookingDate(const char* bd) {
    delete[] bookingDate;
    bookingDate = new char[strlen(bd) + 1];
    strcpy(bookingDate, bd);
}

void Booking::setTour(Tour* t) {
	if (tour != nullptr) {
		delete tour;
	}
	tour = t; 
}

void Booking::setStatus(bookingStatus st) {
	status = st;
}

void Booking::print() {
	if (status == bookingStatus::ongoing) {
		std::cout << "\tBooking status: ongoing";
	}
	else {
		std::cout << "\tBooking status: finished";
	}
	std::cout << "\n\tBooking date : " << bookingDate <<
		         "\n\tLinked tour: \n";
	std::cout << "\t\tName: " << tour->getName() <<
		"\n\t\tPrice: " << tour->getPrice() <<
		"\n\t\tStart date: " << tour->getStartDate() <<
		"\n\t\tFinish date: " << tour->getFinishDate() <<
		"\n\t\tDescription: " << tour->getDescription();
}

std::string Booking::toString() {
	std::stringstream ss;
	std::string st;
	if (status == ongoing)
		st = "ongoing";
	else
		st = "finished";
	ss << "Booking date: " << getBookingDate() << "\n";
	ss << "Status: " << st << "\n";
	ss << "Tour:\n" << getTour()->toString() << "\n";
	return ss.str();
}

bool Booking::isEqual(Booking* item) {
	return strcmp(this->getTour()->getName(), item->getTour()->getName()) == 0;
}
