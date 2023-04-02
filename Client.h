#pragma once
#include "List.h"
#include "Tour.h"


class Client{
private:
	char* name;
	char* lastname;
	char* phoneNumber;
	char* email;
	List<Tour>* listOfOrderedTours;
public:
    Client(const char* n, const char* ln, const char* ph, const char* e);
    ~Client();

    // Getters
    char* getName();
    char* getLastName();
    char* getPhoneNumber();
    char* getEmail();

    // Setters
    void setName(const char* n);
    void setLastname(const char* n);
    void setPhoneNumber(const char* n);
    void setEmail(const char* n);
};

