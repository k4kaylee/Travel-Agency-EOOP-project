#pragma once
class Client;
class Booking;
class Tour;
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
class List {
public:
	struct Item {
		T* ptr;
		Item* next;
	};
	List() {
		head = nullptr;
	}
	~List() {
		this->free();
	}

	Item* getHead() { return head; };

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

	bool find(T* item) {
		for (Item* temp = head; temp != nullptr; temp = temp->next) {
			if (temp->ptr->isEqual(item)) {
				return true;
			}
		}
		return false;
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

	std::string splitString(std::string str) {
		return str;
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

			std::vector<std::string> groupOfResults; //contains the search result string splitted in groups up to 15 strings in each
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
				highlighted = splitString(highlighted);
				std::cout << highlighted << std::endl;
			}
			curr = curr->next;
		}
		if (!foundAny) {
			//highlighted = this->toString();
			std::cout << this->toString();
		}
	}

	void remove(T* item) {
		Item* current = NULL;
		Item* previous = NULL;
		for (Item* temp = head; temp != NULL; temp = temp->next) {
			if (temp->ptr->isEqual(item)) {
				current = temp;
				break;
			}
			previous = temp;
		}
		if (current == NULL) {
			std::cout << "'" << item->getName() << "'" << " was not found.\n";
			return;
		}

		if (previous == NULL) {
			head = current->next;
		}
		else {
			previous->next = current->next;
		}
		delete current->ptr;
		delete current;
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

	std::vector<std::string> toVector(){
		std::vector<std::string> vec;
		std::string item = this->toString();
		std::istringstream tokenStream(item);
		while (std::getline(tokenStream, item, '\n')) {
			vec.push_back(item);
		}

		return vec;
	};

	T* getItemByName(std::string name) {
		for (Item* temp = head; temp != nullptr; temp = temp->next) {
			if (strcmp(temp->ptr->getName(), name.c_str()) == 0) {
				return temp->ptr;
			}
		}
		return nullptr;
	};

private:
	Item* head;
};
