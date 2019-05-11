#pragma once
#ifndef WEIGHTEDADJACENCYLISTGRAPH_H
#define WEIGHTEDADJACENCYLISTGRAPH_H

#include "WeightedDirectedGraph.h"
#include "Vector.h"
#include <iostream>
using namespace std;

class WeightedAdjacencyListGraph : public WeightedDirectedGraph {
private:
	Vector< Vector<WeightedEdge> > adjacency_list;
public:
	Vector<WeightedEdge> get_outgoing_edges_from(int vertex_number) override;
	Vector<WeightedEdge> get_all_edges() override;
	void generate_random_instance_with_approximate_density(int expected_number_of_vertices, double approximate_density) override;
	void generate_random_instance(int expected_number_of_vertices, int expected_number_of_edges) override;
	void load_graph_from_file(string filename) override;
	void print() override;
	WeightedAdjacencyListGraph();

};


#endif

