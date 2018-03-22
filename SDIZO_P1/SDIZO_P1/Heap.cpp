#include "Heap.h"
#include <iostream>

Heap::Heap() {
	amount = 0;
	arrayList = new int[0];
}

Heap::~Heap()
{
	delete[] arrayList;
}

void Heap::push(int data) {
	if (amount == 0) {
		arrayList = new int[1];	// add first element as root
		arrayList[0] = data;
		amount++;
	}
	else {

		int increasedAmount = amount + 1;
		int * listCopy = new int[increasedAmount];
		if (listCopy) {

			for (int i = 0; i < amount; i++) {
				listCopy[i] = arrayList[i];	// copy all elements
			}

			listCopy[amount] = data;	// insert new one as last element

			delete[] arrayList;
			arrayList = listCopy;

			fixToUp(data, amount);	// Try to fix heap to up

			amount++;

		}
	}
}


void Heap::pop() {
	if (amount > 0) {
		arrayList[0] = arrayList[amount - 1];	// asign last leaf as root

		int decreasedAmount = amount - 1;
		int * listCopy = new int[decreasedAmount];
		if (listCopy) {

			for (int i = 0; i < decreasedAmount; i++) {
				listCopy[i] = arrayList[i];
			}

			delete[] arrayList;
			arrayList = listCopy;

			amount--;
			fixToDown(getRoot(), 0);	// try to fix to down heap for check all rules of heap

		}
	}
}

void Heap::fixToUp(int data, int index) {
	//check for parent index
	int parentIndex = getParentIndex(index);
	if (arrayList[parentIndex] < data) {	// check if parent is smaller than insertet object
		arrayList[index] = arrayList[parentIndex]; // if is smaller then change position actual data with its parent
		arrayList[parentIndex] = data;

		index = parentIndex;	// Assign new index (change actual top)
		fixToUp(data, index);	// Again check if parent of actual data is smaller or not
	}
}

void Heap::fixToDown(int data, int index) {
	int leftChildIndex = getLeftChildIndex(index);
	int rightChildIndex = getRightChildIndex(index);
	while (leftChildIndex < amount){ // Left index can be smaller than amount when right child will be the same size as heap

		if (arrayList[leftChildIndex] > arrayList[rightChildIndex]) { // if left child is bigger than right child
			if (arrayList[leftChildIndex] > data) {	//if left child is bigger than data then repalce them
				arrayList[index] = arrayList[leftChildIndex];
				arrayList[leftChildIndex] = data;

				index = leftChildIndex;
			}
			else {
				break;
			}
		}
		else {
			if (arrayList[rightChildIndex] > data) {
				arrayList[index] = arrayList[rightChildIndex];
				arrayList[rightChildIndex] = data;

				index = rightChildIndex;
			}
			else {
				break;
			}
		}

		leftChildIndex = getLeftChildIndex(index);
		rightChildIndex = getRightChildIndex(index);
	}
}

int Heap::getParentIndex(int childIndex) {
	return ((childIndex - 1) / 2);
}

int Heap::getLeftChildIndex(int parentIndex) {
	return (2 * parentIndex + 1);
}

int Heap::getRightChildIndex(int parentIndex) {
	return (2 * parentIndex + 2);
}

int Heap::getRoot() {
	return arrayList[0];
}

int Heap::size() {
	return amount;
}

int *Heap::getArray() {
	return arrayList;
}

bool Heap::containsHelper(int index, int data, bool *found) {
	if (index <= amount) {	//Check if index is lower or the same as amount XD
		if (arrayList[index] == data) {
			return true;
		}
		if (getLeftChildIndex(index) <= amount) {				//First check all left children if there is the searched object
			if (arrayList[getLeftChildIndex(index)] == data)
				*found = true;
			if (arrayList[getLeftChildIndex(index)] > data)
				containsHelper(getLeftChildIndex(index), data, found);	//If there is child please force try to find object
		}
		if (*found)			//If there is searched object return true for all recurensions
			return true;
		if (getRightChildIndex(index) < amount) {		//Do the same things for right children
			if (arrayList[getRightChildIndex(index)] == data)
				*found = true;
			if (arrayList[getRightChildIndex(index)] > data)
				containsHelper(getRightChildIndex(index), data, found);
		}
		if (*found)
			return true;
	}
	return false;
}

bool Heap::contains(int data) {
	bool found = false;		//contains helper is a recurencial method so it needs to have data for check if it fouded element in heap
	return containsHelper(0, data, &found);
}

void Heap::clear() {
	amount = 0;
	delete[] arrayList;
	arrayList = new int[0];
}
