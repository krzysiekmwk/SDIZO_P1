#include <iostream>
#include <string>
#include "DoubleLinkedList.h"
#include "ArrayList.h"
#include "Heap.h"

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

void displayHeap(Heap heap) {
	int * arrayList = heap.getArray();

	for (int i = 0;i < heap.size();i++)
		std::cout << arrayList[i] << ", ";
	std::cout << std::endl;
}

string cr, cl, cp;
Heap heap;
int n = 0;
void printBT(string sp, string sn, int v)
{
	int * arrayList = heap.getArray();

	string s;

	if (v < heap.size())
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBT(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << arrayList[v] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl, 2 * v + 1);
	}
}

int main() {
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	/*
	ArrayList list;

	list.pushFront(1);
	list.pushFront(2);
	list.pushFront(3);
	list.pushBack(4);
	displayListFront(list); //should be 4,1,2,3

	list.pushAtPosition(9,1);
	displayListFront(list); //should be 4,9,1,2,3
	cout << list.contains(3) << endl;
	cout << list.contains(4) << endl;
	cout << list.contains(15) << endl;

	list.popAtPosition(1);
	displayListFront(list); //should be 4,1,2,3

	list.popFront();
	displayListFront(list); //should be 4,1,2

	list.popBack();
	displayListFront(list); //should be 1,2

	list.pushBack(44);
	list.pushFront(22);

	cout << list.contains(44) << endl;
	cout << list.contains(9) << endl;
	displayListFront(list);
	*/
	

	heap.push(18);
	printBT("", "", 0);
	heap.push(17);
	printBT("", "", 0);
	heap.push(16);
	printBT("", "", 0);
	heap.push(12);
	printBT("", "", 0);
	heap.push(15);
	printBT("", "", 0);
	heap.push(3);
	printBT("", "", 0);
	heap.push(9);
	printBT("", "", 0);
	heap.push(6);
	printBT("", "", 0);
	heap.push(5); 
	printBT("", "", 0);
	heap.push(2);
	printBT("", "", 0);
	heap.push(13);
	printBT("", "", 0);

	heap.pop();
	displayHeap(heap);
	printBT("", "", 0);

	//cout << heap.contains(9) << endl;

	int YYY;
	cin >> YYY;

	return 0;
}