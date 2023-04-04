#define _CRT_SECURE_NO_WARNINGS
#include "Client.h";
#include <cstring>;
#include <ctime>;
#include <iostream>


Client::Client(const char* n, const char* ln, const char* ph, const char* em, List<Booking>* lOb) {
    setName(n);
    setLastname(ln);
    setPhoneNumber(ph);
    setEmail(em);
    listOfBookings = lOb;
}


Client::~Client() {
    delete[] name;
    delete[] lastname;
    delete[] phoneNumber;
    listOfBookings->free();
    delete[] email;
}

// Getters
char* Client::getName() { return name; }
char* Client::getLastName() { return lastname; }
char* Client::getPhoneNumber() { return phoneNumber; }
char* Client::getEmail() { return email; }

// Setters
void Client::setName(const char* n) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

void Client::setLastname(const char* ln) {
    delete[] lastname;
    lastname = new char[strlen(ln) + 1];
    strcpy(lastname, ln);
}

void Client::setPhoneNumber(const char* ph) {
    delete[] phoneNumber;
    phoneNumber = new char[strlen(ph) + 1];
    strcpy(phoneNumber, ph);
}

void Client::setEmail(const char* em) {
    delete[] email;
    email = new char[strlen(em) + 1];
    strcpy(email, em);
}

void Client::print() {
    std::cout << "Name: " << name <<
                 "\nLastname: " << lastname <<
                 "\nPhone number: " << phoneNumber <<
                 "\nEmail: " << email << "\n\n";
}

void Client::book(Tour* tr, int numOfCl = 1) {
    std::time_t now = std::time(nullptr);
    char currentTime[20];
    std::strftime(currentTime, 20, "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    Booking* newBooking = new Booking(currentTime, numOfCl, tr);
    listOfBookings->add(newBooking);
}