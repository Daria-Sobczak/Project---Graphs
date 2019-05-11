#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <utility>
#include <functional>
#include "Pair.h"

class Queue {
private:
	Pair *heap; // tablica w ktorej trzymamy kopiec (dla uproszczenia bedziemy zakladac ze numerujemy ja od 1, czyli zawsze bedzie miala o 1 element wiecej)
	int _size;  // rozmiar kopca
	int _max_size; // maksymalny obecnie dostepny rozmiar

	// numeracja elementow w drzewie

	int root(); // numer korzenia kopca
	int last(); // numer ostatniego elementu w kopcu
	int left_child(int num);    // dla danego wierzcholka o numerze num podajemy numer jego lewego dziecka
	int right_child(int num);    // dla danego wierzcholka o numerze num podajemy numer jego prawego dziecka
	int parent(int num);    // dla danego wierzcholka o numerze num podajemy numer jego ojca

	Pair value(int index); // pobiera wartosc elementu o danym indeksie

	// ustawia element w tablicy na zadana wartosc
	// (prywatne, bo uzytkownik nie powinien moc tego uzywac -> bo nie zachowuje porzadku kopca)
	void set_value(int index, Pair value);

	void move_down_and_repair(int num); // przesuwanie elementu na dol tak by przywracac wlasnosc kopca
	void repair_heap_from(int num); // przywraca porzadek kopca od zadanej pozycji

public:
	Queue();    // konstruktor
	int size(); // rozmiar kopca
	void dequeue();  // usun najmniejszy element
	void enqueue(Pair value);  // dodawanie nowego elementu
	Pair min();
	~Queue();

};


#endif

