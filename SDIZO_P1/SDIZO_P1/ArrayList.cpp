#include "ArrayList.h"

ArrayList::ArrayList() {
	amount = 0;
	arrayList = new int[0];
}

ArrayList::~ArrayList()
{
	delete[] arrayList;
}

int ArrayList::front(){
	if (amount == 0)
		return -1;
	return arrayList[amount - 1];
}

int ArrayList::back() {
	if (amount == 0)
		return -1;
	return arrayList[0];
}

void ArrayList::pushFront(int data) {
	int increasedAmount = amount + 1;
	int * listCopy = new int[increasedAmount];
	if (listCopy) {	// Jesli zostala przydzielona nowa pamiec, to rozpocznij kopiowanie

		for (int i = 0; i < increasedAmount; i++) {
			listCopy[i] = arrayList[i];
		}

		listCopy[amount] = data;

		delete[] arrayList;
		arrayList = listCopy;

		amount++;
	}
}

void ArrayList::pushBack(int data) {
	int increasedAmount = amount + 1;
	int * listCopy = new int[increasedAmount];
	if (listCopy) {	// Jesli zostala przydzielona nowa pamiec, to rozpocznij kopiowanie

		for (int i = 0; i < increasedAmount; i++) {
			listCopy[i + 1] = arrayList[i];
		}

		listCopy[0] = data;

		delete[] arrayList;
		arrayList = listCopy;

		amount++;
	}
}

void ArrayList::pushAtPosition(int data, int position) {
	if (position >= amount)
		pushFront(data);
	else {
		int increasedAmount = amount + 1;
		int * listCopy = new int[increasedAmount];
		if (listCopy) {	// Jesli zostala przydzielona nowa pamiec, to rozpocznij kopiowanie

			for (int i = 0; i < position; i++) {
				listCopy[i] = arrayList[i];
			}

			listCopy[position] = data;

			for (int i = position; i < increasedAmount; i++) {
				listCopy[i + 1] = arrayList[i];
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
		if (listCopy) {	// Jesli zostala przydzielona nowa pamiec, to rozpocznij kopiowanie

			for (int i = 0; i < decreasedAmount; i++) {
				listCopy[i] = arrayList[i];
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
		if (listCopy) {	// Jesli zostala przydzielona nowa pamiec, to rozpocznij kopiowanie

			for (int i = 0; i < decreasedAmount; i++) {
				listCopy[i] = arrayList[i + 1];
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
		if (listCopy) {	// Jesli zostala przydzielona nowa pamiec, to rozpocznij kopiowanie

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

bool ArrayList::isEmpty() {
	if (amount == 0)
		return true;
	else
		return false;
}

int ArrayList::size() {
	return amount;
}

int ArrayList::at(int index) {
	if (index >= amount)
		return -1;
	return arrayList[index];
}

bool ArrayList::contains(int data) {
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
