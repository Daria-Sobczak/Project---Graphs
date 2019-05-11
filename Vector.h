#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <typeinfo>
#include <algorithm>
#include "WeightedEdge.h"

template <class T>
class  Vector {
public:

	typedef T* Iterator;

	Vector();
	Vector(unsigned int size);
	Vector(unsigned int size, const T & initial); // wypelnienie calosci wartoscia intitial
	Vector(const Vector<T>& v);
	~Vector();

	unsigned int capacity() const; // zwraca pojemnosc
	unsigned int size() const; // zwraca aktualny rozmiar
	bool empty() const; // sprawdza, czy pusty
	Iterator begin(); // zwraca wskaznik na poczatek
	Iterator end(); // zwraca wskaznik na koniec
	T& front(); // zwraca pierwszy element
	T& back(); // wraca ostatni element
	void push_back(const T& value); // dodaje element na koncu
	void pop_back(); // usuwa element z konca
	void sort(); // sortuje elementy

	void reserve(unsigned int capacity);
	void resize(unsigned int size);

	T & operator[](unsigned int index); // zwraca element znajdujacy sie pod danym indeksem - przeciazenie operatora []
	Vector<T> & operator = (const Vector<T> &);
	void clear(); // usuwa wszystko
private:
	unsigned int _size; // rozmiar
	unsigned int _capacity; // pojemnosc
	unsigned int Log;
	T* buffer; // tablica wskaznikow
};

template<class T>
Vector<T>::Vector() {
	_capacity = 0;
	_size = 0;
	buffer = 0;
	Log = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> & v) {
	_size = v._size;
	Log = v.Log;
	_capacity = v._capacity;
	buffer = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		buffer[i] = v.buffer[i];
}

template<class T>
Vector<T>::Vector(unsigned int size) {
	_size = size;
	Log = ceil(log((double)size) / log(2.0)); // zaokraglenie w gore
	_capacity = 1 << Log;
	buffer = new T[_capacity];
}

template <class T>
bool Vector<T>::empty() const {
	return _size == 0;
}

template<class T>
Vector<T>::Vector(unsigned int size, const T& initial) {
	_size = size;
	Log = ceil(log((double)size) / log(2.0)); // zaokraglenie w gore
	_capacity = 1 << Log;
	buffer = new T[_capacity];
	for (unsigned int i = 0; i < size; i++)
		buffer[i] = initial;
}

template<class T>
Vector<T>& Vector<T>::operator = (const Vector<T> & v) {
	delete[] buffer;
	_size = v._size;
	Log = v.Log;
	_capacity = v._capacity;
	buffer = new T[_capacity];
	for (unsigned int i = 0; i < _size; i++)
		buffer[i] = v.buffer[i];
	return *this;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::begin() {
	return buffer;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::end() {
	return buffer + size();
}

template<class T>
T& Vector<T>::front() {
	return buffer[0];
}

template<class T>
T& Vector<T>::back() {
	return buffer[_size - 1];
}

template<class T>
void Vector<T>::push_back(const T & v) {
	if (_size >= _capacity) {
		reserve(1 << Log);
		Log++;
	}
	buffer[_size++] = v;
}

template<class T>
void Vector<T>::pop_back() {
	_size--;
}

template<class T>
void Vector<T>::reserve(unsigned int capacity) {
	T * newBuffer = new T[capacity];

	for (unsigned int i = 0; i < _size; i++)
		newBuffer[i] = buffer[i];

	_capacity = capacity;
	delete[] buffer;
	buffer = newBuffer;
}

template<class T>
unsigned int Vector<T>::size() const {
	return _size;
}

template<class T>
void Vector<T>::resize(unsigned int size) {
	Log = ceil(log((double)size) / log(2.0));
	reserve(1 << Log);
	_size = size;
}

template<class T>
T& Vector<T>::operator[](unsigned int index) {
	return buffer[index];
}

template<class T>
unsigned int Vector<T>::capacity()const {
	return _capacity;
}

template<class T>
Vector<T>::~Vector() {
	delete[] buffer;
}

template <class T>
void Vector<T>::clear() {
	_capacity = 0;
	_size = 0;
	buffer = 0;
	Log = 0;
}

template<class T>
void Vector<T>::sort() {
	if (typeid(T).name() == typeid(WeightedEdge).name()) {
		std::sort(buffer, buffer + _size, std::less<WeightedEdge>());
	}
	else {
		std::sort(buffer, buffer + _size);
	}

}

#endif

