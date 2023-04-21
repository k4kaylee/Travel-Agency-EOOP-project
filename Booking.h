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
	Tour* tour;
	bookingStatus status;
public:
	Booking(Tour* tr, bookingStatus st = ongoing);
	~Booking(void);

	// Getters
	char* getBookingDate(void);
	Tour* getTour(void);
	bookingStatus getStatus(void);

	char* getCurrentDate();

	//Setters
	void setBookingDate(const char* bDate);
	void setTour(Tour* tr);
	void setStatus(bookingStatus st);
	std::string toString(void);

	void print(void);

	bool isEqual(Booking* item);
};

