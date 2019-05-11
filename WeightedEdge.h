#pragma once
#ifndef WEIGHTEDEDGE_H
#define WEIGHTEDEDGE_H

// klasa reprezentujaca wazona krawedz w grafie
class WeightedEdge {
public:
	int from;   // odkad
	int to;     // dokad
	int cost;   // koszt krawedzi

	WeightedEdge(int f = -1, int t = -1, int c = -1);   // konstruktor domyslny

	// operator porownywania krawedzi (porownuje po koszcie)
	bool operator<(const WeightedEdge& edge) const;
};


#endif