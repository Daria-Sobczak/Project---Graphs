#include "pch.h"
#include "WeightedMatrixGraph.h"
#include <random>
#include <fstream>

Vector<WeightedEdge> WeightedMatrixGraph::get_outgoing_edges_from(int vertex_number) {
	Vector<WeightedEdge> edges; // wektor z krawedziami

	for (int i = 0; i < number_of_vertices; i++) {  // patrzymy na elementy macierzy
		if (matrix[vertex_number][i].to != -1) {    // i jesli jakas krawedz tam jest to
			edges.push_back(matrix[vertex_number][i]);  // dodajemy ja do wektora
		}
	}

	return edges;   // i zwraca wynik
}

void WeightedMatrixGraph::generate_random_instance_with_approximate_density(int expected_number_of_vertices, double approximate_density) {
	int max_number_of_directed_edges = (expected_number_of_vertices*(expected_number_of_vertices-1)) / 2;
	int expected_numer_of_edges = (max_number_of_directed_edges)* approximate_density / 100; // ile krawedzi chcemy dodac
	generate_random_instance(expected_number_of_vertices, expected_numer_of_edges);
}

void WeightedMatrixGraph::generate_random_instance(int expected_number_of_vertices, int expected_number_of_edges) {
	number_of_vertices = expected_number_of_vertices; // ustaw liczbe wierzcholkow

	for (int i = 0; i < number_of_vertices; i++) {
		Vector<WeightedEdge> row(number_of_vertices);   // wektor n-elementowy, wypelniony krawedziami z -1
		matrix.push_back(row);  // dorzucamy rzad do macierzy
	}

	while (number_of_edges < expected_number_of_edges) { // dopoki nie masz wystarczajaco duzo krawedzi
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<uint32_t> vertex_distribution(0, number_of_vertices - 1);

		int from = vertex_distribution(rng);    // losowy wierzcholek
		int to = vertex_distribution(rng); // kolejny

		std::uniform_int_distribution<uint32_t> weight_distribution(1, 10);  // wagi z przedzialu [1,10]
		int cost = weight_distribution(rng);    // losowa waga

		if (matrix[from][to].to == -1) {  // jesli takiej krawedzi jeszcze nie ma
			matrix[from][to] = WeightedEdge(from, to, cost);  // to dodaj
			matrix[to][from] = WeightedEdge(to, from, cost);  // to dodaj
			number_of_edges++;  // i zwieksz liczbe krawedzi o 1

		}
	}
}

void WeightedMatrixGraph::load_graph_from_file(string filename) {
	ifstream file_reader;
	file_reader.open(filename);

	int expected_number_of_vertices, expected_number_of_edges, start_vertex;
	file_reader >> expected_number_of_vertices >> expected_number_of_edges >> start_vertex;

	number_of_vertices = expected_number_of_vertices; // ustaw liczbe wierzcholkow

	for (int i = 0; i < number_of_vertices; i++) {
		Vector<WeightedEdge> row(number_of_vertices);   // caly rzad: wektor n-elementowy, wypelniony krawedziami z -1
		matrix.push_back(row);  // dorzucamy rzad do macierzy
	} // czyli dostaje macierz nxn wypelniona -1

	for (int i = 0; i < expected_number_of_edges; i++) {
		int from, to, weight;
		file_reader >> from >> to >> weight;    // wczytaj krawedz
		matrix[from][to] = WeightedEdge(from, to, weight);    // dopisz do macierzy
		matrix[to][from] = WeightedEdge(to, from, weight);    // dopisz do macierzy
		number_of_edges++;
	}

	file_reader.close();

}

void  WeightedMatrixGraph::print() {
	for (int i = 0; i < number_of_vertices; i++) {
		for (int j = 0; j < number_of_vertices; j++) {
			if (matrix[i][j].to == -1) cout << "-" << "\t";
			else cout << matrix[i][j].cost << "\t";
		}
		cout << endl;
	}
}

WeightedMatrixGraph::WeightedMatrixGraph() {
	number_of_edges = 0;
	number_of_vertices = 0;
}

Vector<WeightedEdge> WeightedMatrixGraph::get_all_edges() {
	Vector<WeightedEdge> edges;

	for (int i = 0; i < number_of_vertices; i++) {
		for (int j = 0; j < number_of_vertices; j++) {
			if (matrix[i][j].to != -1) edges.push_back(matrix[i][j]);
		}
	}

	return edges;
}