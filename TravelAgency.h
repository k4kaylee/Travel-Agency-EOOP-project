#pragma once
#include "List.h"
#include "Client.h"
#include "Tour.h"




class TravelAgency{
private:
	List<Tour>* listOfTours;
	List<Client>* listOfClients;
public:
	TravelAgency(List<Tour>* lOt, List<Client>* lOc);
	~TravelAgency();

	List<Tour>* getTourList() { return  listOfTours; };
	List<Client>* getClientList() { return listOfClients; };
	void setTourList(List<Tour>* lOt);
	void setClientList(List<Client>* cOl);

};

