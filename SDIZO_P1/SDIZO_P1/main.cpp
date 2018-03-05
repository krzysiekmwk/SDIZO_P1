#include <iostream>
#include "DoubleLinkedList.h"
#include <vector>

using namespace std;

void displayListFront(DoubleLinkedList list) {
	for (int i = 0; i < list.size(); i++)
		cout << list.at(i) << endl;
}

void addElement(DoubleLinkedList *list) {
	list->push_front(69);
}


int main() {

	DoubleLinkedList list;
	//cout << list->front()->data << endl; //nullptr exeption
	int x = 0;
	cout << sizeof(int) << endl;
	for (int i = 0; i < 10; i++)
	{
		//cout << x << ", ";
		list.push_front(x);
		x = x + 2;
	}

	displayListFront(list);
	addElement(&list);
	displayListFront(list);

	int YYY;
	cin >> YYY;

	return 0;
}