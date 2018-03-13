#include "Heap.h"
#include <iostream>

Heap::Heap() {
	amount = 0;
	arrayList = new int[0];
}

void Heap::push(int data) {
	int increasedAmount = amount + 1;
	int * listCopy = new int[increasedAmount];
	if (listCopy) {

		for (int i = 0; i < increasedAmount; i++) {
			listCopy[i] = arrayList[i];
		}

		listCopy[amount] = data;

		delete[] arrayList;
		arrayList = listCopy;

		if(amount == 0)
			arrayList[0] = data;
		else {
			int index = amount;
			fixToUp(data, index);

		}

		amount++;

	}
}


void Heap::pop() {
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

		if (amount > 0) // Dla listy ktora nie jest pusta
			fixToDown(getRoot(), 0);
	}
}

void Heap::fixToUp(int data, int index) {
	//Nast�puje sprawdzenie rodzica
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
	while (leftChildIndex < amount){ // Lewy jeszcze mo�e by�, kiedy prawy wyjdzie poza zakres tablicy
		if (arrayList[leftChildIndex] > data){
			int arr = arrayList[leftChildIndex];
			int tmp = data;	// Jesli jest mniejszy, to nastepuje zamienienie go miejscem z elementem z aktualnej pozycji
			arrayList[index] = arrayList[leftChildIndex];
			arrayList[leftChildIndex] = tmp;

			index = leftChildIndex;	// Przypisanie nowego indeksu (w tym miejscu element ma zmieniony wierzcholek)
		}
		else if (arrayList[rightChildIndex] > data) {
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

		leftChildIndex = getLeftChildIndex(index);
		rightChildIndex = getRightChildIndex(index);
	}
}

/*void Heap::fixToDown(int data, int index) {
	//Sprawdzenie Lewego dziecka, a nastepnie prawego
	int leftChildIndex = getLeftChildIndex(index);

	while (leftChildIndex < amount) { // zamienienie miejscami i ponowne sprawdzenie z danego indeksu
		if (arrayList[leftChildIndex] > data) {
			int arr = arrayList[leftChildIndex];
			int tmp = data;	// Jesli jest mniejszy, to nastepuje zamienienie go miejscem z elementem z aktualnej pozycji
			arrayList[index] = arrayList[leftChildIndex];
			arrayList[leftChildIndex] = tmp;

			index = leftChildIndex;	// Przypisanie nowego indeksu (w tym miejscu element ma zmieniony wierzcholek)
			//fixToDown(data, index);	// ponowne wywolanie funkcji w celu sprawdzenia czy lewe dziecko elementu nie jest przypadkiemn mniejsze
			leftChildIndex = getLeftChildIndex(index);
		}
		else {
			break;
		}
	}
	index = leftChildIndex;
	// Prawy dzieciak
	int rightChildIndex = getRightChildIndex(index);

	while (arrayList[rightChildIndex] > data) { // zamienienie miejscami i ponowne sprawdzenie z danego indeksu
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
}*/

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

bool Heap::contains(int data) {
	//Zaczynamy od korzenia i schodzimy w d�. Podobnie jak przy usuwaniu

	return true;
}