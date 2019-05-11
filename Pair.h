#pragma once
#ifndef PAIR_H
#define PAIR_H


class Pair {
public:
	int first, second;
	Pair(int first = 0, int second = 0);

	bool operator<(const Pair& other) const;
	bool operator>(const Pair& other) const;
};


#endif

