#define _CRT_SECURE_NO_WARNINGS
#include "Tour.h"
#include <cstring>
#include <iostream>


Tour::Tour(const char* nm, const char* drtn, float prc, const char* rt, const char* strtDt, const char* dscrptn) {
	setName(nm);
	setDuration(drtn);
	setPrice(prc);
	setRoute(rt);
	setDescription(dscrptn);
	setStartDate(strtDt);
}

Tour::~Tour() {
	delete[] name;
	delete[] duration;
	delete[] route;
	delete[] description;
}

void Tour::setName(const char* nm) {
	delete[] name;
	name = new char[strlen(nm) + 1];
	strcpy(name, nm);
}

void Tour::setDuration(const char* drtn) {
	delete[] duration;
	duration = new char[strlen(drtn) + 1];
	strcpy(duration, drtn);
}

void Tour::setPrice(float prc) {
	price = prc;
}

void Tour::setRoute(const char* rt) {
	delete[] route;
	route = new char[strlen(rt) + 1];
	strcpy(route, rt);
}

void Tour::setStartDate(const char* strtDt) {
	delete[] startDate;
	startDate = new char[strlen(strtDt) + 1];
	strcpy(startDate, strtDt);
}

void Tour::setDescription(const char* dscrptn) {
	delete[] description;
	description = new char[strlen(dscrptn) + 1];
	strcpy(description, dscrptn);
}

void Tour::print() {
	std::cout << "\nName: " << name <<
		"\nDuration: " << duration <<
		"\nPrice: " << price <<
		"\nRoute: " << route <<
		"\nDescription: " << description << std::endl;
}