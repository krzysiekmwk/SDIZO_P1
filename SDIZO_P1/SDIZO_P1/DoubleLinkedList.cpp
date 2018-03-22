#include "DoubleLinkedList.h"

ElemList::ElemList() {	//constructor of helper class.
	data = 0;
	next = nullptr;
	prev = nullptr;
}

DoubleLinkedList::DoubleLinkedList() {
	head = nullptr;
	tail = nullptr;
	amount = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
	clear();	//In destructor we need to clear all data
}

int DoubleLinkedList::front() {
	if (amount == 0)
		return -1;
	return head->data;	//return last element
}

int DoubleLinkedList::back() {
	if (amount == 0)
		return -1;
	return tail->data;	// return first element
}

void DoubleLinkedList::pushFront(int data) {
	ElemList * elem = new ElemList;	//Create new element
	elem->data = data;
	elem->prev = nullptr;
	elem->next = head;	// element hav pointer for previous element

	if (head != nullptr)	//if list is not empty assign new element to pointer in previous object
		head->prev = elem;	// Element will be as first element in the list
	else
		tail = elem;	// if list was empty, the tail is pointer for actual element

	head = elem;	// new element is new head

	amount++;
}

void DoubleLinkedList::pushBack(int data) {
	ElemList * elem = new ElemList;
	elem->data = data;
	elem->prev = tail;	// have pointer to tail in list.
	elem->next = nullptr;

	if (tail != nullptr)
		tail->next = elem;	// add as last element at 0 position
	else
		head = elem;

	tail = elem;	// new element is new tail

	amount++;
}

void DoubleLinkedList::pushAtPosition(int data, int position) {
	if (tail == nullptr)
		pushFront(data);
	else {
		if (position <= 0) {	//if index is wrong and smaller than 0 push it as first element
			pushBack(data);
			return;
		}
		if (position >= amount) { //if index is wrong and bigger than sizse of list push it as last element
			pushFront(data);
			return;
		}
		
		// start searching from 0 position. from tail.
		int i = 0;
		ElemList *tmp = tail; //Don't change the tail. There is only pointer which is poining for tail
		while (tmp != nullptr) {
			if (i == position) {	//if there such position then insert new element there
				ElemList * elem = new ElemList;
				elem->data = data;
				elem->next = tmp->next; //push beetween two of elements
				elem->prev = tmp;
				tmp->next->prev = elem;
				tmp->next = elem;

				amount++;
				break;
			}
			i++;
			tmp = tmp->prev;	// move pointer to the next element in list
		}
	}
}

void DoubleLinkedList::popFront() {
	if (amount == 0)
		return;
	if (head->next != nullptr) {
		ElemList * newHead = head->next;	// pointer for new haed which is just previous value
		newHead->prev = nullptr;
		delete head;	// release memory for old object
		head = newHead;
	}
	else{
		delete head;
		head = tail = nullptr;
	}
	amount--;
}

void DoubleLinkedList::popBack() {
	if (amount == 0)
		return;
	if (tail->prev != nullptr) {
		ElemList * newTail = tail->prev;
		newTail->next = nullptr;
		delete tail;
		tail = newTail;
	}
	else {
		delete tail;
		head = tail = nullptr;
	}
	amount--;
}

void DoubleLinkedList::popAtPosition(int position) {
	if (amount == 0)
		return;
	else {
		if (position <= 0) {
			popBack();
			return;
		}
		if (position >= amount) {
			popFront();
			return;
		}

		int i = 0;
		ElemList *tmp = tail; //Very simmilar to pushing at specifiet position. except there we will delete old data
		while (tmp != nullptr) {
			if (i == position) {
				ElemList * elem = tmp->prev;
				elem->next = tmp->next;
				tmp->next->prev = elem;
				delete tmp;

				amount--;
				break;
			}
			i++;
			tmp = tmp->prev;
		}
	}
}

bool DoubleLinkedList::isEmpty() {
	if (amount == 0)
		return true;
	else
		return false;
}

int DoubleLinkedList::size() {
	return amount;
}

int DoubleLinkedList::at(int index) {
	int i = 0;
	ElemList *tmp = tail; //Enumerate from beginig of List. Just like an array. from 0 to size
	while (tmp != nullptr){
		if (i == index)
			return tmp->data;
		i++;
		tmp = tmp->prev;
	}
	return 0;
}

bool DoubleLinkedList::contains(int data) {
	int i = 0;
	ElemList *tmp = tail; //Enumerate from beginig of List
	while (tmp != nullptr) {
		if (tmp->data == data)
			return true;
		i++;
		tmp = tmp->prev;
	}

	return false;
}

void DoubleLinkedList::clear() {	// Pop all elements just to be sure to release all memory
	while (amount > 0) {
		popFront();
	}
}
