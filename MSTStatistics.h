#pragma once
#ifndef MSTSTATISTICS_H
#define MSTSTATISTICS_H


#include "WeightedEdge.h"
#include "Vector.h"
using namespace std;

class MSTStatistics {
public:
	int total_running_time_in_microseconds; // czas dzialania w [us]
	int cost_of_MST;    // koszt MST
	Vector<WeightedEdge> edges_from_MST;    // krawedzie wziete do MST

	MSTStatistics(int time, int cost, Vector<WeightedEdge> edges);
	void print();
};


#endif

