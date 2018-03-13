#pragma once

class ArrayList {
public:
	ArrayList();
	int front();									//Returns the first element in the list
	int back();										//Returns the last element in the list
	void pushFront(int data);						//Adds a new element 'data' at the beginning of the list
	void pushBack(int data);						//Adds a new element 'data' at the end of the list
	void pushAtPosition(int data, int position);	//Adds new elements 'data' in the list at a specified position
	void popFront();								//Removes the first element of the list, and reduces size of the list by 1
	void popBack();									//Removes the last element of the list, and reduces size of the list by 1
	void popAtPosition(int position);				//Removes element of the list at a specified position, and reduces size of the list by 1
	bool isEmpty();									//Returns whether the list is empty(1) or not(0)
	int size();										//Returns the number of elements in the list
	int at(int index);								//Returns element at a specified position
	bool contains(int data);						//Returns true if list contain some data or false if it does not

private:
	int amount;
	int *arrayList;
};
