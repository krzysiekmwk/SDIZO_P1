#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main() {

	DoubleLinkedList * list = new DoubleLinkedList();
	cout << list->size() << endl;
	list->push_back(10);
	cout << list->size() << endl;
	list->pop_back();
	cout << list->size() << endl;


	int x;
	cin >> x;

	return 0;
}