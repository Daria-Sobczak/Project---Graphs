#include "pch.h"
#include "KruskalMSTSolver.h"


#include "UnionFind.h"
#include <chrono>
#include "Vector.h"

// ALGORYTM KRUSKALA
MSTStatistics KruskalMSTSolver::findMST(WeightedDirectedGraph &graph) {
	auto start = chrono::steady_clock::now();   // uruchamia zegar
	int MST_cost = 0;   // koszt mst
	Vector<WeightedEdge> MST_edges; // krawedzie wziete do MST

	UnionFind unionfind(graph.get_number_of_vertices()); // tworzymy strukture union-find o okreslonym przez liczbe wierzcholkow rozmiarze
	Vector<WeightedEdge> edges = graph.get_all_edges(); // pobieramy wszystkie krawedzie
	
	edges.sort();


	for (int i = 0; i < edges.size(); i++) { // dla kazdej krawedzi
		if (unionfind.union_groups(edges[i].from, edges[i].to)) {  // jezeli jej konce nie sa w jednej grupie
			unionfind.union_groups(edges[i].from, edges[i].to); // to je zlacz (i wez ta krawedz do wyniku)
			MST_cost += edges[i].cost;  // aktualizuje koszt mst
			MST_edges.push_back(edges[i]);  // aktualizuje krawedzie w MST
		}
	}
	
	auto end = chrono::steady_clock::now(); // zatrzymuje zegar
	int running_time_in_microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count(); // czas w mikrosekundach potrzebny na rozw problemu
	//std::chrono::duration<double> diff = end - start;
	//double running_time_in_microseconds = diff.count();
	return MSTStatistics(running_time_in_microseconds, MST_cost, MST_edges);
}