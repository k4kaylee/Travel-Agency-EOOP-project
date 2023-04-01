#pragma once
#include "List.h"



class Client{
private:
	char* name;
	char* lastname;
	char* phoneNumber;
	char* email;
	List<Tour>* listOfOrderedTours;
public:
    Client(char* n, char* ln, char* ph, char* e);
    ~Client();

    // Getters
    char* getName();
    char* getLastName();
    char* getPhoneNumber();
    char* getEmail();

    // Setters
    void setName(char* n);
    void setLastname(char* n);
    void setPhoneNumber(char* n);
    void setEmail(char* n);
};

