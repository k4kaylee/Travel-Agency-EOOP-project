#pragma once
#include "Tour.h"


template<typename T> class List {
private:
	struct Item {
		T* ptr;
		Item* next;
	};
	Item* head;
public:
	List() {
		head = nullptr;
	}
	~List() {
		this->free();
	}


	void add() {

	}


	void free() {
		Item* curr = this->head;
		while (curr != nullptr) {
			Item* temp = curr;
			curr = curr->next;
			delete temp->ptr;
			delete temp;
		}
	}
};


