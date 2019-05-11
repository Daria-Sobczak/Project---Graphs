#pragma once
#ifndef MSTSOLVER_H
#define MSTSOLVER_H


#include "MSTStatistics.h"
#include "WeightedDirectedGraph.h"

class MSTSolver {
public:
	virtual MSTStatistics findMST(WeightedDirectedGraph &graph) = 0;
};


#endif
