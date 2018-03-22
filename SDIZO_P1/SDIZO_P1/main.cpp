#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <conio.h>

#include "DoubleLinkedList.h"
#include "ArrayList.h"
#include "Heap.h"

using namespace std;

int isProgramWorking;

//Zmienne do liczenia czasu w mikrosekundach
auto start = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::high_resolution_clock::now() - start;
long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

//zmienne do wyswietlania kopca
string cr, cl, cp;

//KOPIEC, LISTA, TABLICA
Heap heap;
DoubleLinkedList doubleLinkedList;
ArrayList arrayList;

void displayListFront(DoubleLinkedList list);
void displayListFront(ArrayList list);
void displayHeap();

void showAndChooseMainScreen();
void showArrayListMenu();
void showDoubleLinkedListMenu();
void showHeapMenu();

void fillArrayList(ArrayList *arrayList);
void fillDoubleLinkedList(DoubleLinkedList *doubleLinkedList);
void fillHeap(Heap *heap);


int main() {
	system("cls");
	cout << "Program testowy. Wpisz cokolwiek oraz powtwierdz eneterem by kontynuowac" << endl;
	int x;
	cin >> x;

	isProgramWorking = true;

	while (isProgramWorking)
	{
		showAndChooseMainScreen();
		system("PAUSE");
	}

	/*start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
		heap.push(rand() % 99);
	elapsed = std::chrono::high_resolution_clock::now() - start;

	microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

	cout << microseconds << endl;*/

	return 0;
}

/*		WYSWIETLANIE LISTY DWUKIERUNKOWEJ		*/
void displayListFront(DoubleLinkedList list) {
	for (int i = 0; i < list.size(); i++)
		cout << list.at(i) << ", ";

	cout << endl;
}

/*		WYSWIETLANIE TABLICY		*/
void displayListFront(ArrayList list) {
	for (int i = 0; i < list.size(); i++)
		cout << list.at(i) << ", ";

	cout << endl;
}

/*		WYSWIETLANIE KOPCA		*/
void displayHeap() {
	int indeks = 1;
	int i = 0;

	while (i < heap.size())
	{
		for (int j = 0; j < indeks; j++) {
			if (i < heap.size()) {
				for (int k = 0; k < 40 / (indeks+1);k++)
					cout << " ";
				cout << heap.getArray()[i];
			}
			i++;
		}
		cout << endl;
		indeks *= 2;
	}
}

void showAndChooseMainScreen() {
	int choose;
	system("cls");
	cout << "SDIZO P1 / Krzysztof Nowakowski / 235053" << endl;
	cout << "Wybierz typ struktury, ktory chcesz testowac: " << endl;
	cout << "(1) ArrayList - lista tablicowa" << endl;
	cout << "(2) DoubleLinkedList - lista dwukierunkowa" << endl;
	cout << "(3) Heap - kopiec binarny" << endl;
	cout << "(5) Zakoncz" << endl;

	cin.clear();
	cin.ignore(INT_MAX, '\n');
	cin >> choose;

	cout << "wpisano: " << choose << endl;

	switch (choose) {
	case 1:
		showArrayListMenu();
		break;
	case 2:
		showDoubleLinkedListMenu();
		break;
	case 3:
		showHeapMenu();
		break;
	case 5:
		isProgramWorking = false;
		break;
	default:
		cout << "zla liczba, wybierz ponownie." << endl;
		system("PAUSE");
		break;
	}
}

