#pragma once
#include "Tour.h"


enum bookingStatus {
	finished,
	ongoing
};

class Booking{
private:
	char* bookingDate;
	int numberOfClients;
	Tour* tour;
	bookingStatus status;
public:
	Booking(const char* bDate, int numOfCl, Tour* tr);
	~Booking();

	// Getters
	char* getBookingDate();
	int getNumberOfClients();
	Tour* getTour();

	//Setters
	void setBookingDate(const char* bDate);
	void setNumberOfClients(int numOfCl);
	void setTour(Tour* tr);

	void print();
};

