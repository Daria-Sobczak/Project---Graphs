#pragma once
#ifndef WEIGHTEDMATRIXGRAPH_H
#define WEIGHTEDMATRIXGRAPH_H
#include "WeightedDirectedGraph.h"
#include <iostream>
#include "Vector.h"
using namespace std;

// klasa opisujaca wazony skierowany graf reprezentowany macierzowo
class WeightedMatrixGraph : public WeightedDirectedGraph {
private:
	Vector< Vector<WeightedEdge> >  matrix;

public:
	WeightedMatrixGraph();
	Vector<WeightedEdge> get_outgoing_edges_from(int vertex_number) override;
	Vector<WeightedEdge> get_all_edges() override;

	void generate_random_instance_with_approximate_density(int expected_numer_of_vertices, double approximate_density) override;

	void generate_random_instance(int expected_numer_of_vertices, int expected_numer_of_edges) override;

	void load_graph_from_file(string filename) override;

	void print() override;
};


#endif