void showArrayListMenu() {
	bool showMenu = true;
	while (showMenu) {

		int choose;
		int position;
		int data;

		system("cls");
		cout << "ArrayList" << endl;
		cout << "Co chcesz zrobic?" << endl;
		cout << "(1) Wypelnij strukture danymi z pliku \"example.txt\"" << endl;
		cout << "(2) Wyswietl strukture (wyswietla jak liste, od elementu 0 w gore)" << endl;
		cout << "(3) Dodaj element na koncu (push_front)" << endl;
		cout << "(4) Dodaj element na poczatku (push_back)" << endl;
		cout << "(5) Dodaj element na wybranej pozycji (push_at)" << endl;
		cout << "(6) Usun element na koncu (pop_front)" << endl;
		cout << "(7) Usun element na poczatku (pop_back)" << endl;
		cout << "(8) Usun element na wybranej pozycji (pop_at)" << endl;
		cout << "(9) Wyswietl wielkosc (size)" << endl;
		cout << "(10) Czy zawiera dana? (contains)" << endl;
		cout << "(11) Wyczysc strukture (od razu usuwa cala tablice z pamieci)" << endl;
		cout << "(12) Zakoncz" << endl;

		cin >> choose;

		cout << "wpisano: " << choose << endl;

		switch (choose) {
		case 1:
			start = std::chrono::high_resolution_clock::now();

			fillArrayList(&arrayList);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			cout << "Uzupelniono danymi z pliku" << endl;
			system("PAUSE");
			break;
		case 2:
			cout << "Lista: " << endl;

			start = std::chrono::high_resolution_clock::now();

			displayListFront(arrayList);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 3:
			cout << "Dodaj do listy na koncu: " << endl;
			cin >> data;

			start = std::chrono::high_resolution_clock::now();

			arrayList.pushFront(data);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 4:
			cout << "Dodaj do listy na poczatku: " << endl;
			cin >> data;

			start = std::chrono::high_resolution_clock::now();

			arrayList.pushBack(data);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 5:
			cout << "Dodaj do listy na wybranej pozycji: " << endl;
			cin >> position;
			cout << "Wartosc: " << endl;
			cin >> data;

			start = std::chrono::high_resolution_clock::now();

			arrayList.pushAtPosition(data, position);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 6:
			cout << "Usunieto z konca" << endl;

			start = std::chrono::high_resolution_clock::now();

			arrayList.popFront();

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 7:
			cout << "Usunieto z poczatku" << endl;

			start = std::chrono::high_resolution_clock::now();

			arrayList.popBack();

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 8:
			cout << "Usun z wybranej pozycji: " << endl;
			cin >> position;

			start = std::chrono::high_resolution_clock::now();

			arrayList.popAtPosition(position);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 9:
			cout << "Wielkosc: " << arrayList.size() << endl;
			system("PAUSE");
			break;
		case 10: {
			cout << "Wyszukaj dana: " << endl;
			cin >> data;

			start = std::chrono::high_resolution_clock::now();

			bool contains = arrayList.contains(data);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			if (contains)
				cout << "Jest" << endl;
			else
				cout << "Brak" << endl;
			system("PAUSE");}
			break;
		case 11:
			cout << "Czyszczenie tablicy" << endl;

			start = std::chrono::high_resolution_clock::now();

			arrayList.clear();

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 12:
			showMenu = false;
			break;
		default:
			cout << "zla liczba, wybierz ponownie." << endl;
			system("PAUSE");
			break;
		}
	}
}

void showDoubleLinkedListMenu() {
	bool showMenu = true;
	while (showMenu) {

		int choose;
		int position;
		int data;

		system("cls");
		cout << "DoubleLinkedList" << endl;
		cout << "Co chcesz zrobic?" << endl;
		cout << "(1) Wypelnij strukture danymi z pliku \"example.txt\"" << endl;
		cout << "(2) Wyswietl strukture (wyswietla jak liste, od elementu 0 w gore)" << endl;
		cout << "(3) Dodaj element na koncu (push_front)" << endl;
		cout << "(4) Dodaj element na poczatku (push_back)" << endl;
		cout << "(5) Dodaj element na wybranej pozycji (push_at)" << endl;
		cout << "(6) Usun element na koncu (pop_front)" << endl;
		cout << "(7) Usun element na poczatku (pop_back)" << endl;
		cout << "(8) Usun element na wybranej pozycji (pop_at)" << endl;
		cout << "(9) Wyswietl wielkosc (size)" << endl;
		cout << "(10) Czy zawiera dana? (contains)" << endl;
		cout << "(11) Wyczysc strukture (usuwa element po elemencie, zeby byc pewnym ze zwolni cala pamiec)" << endl;
		cout << "(12) Zakoncz" << endl;

		cin >> choose;

		cout << "wpisano: " << choose << endl;

		switch (choose) {
		case 1:
			start = std::chrono::high_resolution_clock::now();

			fillDoubleLinkedList(&doubleLinkedList);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			cout << "Uzupelniono danymi z pliku" << endl;
			system("PAUSE");
			break;
		case 2:
			cout << "Lista: " << endl;

			start = std::chrono::high_resolution_clock::now();

			displayListFront(doubleLinkedList);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 3:
			cout << "Dodaj do listy na koncu: " << endl;
			cin >> data;

			start = std::chrono::high_resolution_clock::now();

			doubleLinkedList.pushFront(data);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 4:
			cout << "Dodaj do listy na poczatku: " << endl;
			cin >> data;

			start = std::chrono::high_resolution_clock::now();

			doubleLinkedList.pushBack(data);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 5:
			cout << "Dodaj do listy na wybranej pozycji: " << endl;
			cin >> position;
			cout << "Wartosc: " << endl;
			cin >> data;

			start = std::chrono::high_resolution_clock::now();

			doubleLinkedList.pushAtPosition(data, position);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 6:
			cout << "Usunieto z konca" << endl;

			start = std::chrono::high_resolution_clock::now();

			doubleLinkedList.popFront();

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 7:
			cout << "Usunieto z poczatku" << endl;

			start = std::chrono::high_resolution_clock::now();

			doubleLinkedList.popBack();

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 8:
			cout << "Usun z wybranej pozycji: " << endl;
			cin >> position;

			start = std::chrono::high_resolution_clock::now();

			doubleLinkedList.popAtPosition(position);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 9:
			cout << "Wielkosc: " << doubleLinkedList.size() << endl;
			system("PAUSE");
			break;
		case 10: {
			cout << "Wyszukaj dana: " << endl;
			cin >> data;

			start = std::chrono::high_resolution_clock::now();

			bool contains = doubleLinkedList.contains(data);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			if (contains)
				cout << "Jest" << endl;
			else
				cout << "Brak" << endl;
			system("PAUSE");}
				 break;
		case 11:
			cout << "Czyszczenie listy" << endl;

			start = std::chrono::high_resolution_clock::now();

			doubleLinkedList.clear();

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 12:
			showMenu = false;
			break;
		default:
			cout << "zla liczba, wybierz ponownie." << endl;
			system("PAUSE");
			break;
		}
	}
}

