#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main() {

	DoubleLinkedList * list = new DoubleLinkedList();
	//cout << list->front()->data << endl; //nullptr exeption
	list->push_front(10);
	cout << list->front()->data << endl;


	int x;
	cin >> x;

	return 0;
}