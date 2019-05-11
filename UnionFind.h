#pragma once
#ifndef UNIONFIND_H
#define UNIONFIND_H

#include "Vector.h"

using namespace std;

// Union-find do struktura do przechowywania zbiorow

class UnionFind {
private:
	Vector<int> representatives;

public:
	int find_representative(int elem); // zwraca reprezentanta grupy w ktorym jest podany element
	bool the_same_set(int x, int y); // zwraca true jesli x i y sa w tej samej grupie
	bool union_groups(int a, int b); // laczy grupy w ktorych jest a i b
	UnionFind(int size);     // konstruktor struktury union-find
};


#endif

