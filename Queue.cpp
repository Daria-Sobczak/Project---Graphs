#include "pch.h"
#include "Queue.h"


int Queue::root() {
	return 1;
}

int Queue::last() {
	return _size;
}

int Queue::left_child(int num) {
	return  2 * num;
}

int Queue::right_child(int num) {
	return 2 * num + 1;
}

int Queue::parent(int num) {
	return num / 2;
}

Pair Queue::value(int index) {
	return heap[index];
}

Queue::Queue() {
	_max_size = 10;
	heap = new Pair[_max_size];  // 10-elementowa tablica
	_size = 0;   // na poczatku tablica ma 0 elementow
}

void Queue::set_value(int index, Pair value) {
	heap[index] = value;
}

int Queue::size() {
	return _size;
}

void Queue::dequeue() {
	if (_size != 0) {
		set_value(root(), value(last()));   // podmien wartosci korzenia z ostatnim
		_size--; // zmiejsz rozmiar
		move_down_and_repair(root());  // przesuwaj od korzenia w dol i poprawiaj wartosci
	}
}

void Queue::enqueue(Pair value) {
	if (size() < _max_size - 1) {
		heap[size() + 1] = value;
		_size++;
	}
	else {
		_max_size = 2 * _max_size + 2;
		Pair *new_heap = new Pair[_max_size];

		for (int i = 1; i <= _size; i++) {    // przepisz nowe elementy z heap do new_heap
			new_heap[i] = heap[i];
		}

		_size++; // zwieksz liczbe elementow o 1
		new_heap[_size] = value; // i ustaw nowy element na value
		delete[] heap;
		heap = new_heap;    // podmien kopce
	}

	// teraz bedziemy szli od elementu w gore i poprawiali porzadek kopca

	int num = _size; // numer elementu w ktorym aktualnie jestesmy
	repair_heap_from(num); // przywroc wlasnosc kopca
}

void Queue::move_down_and_repair(int num) {
	int smallest = num; // liczymy czy porzadek jest zaburzony i szukamy najmniejszego elementu

	// jesli lewe dziecko ma miejsza wartosc to ustaw na aktualnie najmniejszy element
	if (left_child(num) <= size() && value(left_child(num)) < value(smallest))
		smallest = left_child(num);

	// jesli prawe dziecko ma miejsza wartosc to ustaw na aktualnie najmniejszy element
	if (right_child(num) <= size() && value(right_child(num)) < value(smallest))
		smallest = right_child(num);

	// jesli najmniejszy element nie jest aktualnym elementem
	if (smallest != num) {
		Pair temp = value(smallest);   // do temp wrzucamy wartosc smallest
		set_value(smallest, value(num));  // wartosc aktualnego elemenetu wrzucamy do smallest
		set_value(num, temp);    // wartosc aktualnego elementu ustawiamy na temp

		move_down_and_repair(smallest);    // wywolaj sie rekurencyjnie
	}
}

void Queue::repair_heap_from(int num) {
	while (num != root() && value(parent(num)) > value(num)) { // jesli wartosc ojca jest wieksza niz nasza obecna
		// to zamien je miejscami
		Pair temp = value(parent(num));   // do temp wrzucamy wartosc ojca
		set_value(parent(num), value(num));  // wartosc syna wrzucamy do ojca
		set_value(num, temp);    // wartosc syna ustawiamy na temp
		num = parent(num);  // przejdz do ojca
	}
}

Queue::~Queue() {
	delete[] heap;
}

Pair Queue::min() {
	return value(root());
}
