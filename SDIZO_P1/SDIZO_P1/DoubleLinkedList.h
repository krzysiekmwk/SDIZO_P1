#pragma once

class DoubleLinkedList {

private: 
	int data;
	DoubleLinkedList *next, *prev, *head, *tail;
	int count;

public:
	DoubleLinkedList();
	~DoubleLinkedList();
	DoubleLinkedList * front();			//Returns reference to the first element in the list
	DoubleLinkedList * back();			//Returns reference to the last element in the list
	void push_front(int data);				//Adds a new element ‘g’ at the beginning of the list
	void push_back(int data);				//Adds a new element ‘g’ at the end of the list
	void pop_front();						//Removes the first element of the list, and reduces size of the list by 1
	void pop_back();						//Removes the last element of the list, and reduces size of the list by 1
	bool isEmpty();						//Returns whether the list is empty(1) or not(0)
	void insert(int data, int position);	//Inserts new elements in the list before the element at a specified position
	int size();							//Returns the number of elements in the list
};