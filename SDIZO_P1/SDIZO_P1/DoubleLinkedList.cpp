#include "DoubleLinkedList.h"

ElemList::ElemList() {
	data = 0;
	next = nullptr;
	prev = nullptr;
}

DoubleLinkedList::DoubleLinkedList() {
	head = nullptr;
	tail = nullptr;
	count = 0;
}

int DoubleLinkedList::front() {
	return head->data;
}

int DoubleLinkedList::back() {
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

	count++;
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

	count++;
}

void DoubleLinkedList::pushAtPosition(int data, int position) {
	if (tail == nullptr)
		pushFront(data);
	else {
		if (position <= 0) {
			pushBack(data);
			return;
		}
		if (position >= count) {
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

				count++;
				break;
			}
			i++;
			tmp = tmp->prev;
		}
	}
}

void DoubleLinkedList::popFront() {
	if (count == 0)
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
	count--;
}

void DoubleLinkedList::popBack() {
	if (count == 0)
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
	count--;
}

bool DoubleLinkedList::isEmpty() {
	if (count == 0)
		return true;
	else
		return false;
}

int DoubleLinkedList::size() {
	return count;
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

ElemList * DoubleLinkedList::getHead() {
	return head;
}
ElemList * DoubleLinkedList::getTail() {
	return tail;
}