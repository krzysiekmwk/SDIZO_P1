#pragma once

class ElemList {
public:
	ElemList();
	int data;
	ElemList *next, *prev;
};

class DoubleLinkedList {
public:
	DoubleLinkedList();
	int front();			//Returns the first element in the list
	int back();			//Returns the last element in the list
	void push_front(int data);				//Adds a new element ‘g’ at the beginning of the list
	void push_back(int data);				//Adds a new element ‘g’ at the end of the list
	void puchPosition(int data, int position);	//Inserts new elements in the list before the element at a specified position
	void pop_front();						//Removes the first element of the list, and reduces size of the list by 1
	void pop_back();						//Removes the last element of the list, and reduces size of the list by 1
	void popPosition();
	bool isEmpty();						//Returns whether the list is empty(1) or not(0)
	int size();							//Returns the number of elements in the list
	int at(int index);
	ElemList * getHead();
	ElemList * getTail();

private:
	ElemList *head, *tail;
	int count;
};