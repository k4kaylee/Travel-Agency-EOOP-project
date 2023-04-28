#pragma once
#include "Booking.h"
#include "List.h"
#include "Tour.h"
#include <cstring>


class Client{
private:
	char* name;
	char* lastname;
	char* phoneNumber;
	char* email;
	List<Booking>* listOfBookings;
public:
    Client(const char* n, const char* ln, const char* ph, const char* e, List<Booking>* lOb = new List<Booking>);
    ~Client();
    
    // Getters
    char* getName(void);
    char* getLastName(void);
    char* getPhoneNumber(void);
    char* getEmail(void);
    List<Booking>* getListOfBookings(void);

    // Setters
    void setName(const char* n);
    void setLastname(const char* n);
    void setPhoneNumber(const char* n);
    void setEmail(const char* n);

    void book(Tour* tr);
    void print(void);
    std::string toString();

    bool isEqual(Client* item);
};

