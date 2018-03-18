#include "Heap.h"
#include <iostream>

Heap::Heap() {
	amount = 0;
	arrayList = new int[0];
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
	if (index <= amount) {
		if (arrayList[index] == data) {
			return true;
		}
		int arr = arrayList[getLeftChildIndex(index)];
		int lf = getLeftChildIndex(index);
		if (getLeftChildIndex(index) <= amount) {
			if (arrayList[getLeftChildIndex(index)] == data)
				*found = true;
			if (arrayList[getLeftChildIndex(index)] > data)
				containsHelper(getLeftChildIndex(index), data, found);
		}
		if (*found)
			return true;
		int arr2 = arrayList[getRightChildIndex(index)];
		int rf = getRightChildIndex(index);
		if (getRightChildIndex(index) < amount) {
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
	bool found = false;
	return containsHelper(0, data, &found);
}

void Heap::clear() {
	while (amount > 0){
		pop();
	}
}