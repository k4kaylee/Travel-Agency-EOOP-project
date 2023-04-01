#define _CRT_SECURE_NO_WARNINGS
#include "Client.h";
#include <cstring>;



Client::Client(char* n, char* ln, char* ph, char* em) {
    setName(n);
    setLastname(ln);
    setPhoneNumber(ph);
    setEmail(em);
}


Client::~Client() {
    delete[] name;
    delete[] lastname;
    delete[] phoneNumber;
    delete[] email;
}

// Getters
char* Client::getName() { return name; }
char* Client::getLastName() { return lastname; }
char* Client::getPhoneNumber() { return phoneNumber; }
char* Client::getEmail() { return email; }

// Setters
void Client::setName(char* n) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

void Client::setLastname(char* ln) {
    delete[] lastname;
    lastname = new char[strlen(ln) + 1];
    strcpy(lastname, ln);
}

void Client::setPhoneNumber(char* ph) {
    delete[] phoneNumber;
    phoneNumber = new char[strlen(ph) + 1];
    strcpy(phoneNumber, ph);
}

void Client::setEmail(char* em) {
    delete[] email;
    email = new char[strlen(em) + 1];
    strcpy(email, em);
}

