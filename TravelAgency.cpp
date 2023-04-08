#include "TravelAgency.h"



TravelAgency::TravelAgency(List<Tour>* lOt, List<Client>* lOc) {
	setTourList(lOt);
	setClientList(lOc);
}

TravelAgency::~TravelAgency() {
	listOfClients->free();
}

void TravelAgency::setTourList(List<Tour>* lOt) {
	listOfTours = lOt;
}

void TravelAgency::setClientList(List<Client>* lOc) {
	listOfClients = lOc;
}
