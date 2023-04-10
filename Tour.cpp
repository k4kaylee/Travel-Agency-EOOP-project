#define _CRT_SECURE_NO_WARNINGS
#include "Tour.h"
#include <cstring>
#include <iostream>


Tour::Tour(const char* nm, float prc, const char* strtDt, const char* fnshDt, const char* dscrptn) {
	setName(nm);
	setPrice(prc);
	setDescription(dscrptn);
	setStartDate(strtDt);
	setFinishDate(fnshDt);
}

Tour::~Tour() {
	delete[] name;
	delete[] finishDate;
	delete[] startDate;
	delete[] description;
}

void Tour::setName(const char* nm) {
	delete[] name;
	name = new char[strlen(nm) + 1];
	strcpy(name, nm);
}

void Tour::setFinishDate(const char* fnshDt) {
	delete[] finishDate;
	finishDate = new char[strlen(fnshDt) + 1];
	strcpy(finishDate, fnshDt);
}

void Tour::setPrice(float prc) {
	price = prc;
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
	std::cout << "Name: " << name <<
		"\nPrice: " << price <<
		"\nStart date: " << startDate <<
		"\nFinish date: " << finishDate <<
		"\nDescription: " << description << "\n\n";
}