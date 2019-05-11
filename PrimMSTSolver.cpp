#include "pch.h"
#include "PrimMSTSolver.h"

#include <chrono>
#include <queue>
#include "PrimMSTSolver.h"
#include "Queue.h"

MSTStatistics PrimMSTSolver::findMST(WeightedDirectedGraph &graph) {
	auto start = chrono::steady_clock::now();  // uruchamia zegar 

	Vector<bool> inMst(graph.get_number_of_vertices(), false); // sprawdzenie czy dany wierzcholek jest juz w MST
	Vector<int> keys(graph.get_number_of_vertices(), INT_MAX);  // ustawia klucze na nieskonczonosc
	Vector<int> parent(graph.get_number_of_vertices(), -1); // rodzica danego wierzcholka ustawiamy na -1 (nie ma go jeszcze)

	Queue queue;

	int starting_vertex = 0;  // startowy wierzcholek
	queue.enqueue(Pair(0, starting_vertex));  // wrzuca pare (0,start) do kolejki (waga, wierzcholek)
	keys[starting_vertex] = 0;  // ustawia klucz wierzcholka 0 na 0

	while (queue.size() != 0) {  // dopoki kolejka nie jest pusta
		int selected_node = queue.min().second;    // pobierz wierzcholek z kolejki
		queue.dequeue(); // usun go
		inMst[selected_node] = true; // ustaw ze jest w kolejce
		Vector<WeightedEdge> outgoing_edges = graph.get_outgoing_edges_from(selected_node); // pobierz jego liste krawedzi

		for (int i = 0; i < outgoing_edges.size(); i++) {    // dla kazdej krawedzi, wybiera ja i ...
			int neighbour = outgoing_edges[i].to;   // oblicza z czym laczy (sasiad)
			int weight = outgoing_edges[i].cost;    // i jakim kosztem

			if (!inMst[neighbour] && keys[neighbour] > weight) {  // jezeli sasiad nie jest jeszcze w MST i jego klucz jest wiekszy niz waga krawedzi
				keys[neighbour] = weight; // ustaw mu mowy klucz
				queue.enqueue(Pair(keys[neighbour], neighbour));  // wrzuc (klucz, sasiad) do kolejki
				parent[neighbour] = selected_node;    // ustaw ze selected_node poprawil wynik dla sasiada
			}
		}
	}

	Vector<WeightedEdge> MST_edges; // krawedzie wziete do MST
	int MST_cost = 0;   // koszt mst

	for (int i = 1; i < graph.get_number_of_vertices(); i++) {   // dla kazdego wierzcholka
		MST_edges.push_back(WeightedEdge(parent[i], i, keys[i])); // wybierz krawedz i dopisz do MST
		MST_cost += keys[i];    // dodaj wage tej krawedzi do lacznej wagi MST
	}

	auto end = chrono::steady_clock::now(); // zatrzymujem zegar
	int running_time_in_microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count(); // czas w mikrosekundach potrzeby na rozw problemu
	return MSTStatistics(running_time_in_microseconds, MST_cost, MST_edges); // zwroc odpowiedz

}