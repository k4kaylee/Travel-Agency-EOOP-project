#pragma once


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


	void add(Item newItem) {
		Item* current = head;
		Item* previous = nullptr;

		while (current != nullptr && strcmp(current->item->name, current->item->name < 0)) {
			previous = current;
			current = current->next;
		}
		if (previous == nullptr) {
			newItem->next = head;
			head = newItem;
		}
		else {
			previous->next = newItem;
			newItem->next = current;
		}
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


