#include "ClientList.h"



ClientList::ClientList() {
	current = nullptr;
	next = nullptr;
}

ClientList::~ClientList() {
	delete current;
	delete next;
}
