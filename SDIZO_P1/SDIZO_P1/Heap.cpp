#include "Heap.h"
#include <iostream>

Heap::Heap() {
	amount = 0;
	arrayList = new int[0];
}

Heap::~Heap()
{
	delete[] arrayList;
}

void Heap::push(int data) {
	if (amount == 0) {
		arrayList = new int[1];
		arrayList[0] = data;
		amount++;
	}
	else {

		int increasedAmount = amount + 1;
		int * listCopy = new int[increasedAmount];
		if (listCopy) {

			for (int i = 0; i < amount; i++) {
				listCopy[i] = arrayList[i];
			}

			listCopy[amount] = data;

			delete[] arrayList;
			arrayList = listCopy;

			fixToUp(data, amount);

			amount++;

		}
	}
}


void Heap::pop() {
	if (amount > 0) {
		arrayList[0] = arrayList[amount - 1];

		int decreasedAmount = amount - 1;
		int * listCopy = new int[decreasedAmount];
		if (listCopy) {	// Jesli zostala przydzielona nowa pamiec, to rozpocznij kopiowanie

			for (int i = 0; i < decreasedAmount; i++) {
				listCopy[i] = arrayList[i];
			}

			delete[] arrayList;
			arrayList = listCopy;

			amount--;
			fixToDown(getRoot(), 0);

		}
	}
}

void Heap::fixToUp(int data, int index) {
	//Nastêpuje sprawdzenie rodzica
	int parentIndex = getParentIndex(index);
	if (arrayList[parentIndex] < data) {	// Sprawdzenie czy rodzic jest mniejszy niz wstawiany
		int tmp = data;	// Jesli jest mniejszy, to nastepuje zamienienie go miejscem z elementem z aktualnej pozycji
		arrayList[index] = arrayList[parentIndex];
		arrayList[parentIndex] = tmp;

		index = parentIndex;	// Przypisanie nowego indeksu (w tym miejscu element ma zmieniony wierzcholek)
		fixToUp(data, index);	// ponowne wywolanie funkcji w celu sprawdzenia czy rodzic elementu nie jest przypadkiemn mniejszy
	}
}

void Heap::fixToDown(int data, int index) {
	int leftChildIndex = getLeftChildIndex(index);
	int rightChildIndex = getRightChildIndex(index);
	while (leftChildIndex < amount){ // Lewy jeszcze mo¿e byæ, kiedy prawy wyjdzie poza zakres tablicy

		if (arrayList[leftChildIndex] > arrayList[rightChildIndex]) { // Jesli lewe dziecko jest wieksze od tego z prawej, to zamien z tym z lewej
			if (arrayList[leftChildIndex] > data) {
				int arr = arrayList[leftChildIndex];
				int tmp = data;	// Jesli jest mniejszy, to nastepuje zamienienie go miejscem z elementem z aktualnej pozycji
				arrayList[index] = arrayList[leftChildIndex];
				arrayList[leftChildIndex] = tmp;

				index = leftChildIndex;	// Przypisanie nowego indeksu (w tym miejscu element ma zmieniony wierzcholek)
			}
			else {
				break;
			}
		}
		else {
			if (arrayList[rightChildIndex] > data) {
				int arr = arrayList[rightChildIndex];
				int tmp = data;	// Jesli jest mniejszy, to nastepuje zamienienie go miejscem z elementem z aktualnej pozycji
				arrayList[index] = arrayList[rightChildIndex];
				arrayList[rightChildIndex] = tmp;

				index = rightChildIndex;	// Przypisanie nowego indeksu (w tym miejscu element ma zmieniony wierzcholek)
											//fixToDown(data, index);
			}
			else {
				break;
			}
		}

		leftChildIndex = getLeftChildIndex(index);
		rightChildIndex = getRightChildIndex(index);
	}
}

int Heap::getParentIndex(int childIndex) {
	return ((childIndex - 1) / 2);
}

int Heap::getLeftChildIndex(int parentIndex) {
	return (2 * parentIndex + 1);
}

int Heap::getRightChildIndex(int parentIndex) {
	return (2 * parentIndex + 2);
}

int Heap::getRoot() {
	return arrayList[0];
}

int Heap::size() {
	return amount;
}

int *Heap::getArray() {
	return arrayList;
}

bool Heap::containsHelper(int index, int data, bool *found) {
	if (index <= amount) {	//Check if index is lower or the same as amount XD
		if (arrayList[index] == data) {
			return true;
		}
		if (getLeftChildIndex(index) <= amount) {				//First check all left children if there is the searched object
			if (arrayList[getLeftChildIndex(index)] == data)
				*found = true;
			if (arrayList[getLeftChildIndex(index)] > data)
				containsHelper(getLeftChildIndex(index), data, found);	//If there is child please force try to find object
		}
		if (*found)			//If there is searched object return true for all recurensions
			return true;
		if (getRightChildIndex(index) < amount) {		//Do the same things for right children
			if (arrayList[getRightChildIndex(index)] == data)
				*found = true;
			if (arrayList[getRightChildIndex(index)] > data)
				containsHelper(getRightChildIndex(index), data, found);
		}
		if (*found)
			return true;
	}
	return false;
}

bool Heap::contains(int data) {
	bool found = false;		//contains helper is a recurencial method so it needs to have data for check if it fouded element in heap
	return containsHelper(0, data, &found);
}

void Heap::clear() {
	delete[] arrayList;
	arrayList = new int[0];
	amount = 0;
}