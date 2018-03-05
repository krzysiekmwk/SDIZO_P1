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

void DoubleLinkedList::push_front(int data) {
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

void DoubleLinkedList::push_back(int data) {
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

void DoubleLinkedList::puchPosition(int data, int position) {
	if (tail == nullptr)
		push_front(data);
	else {
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

void DoubleLinkedList::pop_front() {
	count--;
}

void DoubleLinkedList::pop_back() {
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