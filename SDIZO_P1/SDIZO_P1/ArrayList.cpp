#include "ArrayList.h"

ArrayList::ArrayList() {
	amount = 0;
	arrayList = new int[0];	//Initialization an pointer for array in size 0
}

ArrayList::~ArrayList()
{
	delete[] arrayList;		//destructor. release memory where was array
}

int ArrayList::front(){
	if (amount == 0)
		return -1;
	return arrayList[amount - 1];	//return last element
}

int ArrayList::back() {
	if (amount == 0)
		return -1;
	return arrayList[0];		// return first element
}

void ArrayList::pushFront(int data) {
	int increasedAmount = amount + 1;
	int * listCopy = new int[increasedAmount];
	if (listCopy) {	// If there was new allocaded memory

		for (int i = 0; i < increasedAmount; i++) {	//copy all array
			listCopy[i] = arrayList[i];
		}

		listCopy[amount] = data;	//insert data in last position

		delete[] arrayList;
		arrayList = listCopy;

		amount++;		//increase size of array
	}
}

void ArrayList::pushBack(int data) {
	int increasedAmount = amount + 1;
	int * listCopy = new int[increasedAmount];
	if (listCopy) {

		for (int i = 0; i < increasedAmount; i++) {
			listCopy[i + 1] = arrayList[i];
		}

		listCopy[0] = data;	// add element as first

		delete[] arrayList;
		arrayList = listCopy;

		amount++;
	}
}

void ArrayList::pushAtPosition(int data, int position) {
	if (position >= amount)
		pushFront(data);
	else if (position <= 0)
		pushBack(data);
	else {
		int increasedAmount = amount + 1;
		int * listCopy = new int[increasedAmount];
		if (listCopy) {

			for (int i = 0; i < position; i++) {
				listCopy[i] = arrayList[i];		//copy all first data in array
			}

			listCopy[position] = data;	//insert new data in specified position

			for (int i = position; i < increasedAmount; i++) {
				listCopy[i + 1] = arrayList[i];		// copy rest of data
			}

			delete[] arrayList;
			arrayList = listCopy;

			amount++;
		}
	}
}

void ArrayList::popFront() {
	if (amount > 0) {
		int decreasedAmount = amount - 1;
		int * listCopy = new int[decreasedAmount];
		if (listCopy) {

			for (int i = 0; i < decreasedAmount; i++) {
				listCopy[i] = arrayList[i];	//copy all elements without the last one
			}

			delete[] arrayList;
			arrayList = listCopy;

			amount--;
		}
	}
}

void ArrayList::popBack() {
	if (amount > 0) {
		int decreasedAmount = amount - 1;
		int * listCopy = new int[decreasedAmount];
		if (listCopy) {

			for (int i = 0; i < decreasedAmount; i++) {
				listCopy[i] = arrayList[i + 1];	//copy all elements except first one
			}

			delete[] arrayList;
			arrayList = listCopy;

			amount--;
		}
	}
}

void ArrayList::popAtPosition(int position) {
	if (amount > 0 && position < amount) {
		int decreasedAmount = amount - 1;
		int * listCopy = new int[decreasedAmount];
		if (listCopy) {

			for (int i = 0; i < position; i++) {
				listCopy[i] = arrayList[i];
			}

			for (int i = position; i < decreasedAmount; i++) {
				listCopy[i] = arrayList[i + 1];
			}

			delete[] arrayList;
			arrayList = listCopy;

			amount--;
		}
	}
}

bool ArrayList::isEmpty() {		//if ammount == 0 return true
	if (amount == 0)
		return true;
	else
		return false;
}

int ArrayList::size() {
	return amount;
}

int ArrayList::at(int index) {	//get data in specified indexed position
	if (index >= amount || index < 0)
		return -1;
	return arrayList[index];
}

bool ArrayList::contains(int data) {	//linary check if there is searched data
	for (int i = 0; i < amount; i++)
		if (arrayList[i] == data)
			return true;
	return false;
}

void ArrayList::clear() {
	amount = 0;
	delete[] arrayList;
	arrayList = new int[0];

}
