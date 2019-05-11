#pragma once
#ifndef KRUSKALMSTSOLVER_H
#define KRUSKALMSTSOLVER_H

#include "MSTSolver.h"
#include <iostream>
using namespace std;

class KruskalMSTSolver : public MSTSolver {
public:
	MSTStatistics findMST(WeightedDirectedGraph &graph) override;
};


#endif 

