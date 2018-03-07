#include <iostream>
#include "DoubleLinkedList.h"
#include "ArrayList.h"

using namespace std;

void displayListFront(DoubleLinkedList list) {
	for (int i = 0; i < list.size(); i++)
		cout << list.at(i) << ", ";

	cout << endl;
}

void displayListFront(ArrayList list) {
	for (int i = 0; i < list.size(); i++)
		cout << list.at(i) << ", ";

	cout << endl;
}

int main() {

	DoubleLinkedList list;

	list.pushFront(1);
	list.pushFront(2);
	list.pushFront(3);
	list.pushBack(4);
	displayListFront(list); //should be 4,1,2,3

	list.pushAtPosition(9,1);
	displayListFront(list); //should be 4,9,1,2,3

	list.popAtPosition(1);
	displayListFront(list); //should be 4,1,2,3

	list.popFront();
	displayListFront(list); //should be 4,1,2

	list.popBack();
	displayListFront(list); //should be 1,2

	list.pushBack(44);
	list.pushFront(22);
	displayListFront(list);

	int YYY;
	cin >> YYY;

	return 0;
}