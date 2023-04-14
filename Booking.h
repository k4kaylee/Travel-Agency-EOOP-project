#pragma once
#include "Tour.h"
#include <string>

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
	~Booking(void);

	// Getters
	char* getBookingDate(void);
	int getNumberOfClients(void);
	Tour* getTour(void);
	bookingStatus getStatus(void);

	//Setters
	void setBookingDate(const char* bDate);
	void setNumberOfClients(int numOfCl);
	void setTour(Tour* tr);
	std::string toString(void);

	void print(void);
};

