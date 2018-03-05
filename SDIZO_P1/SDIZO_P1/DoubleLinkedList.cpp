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

ElemList * DoubleLinkedList::front() {
	return head;
}

ElemList * DoubleLinkedList::back() {
	return tail;
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
	count++;
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

void DoubleLinkedList::insert(int data, int position) {

}

int DoubleLinkedList::size() {
	return count;
}