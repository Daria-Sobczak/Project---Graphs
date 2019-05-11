#include "pch.h"
#include "WeightedAdjacencyListGraph.h"
#include <random>
#include <fstream>


Vector<WeightedEdge> WeightedAdjacencyListGraph::get_outgoing_edges_from(int vertex_number) {
	return adjacency_list[vertex_number];
}

void WeightedAdjacencyListGraph::generate_random_instance_with_approximate_density(int expected_number_of_vertices, double approximate_density) {
	int max_number_of_directed_edges = (expected_number_of_vertices*(expected_number_of_vertices-1)) / 2;
	int expected_numer_of_edges = (max_number_of_directed_edges)* approximate_density / 100; // ile krawedzi chcemy dodac
	generate_random_instance(expected_number_of_vertices, expected_numer_of_edges);
}

void WeightedAdjacencyListGraph::generate_random_instance(int expected_number_of_vertices, int expected_number_of_edges) {
	number_of_vertices = expected_number_of_vertices; // ustaw liczbe wierzcholkow
	adjacency_list.resize(number_of_vertices);  // rozszerz liste sasiedztwa do podanej liczby wierzcholkow

	while (number_of_edges < expected_number_of_edges) { // dopoki nie masz wystarczajaco duzo krawedzi
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<uint32_t> vertex_distribution(0, number_of_vertices - 1);

		int from = vertex_distribution(rng);    // losowy wierzcholek
		int to = vertex_distribution(rng); // kolejny

		std::uniform_int_distribution<uint32_t> weight_distribution(1, 10);  // wagi z przedzialu [1,10]
		int cost = weight_distribution(rng);    // losowa waga

		bool contains = false;  // sprawdzamy czy graf nie ma juz takiej krawedzi

		for (int j = 0; j < adjacency_list[from].size(); j++) {
			if (adjacency_list[from][j].to == to) contains = true;   // porownujemy to, jesli znalezlismy takie samo to zmieniamy contains na false
		}

		if (!contains) { // jesli nie zawiera to dodajemy krawedz
			adjacency_list[from].push_back(WeightedEdge(from, to, cost));
			adjacency_list[to].push_back(WeightedEdge(to, from, cost));
			number_of_edges++;  // i zwiekszamy liczbe krawedzi o 1
		}
	}
}

void WeightedAdjacencyListGraph::load_graph_from_file(string filename) {
	ifstream file_reader;
	file_reader.open(filename);

	int expected_number_of_vertices, expected_number_of_edges, start_vertex;
	file_reader >> expected_number_of_vertices >> expected_number_of_edges >> start_vertex;
	number_of_vertices = expected_number_of_vertices; // ustaw liczbe wierzcholkow
	adjacency_list.resize(number_of_vertices);  // rozszerz liste sasiedztwa do podanej liczby wierzcholkow

	for (int i = 0; i < expected_number_of_edges; i++) {
		int from, to, weight;
		file_reader >> from >> to >> weight;    // wczytaj krawedz
		adjacency_list[from].push_back(WeightedEdge(from, to, weight));    // dopisz do listy
		adjacency_list[to].push_back(WeightedEdge(to, from, weight));    // dopisz do listy
		number_of_edges++;
	}

	file_reader.close();
}

void WeightedAdjacencyListGraph::print() {
	for (int i = 0; i < number_of_vertices; i++) {
		cout << i << ": ";  // nr wierzcholka

		if (adjacency_list[i].empty()) cout << "empty";  // jak nie ma krawedzi to wypisz empty
		else {  // a tu wypisuj krawedzie
			cout << "[";
			for (int j = 0; j < adjacency_list[i].size(); j++) {
				cout << "(" << adjacency_list[i][j].to << ", " << adjacency_list[i][j].cost << ")";
				if (j != adjacency_list[i].size() - 1) cout << ", ";
			}
			cout << "]";
		}

		cout << endl;
	}
}

Vector<WeightedEdge> WeightedAdjacencyListGraph::get_all_edges() {
	Vector<WeightedEdge> edges;

	for (int i = 0; i < number_of_vertices; i++) {
		for (int j = 0; j < adjacency_list[i].size(); j++) {
			edges.push_back(adjacency_list[i][j]);
		}
	}

	return edges;
}

WeightedAdjacencyListGraph::WeightedAdjacencyListGraph() {
	number_of_edges = 0;
	number_of_vertices = 0;
}
