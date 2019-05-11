// Project3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <chrono>
#include <queue>
#include "UnionFind.h"
#include "WeightedMatrixGraph.h"
#include "WeightedAdjacencyListGraph.h"
#include "KruskalMSTSolver.h"
#include "PrimMSTSolver.h"
#include "Queue.h"

using namespace std;

int main() {
	    
	    WeightedMatrixGraph graph;
	    graph.load_graph_from_file("graphV10Dens0.5.txt");
	    graph.print();
	
	    KruskalMSTSolver solver;
	    solver.findMST(graph).print();
	
	    PrimMSTSolver solver2;
	    solver2.findMST(graph).print();

		cout << endl;

		WeightedAdjacencyListGraph graph_l;
		graph_l.load_graph_from_file("graphV10Dens0.5.txt");
		graph_l.print();
		
	/*
	//int rozmiary[3] = { 10, 50, 100 };//, 500, 1000 };
	int rozmiary[1] = { 1000 };
	int procenty[4] = { 25, 50, 75, 100 };
	int liczba_powtorzen = 100;

	cout << "r\tp\tmacierz_kruskal\tmacierz_prim\tlista_kruskal\tlista_prim" << endl;

	ofstream record("Wyniki1000.txt");
	record << "r\tp\tmacierz_kruskal\tmacierz_prim\tlista_kruskal\tlista_prim" << "\n";
	//record << "10\t50\t";
	
	for (int r = 0; r < 1; r++) {
		for (int p = 0; p < 4; p++) {

			int czas_prim_macierz = 0;
			int czas_kruskal_macierz = 0;

			for (int i = 0; i < liczba_powtorzen; i++) {
				WeightedMatrixGraph g;
				g.generate_random_instance_with_approximate_density(rozmiary[r], procenty[p]);

				KruskalMSTSolver solverK;
				czas_kruskal_macierz += solverK.findMST(g).total_running_time_in_microseconds;

				PrimMSTSolver solverP;
				czas_prim_macierz += solverP.findMST(g).total_running_time_in_microseconds;
			}

			czas_prim_macierz /= liczba_powtorzen;
			czas_kruskal_macierz /= liczba_powtorzen;
			record << rozmiary[r] << "\t" << procenty[p] << "\t" << czas_kruskal_macierz << "\t" << czas_prim_macierz << "\t";

			int czas_prim_lista_sasiedztwa = 0;
			int czas_kruskal_lista_sasiedztwa = 0;


			for (int i = 0; i < liczba_powtorzen; i++) {
				WeightedAdjacencyListGraph g;
				g.generate_random_instance_with_approximate_density(rozmiary[r], procenty[p]);

				PrimMSTSolver solverP;
				czas_prim_lista_sasiedztwa += solverP.findMST(g).total_running_time_in_microseconds;

				KruskalMSTSolver solverK;
				czas_kruskal_lista_sasiedztwa += solverK.findMST(g).total_running_time_in_microseconds;
			}

			czas_prim_lista_sasiedztwa /= liczba_powtorzen;
			czas_kruskal_lista_sasiedztwa /= liczba_powtorzen;

			cout << rozmiary[r] << "\t" << procenty[p] << "\t" << czas_kruskal_macierz << "\t" << czas_prim_macierz;
			cout << "\t" << czas_kruskal_lista_sasiedztwa << "\t" << czas_prim_lista_sasiedztwa << endl;
			record << czas_kruskal_lista_sasiedztwa << "\t" << czas_prim_lista_sasiedztwa << "\n";
		}
	}
	*/


	/*
	int czas_prim_macierz = 0;
	int czas_kruskal_macierz = 0;
	for (int i = 0; i < liczba_powtorzen; i++) {
	WeightedMatrixGraph g;
	//auto start = chrono::steady_clock::now();
	g.generate_random_instance_with_approximate_density(10, 50);
	//auto end = chrono::steady_clock::now();
	//int running_time_in_milisec = chrono::duration_cast<chrono::milliseconds>(end - start).count();

	KruskalMSTSolver solverK;
	czas_kruskal_macierz += solverK.findMST(g).total_running_time_in_microseconds;

	PrimMSTSolver solverP;
	czas_prim_macierz += solverP.findMST(g).total_running_time_in_microseconds;
	}

	czas_prim_macierz /= 100;
	czas_kruskal_macierz /= 100;
	

	int czas_prim_lista_sasiedztwa = 0;
	int czas_kruskal_lista_sasiedztwa = 0;

	for (int i = 0; i < liczba_powtorzen; i++) {
		WeightedAdjacencyListGraph g;
		g.generate_random_instance_with_approximate_density(10, 50);

		PrimMSTSolver solverP;
		czas_prim_lista_sasiedztwa += solverP.findMST(g).total_running_time_in_microseconds;

		KruskalMSTSolver solverK;
		czas_kruskal_lista_sasiedztwa += solverK.findMST(g).total_running_time_in_microseconds;
	}

	czas_prim_lista_sasiedztwa /= liczba_powtorzen;
	czas_kruskal_lista_sasiedztwa /= liczba_powtorzen;
	


	cout << czas_kruskal_macierz << "\t" << czas_prim_macierz << "\t" << czas_kruskal_lista_sasiedztwa << "\t" << czas_prim_lista_sasiedztwa << endl;
	//cout << running_time_in_milisec << endl;
	*/
	
	

	return 0;
}