#pragma once
class Client;
class Booking;
class Tour;
#include <cstring>
#include <iostream>

template<typename T> 
class List {
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


	void add(Client* itemPtr) {
		Item* newItem = new Item;
		newItem->ptr = itemPtr;
		newItem->next = nullptr;
		
		if (head == nullptr || strcmp(head->ptr->getName(), newItem->ptr->getName()) > 0) {
			newItem->next = head;
			head = newItem;
		}
		else {
			Item* current = head;
			while (current->next != nullptr && strcmp(current->next->ptr->getName(), newItem->ptr->getName()) < 0) {
				current = current->next;
			}
			newItem->next = current->next;
			current->next = newItem;
		}
	}

	void add(Tour* itemPtr) {
		Item* newItem = new Item;
		newItem->ptr = itemPtr;
		newItem->next = nullptr;

		if (head == nullptr || strcmp(head->ptr->getName(), newItem->ptr->getName()) > 0) {
			newItem->next = head;
			head = newItem;
		}
		else {
			Item* current = head;
			while (current->next != nullptr && strcmp(current->next->ptr->getName(), newItem->ptr->getName()) < 0) {
				current = current->next;
			}
			newItem->next = current->next;
			current->next = newItem;
		}
	}
	
	void add(Booking* itemPtr) {
		Item* newItem = new Item;
		newItem->ptr = itemPtr;
		newItem->next = nullptr;

		if (head == nullptr || strcmp(head->ptr->getBookingDate(), newItem->ptr->getBookingDate()) > 0) {
			newItem->next = head;
			head = newItem;
		}
		else {
			Item* current = head;
			while (current->next != nullptr && strcmp(current->next->ptr->getBookingDate(), newItem->ptr->getBookingDate()) < 0) {
				current = current->next;
			}
			newItem->next = current->next;
			current->next = newItem;
		}
	}


	void print() {
		Item* current = head;
		if (current != nullptr) {
			while (current != nullptr) {
				current->ptr->print();
				current = current->next;
			}
			std::cout << "\n\n";
		}
	};

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


