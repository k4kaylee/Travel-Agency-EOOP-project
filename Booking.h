#pragma once
#include "List.h"
#include "Tour.h"
#include "Client.h"


class Booking{
private:
	char* bookingDate;
	char* startDate;
	int numberOfClients;
	List<Client>* listOfClients;
	Tour* tour;
public:
	Booking(char* bDate, char* stDate, int numOfCl, List<Client>* lOfClients, Tour* tr);
	~Booking();

	// Getters
	char* getBookingDate();
	char* getStartDate();
	int getNumberOfClients();
	List<Client>* getListOfClients();
	Tour* getTour();

	//Setters
	void setBookingDate(char* bDate);
	void setStartDate(char* stDate);
	void setNumberOfClients(int numOfCl);
	void setListOfClients(List<Client>* lOfClients);
	void setTour(Tour* tr);
};

