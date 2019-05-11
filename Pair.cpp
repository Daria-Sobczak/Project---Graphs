#include "pch.h"
#include "Pair.h"


Pair::Pair(int first, int second) {
	this->first = first;
	this->second = second;
}

bool Pair::operator<(const Pair &p2) const {
	return (first < p2.first) || (first == p2.first && first < p2.second);

}

bool Pair::operator>(const Pair &p2) const {
	return (first > p2.first) || (first == p2.first && first > p2.second);
}
