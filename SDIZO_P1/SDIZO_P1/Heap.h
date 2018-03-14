#pragma once

class Heap {
public:
	Heap();
	void push(int data);
	void pop();
	int getRoot();
	int size();
	bool contains(int data);
	int *getArray();

private:
	int getParentIndex(int childIndex);
	int getLeftChildIndex(int parentIndex);
	int getRightChildIndex(int parentIndex);
	bool containsHelper(int index, int data, bool *found);
	void fixToUp(int data, int index);
	void fixToDown(int data, int index);
	int *arrayList;
	int amount;
};