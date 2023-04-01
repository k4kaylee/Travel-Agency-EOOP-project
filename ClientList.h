#pragma once
#include "Client.h"



class ClientList{
private:
	Client* current;
	Client* next;
public:
	ClientList();
	~ClientList();
};

