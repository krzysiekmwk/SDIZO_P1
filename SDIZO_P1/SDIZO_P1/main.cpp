#include <iostream>
#include "DoubleLinkedList.h"
#include <vector>

using namespace std;

void displayListFront(DoubleLinkedList list) {
	for (int i = 0; i < list.size(); i++)
		cout << list.at(i) << ", ";

	cout << endl;
}

int main() {

	DoubleLinkedList list;

	list.pushFront(1);
	list.pushFront(2);
	list.pushFront(3);

	displayListFront(list);

	list.pushAtPosition(9,1); //should be 1,9,2,3

	displayListFront(list);

	list.popAtPosition(1); //should be 1,2,3

	displayListFront(list);

	int YYY;
	cin >> YYY;

	return 0;
}