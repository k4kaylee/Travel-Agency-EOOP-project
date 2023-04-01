#include "Tour.h"
#include <cstring>


Tour::Tour(char* nm, char* drtn, float prc, char* rt, char* dscrptn) {
	setName(nm);
	setDuration(drtn);
	setPrice(prc);
	setRoute(rt);
	setDescription(dscrptn);
}

Tour::~Tour() {
	delete name;
	delete duration;
	delete route;
	delete description;
}

void Tour::setName(char* nm) {
	delete[] name;
	name = new char[strlen(nm) + 1];
	strcpy(name, nm);
}

void Tour::setDuration(char* drtn) {
	delete[] duration;
	duration = new char[strlen(drtn) + 1];
	strcpy(duration, drtn);
}

void Tour::setPrice(float prc) {
	price = prc;
}

void Tour::setRoute(char* rt) {
	delete[] route;
	route = new char[strlen(rt) + 1];
	strcpy(route, rt);
}

void Tour::setDescription(char* dscrptn) {
	delete[] description;
	description = new char[strlen(dscrptn) + 1];
	strcpy(description, dscrptn);
}