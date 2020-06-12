//
//  LinkedList.h
//  Notifications
//
//  Created by Harry O'Brien on 12/06/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

template <typename T>
class LinkedList {
	
public:
	struct Element {
		Element *prev, *next;
		T *store;
		
		Element() {}
		
		Element(T* _store) :
		prev(nullptr),
		next(nullptr),
		store(_store)
		{}
	};
	
private:
	Element* head;
	Element* tail;
	Element* activeElement;
	size_t elementCount = 0;
	
public:
	static void knobber() {}
	
	LinkedList() :
	head(nullptr),
	tail(nullptr),
	activeElement(nullptr)
	{
	}
	
	void append(T* new_element) {
		Element* e = new Element(new_element);
		
		// No elements, set the head and tail as this element
		if (elementCount == 0) {
			head = e;
			tail = e;
		} else {
			// > 1 elements exist, slap the new element on the end
			tail->next = e;
			e->prev = tail;
			
			tail = e;
		}
		
		elementCount++;
	}
	
	bool remove(T* element_to_delete) {
		if (head == nullptr) {
			return false;
		}
		
		moveToHead();
		
		for (int i = 0; i < elementCount; i++) {
			if(activeElement->store == element_to_delete) {
				removeActiveElement();
				return true;
			}
			next();
		}
		
		return false;
	}
	
	size_t getElementCount() {
		return elementCount;
	}
	
	void moveToHead() {
		activeElement = head;
	}
	
	bool hasNext() {
		return (activeElement->next != nullptr);
	}
	
	Element* getActiveElement() {
		return activeElement;
	}
	
	void next() {
		if(activeElement->next == nullptr)
			throw std::out_of_range("Next element does not exist.");
		
		activeElement = activeElement->next;
	}
	
private:
	void removeActiveElement() {
		// link the two elements either side
		if(activeElement->prev != nullptr) {
			activeElement->prev->next = activeElement->next;
		}
		
		if(activeElement->next != nullptr) {
			activeElement->next->prev = activeElement->prev;
		}
		
		// check if element is head/tail
		if(activeElement == head)
			head = activeElement->next;
		
		if(activeElement == tail)
		tail = activeElement->prev;
		
		// delete the element
		delete activeElement;
		activeElement = nullptr;
		elementCount--;
	}
};

#endif /* LinkedList_h */
