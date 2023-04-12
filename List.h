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

	Item* getHead() { return head; };

	bool find(T* item) {
		for (Item* temp = head; temp != nullptr; temp = temp->next) {
			if (strcmp(temp->ptr->getName(), item->getName()) == 0) {
				return true;
			}
			return false;
		}
	};



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
		else {
			std::cout << "Selected list is empty\n";
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


	void search(const std::string& search) {
		Item* curr = head;
		while (curr != nullptr) {
			T* value = curr->ptr;
			std::string str = value->toString();
			std::string highlighted;
			size_t pos = 0;
			while ((pos = str.find(search, pos)) != std::string::npos) {
				highlighted += str.substr(pos, search.length());
				highlighted = highlighted.substr(0, pos) + "\033[31m" + highlighted.substr(pos, search.length()) + "\033[0m" + highlighted.substr(pos + search.length());
				pos += search.length();
			}
			std::cout << highlighted << std::endl;
			curr = curr->next;
		}
	}

	std::string toString() {
		std::stringstream ss;
		Item* current = this->getHead();
		while (current != nullptr) {
			ss << current->ptr->toString() << "\n";
			current = current->next;
		}
		return ss.str();
	}
};

	
