#pragma once
#ifndef WEIGHTEDDIRECTEDGRAPH_H
#define WEIGHTEDDIRECTEDGRAPH_H

#include "Vector.h"
#include "WeightedEdge.h"
#include <string>

using namespace std;

// Abstrakcyjna (tj. wirtualna) klasa reprezentujaca wazony graf skierowany
class WeightedDirectedGraph {
protected:
	int number_of_vertices; // liczba wierzcholkow grafu
	int number_of_edges;    // liczba krawedzi w grafie

public:
	virtual Vector<WeightedEdge> get_outgoing_edges_from(int vertex_number) = 0;    // zwraca wektor krawedzi wychodzacych z danego wierzcholka
	virtual Vector<WeightedEdge> get_all_edges() = 0;    // zwraca wektor krawedzi z calego grafu
	virtual void generate_random_instance_with_approximate_density(int expected_number_of_vertices, double approximate_density) = 0; // losowy graf o zadanej liczbie wierzcholkow i zadanej gestosci
	virtual void generate_random_instance(int expected_number_of_vertices, int expected_number_of_edges) = 0; // losowy graf o zadanej liczbie wierzcholkow i krawedzi
	virtual void load_graph_from_file(string filename) = 0; // wczytywanie grafu z pliku o podanej nazwie
	virtual void print() = 0;   // wypisywanie grafu
	int get_number_of_edges();
	int get_number_of_vertices();
};


#endif