void showHeapMenu() {
	bool showMenu = true;
	while (showMenu) {

		int choose;
		int position;
		int data;

		system("cls");
		cout << "DoubleLinkedList" << endl;
		cout << "Co chcesz zrobic?" << endl;
		cout << "(1) Wypelnij strukture danymi z pliku \"example.txt\"" << endl;
		cout << "(2) Wyswietl strukture" << endl;
		cout << "(3) Dodaj element" << endl;
		cout << "(4) Usun element" << endl;
		cout << "(5) Wyswietl wielkosc (size)" << endl;
		cout << "(6) Czy zawiera dana? (contains)" << endl;
		cout << "(7) Wyczysc strukture (od razu usuwa cala tablice z pamieci)" << endl;
		cout << "(8) Zakoncz" << endl;

		cin >> choose;

		cout << "wpisano: " << choose << endl;

		switch (choose) {
		case 1:
			start = std::chrono::high_resolution_clock::now();

			fillHeap(&heap);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			cout << "Uzupelniono danymi z pliku" << endl;
			system("PAUSE");
			break;
		case 2:
			cout << "Kopiec: " << endl;

			start = std::chrono::high_resolution_clock::now();

			displayHeap();

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 3:
			cout << "Dodaj do kopca: " << endl;
			cin >> data;

			start = std::chrono::high_resolution_clock::now();

			heap.push(data);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 4:
			cout << "Usunieto z kopca" << endl;

			start = std::chrono::high_resolution_clock::now();

			heap.pop();

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 5:
			cout << "Wielkosc: " << heap.size() << endl;
			system("PAUSE");
			break;
		case 6: {
			cout << "Wyszukaj dana: " << endl;
			cin >> data;

			start = std::chrono::high_resolution_clock::now();

			bool contains = heap.contains(data);

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			if (contains)
				cout << "Jest" << endl;
			else
				cout << "Brak" << endl;
			system("PAUSE");}
				 break;
		case 7:
			cout << "Czyszczenie listy" << endl;

			start = std::chrono::high_resolution_clock::now();

			heap.clear();

			elapsed = std::chrono::high_resolution_clock::now() - start;
			microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			cout << microseconds << "us" << endl;

			system("PAUSE");
			break;
		case 8:
			showMenu = false;
			break;
		default:
			cout << "zla liczba, wybierz ponownie." << endl;
			system("PAUSE");
			break;
		}
	}
}

void fillArrayList(ArrayList *arrayList) {
	string size;
	ifstream myfile("example.txt");

	if (myfile) {
		getline(myfile, size); // Wczytanie pierwszej lini - informacja ile jest elementow.

		for (int i = 0; i < atoi(size.c_str()); i++) {
			string line;
			getline(myfile, line);

			int number = atoi(line.c_str());
			arrayList->pushFront(number);
		}

		myfile.close();
	}
	else cout << "plik sie nie wczytal\n";
}

void fillDoubleLinkedList(DoubleLinkedList *doubleLinkedList) {
	string size;
	ifstream myfile("example.txt");

	if (myfile) {
		getline(myfile, size); // Wczytanie pierwszej lini - informacja ile jest elementow.

		for (int i = 0; i < atoi(size.c_str()); i++) {
			string line;
			getline(myfile, line);

			int number = atoi(line.c_str());
			doubleLinkedList->pushFront(number);
		}

		myfile.close();
	}
	else cout << "plik sie nie wczytal\n";
}

void fillHeap(Heap *heap) {
	string size;
	ifstream myfile("example.txt");

	if (myfile) {
		getline(myfile, size); // Wczytanie pierwszej lini - informacja ile jest elementow.

		for (int i = 0; i < atoi(size.c_str()); i++) {
			string line;
			getline(myfile, line);

			int number = atoi(line.c_str());
			heap->push(number);
		}

		myfile.close();
	}
	else cout << "plik sie nie wczytal\n";
}
