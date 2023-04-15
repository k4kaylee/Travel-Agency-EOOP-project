#pragma once
class Client;
class Booking;
class Tour;
#include <string>
#include <iostream>
#include <algorithm>



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
		bool foundAny = false;
		while (curr != nullptr) {
			T* value = curr->ptr;
			std::string str = value->toString();
			std::stringstream ss(str);
			std::string line;
			std::string highlighted;
			bool found = false;

			std::string searchLower = search;
			std::transform(searchLower.begin(), searchLower.end(), searchLower.begin(), ::tolower);


			while (std::getline(ss, line)) {
				std::string lineLower = line;
				std::transform(lineLower.begin(), lineLower.end(), lineLower.begin(), ::tolower);
				size_t colonPos = line.find(':');
				if (colonPos != std::string::npos) {	
					size_t searchPos = lineLower.find(searchLower, colonPos + 1);
					if (searchPos != std::string::npos) {
						found = true;
						std::string searchHighlight = line.substr(searchPos, search.length());
						std::string replaceStr = "\033[31m" + searchHighlight + "\033[0m";
						line.replace(searchPos, search.length(), replaceStr);
					}
				}
				highlighted += line + "\n";
			}

			if (found) {
				foundAny = true;
				std::cout << highlighted << std::endl;
			}
			curr = curr->next;
		}
		if (!foundAny) {
			std::cout << this->toString();
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

	
