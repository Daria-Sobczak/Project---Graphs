#include "pch.h"
#include "MSTStatistics.h"
#include <iostream>

MSTStatistics::MSTStatistics(int time, int cost, Vector<WeightedEdge> edges) {
	total_running_time_in_microseconds = time;
	cost_of_MST = cost;
	edges_from_MST = edges;
}

void MSTStatistics::print() {
	cout << "Running time in microseconds " << total_running_time_in_microseconds << endl;
	cout << "Overall cost of MST " << cost_of_MST << endl;
	cout << "Taken edges : [";

	for (int i = 0; i < edges_from_MST.size(); i++) {
		cout << "(" << edges_from_MST[i].from << "->" << edges_from_MST[i].to << ", " << edges_from_MST[i].cost << ")";
		if (i != edges_from_MST.size() - 1) cout << ", "; // jesli nie jest ostatnia krawedzia to wyswietla "," dla oddzielenia krawedzi
	}

	cout << "]" << endl;

}
