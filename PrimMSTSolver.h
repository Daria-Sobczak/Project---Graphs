#pragma once
#ifndef PRIMMSTSOLVER_H
#define PRIMMSTSOLVER_H


#include <iostream>
#include "MSTSolver.h"
using namespace std;

class PrimMSTSolver : public MSTSolver {
public:
	MSTStatistics findMST(WeightedDirectedGraph &graph) override;
};


#endif

