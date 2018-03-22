#include "DoubleLinkedList.h"

ElemList::ElemList() {
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
	clear();
}

int DoubleLinkedList::front() {
	if (amount == 0)
		return -1;
	return head->data;
}

int DoubleLinkedList::back() {
	if (amount == 0)
		return -1;
	return tail->data;
}

void DoubleLinkedList::pushFront(int data) {
	ElemList * elem = new ElemList;
	elem->data = data;
	elem->prev = nullptr;
	elem->next = head;

	if (head != nullptr)
		head->prev = elem;
	else
		tail = elem;

	head = elem;

	amount++;
}

void DoubleLinkedList::pushBack(int data) {
	ElemList * elem = new ElemList;
	elem->data = data;
	elem->prev = tail;
	elem->next = nullptr;

	if (tail != nullptr)
		tail->next = elem;
	else
		head = elem;

	tail = elem;

	amount++;
}

void DoubleLinkedList::pushAtPosition(int data, int position) {
	if (tail == nullptr)
		pushFront(data);
	else {
		if (position <= 0) {
			pushBack(data);
			return;
		}
		if (position >= amount) {
			pushFront(data);
			return;
		}
			
		int i = 0;
		ElemList *tmp = tail; //Don't change the tail. 
		while (tmp != nullptr) {
			if (i == position) {
				ElemList * elem = new ElemList;
				elem->data = data;
				elem->next = tmp->next;
				elem->prev = tmp;
				tmp->next->prev = elem;
				tmp->next = elem;

				amount++;
				break;
			}
			i++;
			tmp = tmp->prev;
		}
	}
}

void DoubleLinkedList::popFront() {
	if (amount == 0)
		return;
	if (head->next != nullptr) {
		ElemList * newHead = head->next;
		newHead->prev = nullptr;
		delete head;
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
		ElemList *tmp = tail; //Don't change the tail. 
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
	ElemList *tmp = tail; //Enumerate from beginig of List
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

void DoubleLinkedList::clear() {
	while (amount > 0) {
		popFront();
	}
}