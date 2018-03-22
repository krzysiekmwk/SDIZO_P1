#pragma once

class Heap {
public:
	Heap();						//Constructor
	~Heap();					//Deconstructor for Heap
	void push(int data);		//Push data
	void pop();					//Pop element in root
	int getRoot();				//Returns data in root
	int size();					//Returns size of Heap
	bool contains(int data);	//Returns true if heap contains sought data or false if it does not
	int *getArray();			//Returns array from heap.
	void clear();				//Clear all heap

private:
	int getParentIndex(int childIndex);			//Returns index of parent
	int getLeftChildIndex(int parentIndex);		//returns index of left child
	int getRightChildIndex(int parentIndex);	//returns index of right child
	bool containsHelper(int index, int data, bool *found);	//Method for searching data
	void fixToUp(int data, int index);			//Methos which is reapairing heap from down to up. Using after adding new element
	void fixToDown(int data, int index);		//Method which is reapairing the heap from up to down after deleting root.
	int *arrayList;
	int amount;
};