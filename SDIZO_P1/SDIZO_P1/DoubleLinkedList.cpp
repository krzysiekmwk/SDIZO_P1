#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {
	count = 0;
}

DoubleLinkedList * DoubleLinkedList::front() {
	return head;
}

DoubleLinkedList * DoubleLinkedList::back() {
	return tail;
}

void DoubleLinkedList::push_front(int data) {
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