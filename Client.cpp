#define _CRT_SECURE_NO_WARNINGS
#include "Client.h";
#include "List.h"
#include <cstring>;
#include <ctime>;
#include <iostream>
#include <sstream>


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
List<Booking>* Client::getListOfBookings() { return listOfBookings; }

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
                 "\nEmail: " << email <<
                 "\nBookings: \n";
    if (listOfBookings->getHead() == nullptr)
        std::cout << "\tNo bookings were made.\n\n";
    else
        listOfBookings->print();
}

void Client::book(Tour* tr, int numOfCl) {
    Booking* newBooking = new Booking(tr);
    listOfBookings->add(newBooking);
}


std::string Client::toString() {
    std::stringstream ss;
    ss << "Name: " << name << "\n";
    ss << "Lastname: " << lastname << "\n";
    ss << "Phone number: " << phoneNumber << "\n";
    ss << "Email: " << email << "\n";
    ss << "List of bookings:\n";
    if (listOfBookings != nullptr) {
        ss << listOfBookings->toString();
    }
    return ss.str();
}

bool Client::isEqual(Client* item) {
    return strcmp(this->getName(), item->getName()) == 0;
}