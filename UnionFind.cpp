#include "pch.h"
#include "UnionFind.h"


int UnionFind::find_representative(int elem) {
	if (representatives[elem] == elem) { // jesli elem jest reprezentantem swojej wlasnej grupy...
		return elem;    // to po prostu go zwroc
	}

	int rep = find_representative(representatives[elem]); // szukaj reprezentanta grupy rekurencyjnie
	representatives[elem] = rep;    // jak juz go znalazles to ustaw go jako reprezentanta elem, by nie szukac go potem wielokrotnie
	return rep; // i go zwroc
}

bool UnionFind::the_same_set(int x, int y) {
	return (find_representative(x) == find_representative(y));    // sa w tej samej grupie jesli reprezentanci sa tacy sami
}

bool UnionFind::union_groups(int a, int b) {
	int fa = find_representative(a); // szukaj reprezentanta zbioru zawieraj¹cego element 'a'
	int fb = find_representative(b); // szukaj reprezentanta zbioru zawieraj¹cego element 'b'

	if (fa == fb) return false; // nie trzeba nic ³¹czyæ
	else {
		representatives[fa] = fb;
		return true;
	}
}

UnionFind::UnionFind(int size) {
	representatives.resize(size);   // stworz tablice o liczbie elementow size, czyli zbiory {0}, {1}, ..., {size-1}

	for (int i = 0; i < size; i++) { // dla kazdego numeru i
		representatives[i] = i;    // ustaw ze i jest reprezentantem samego siebie
	}
}
