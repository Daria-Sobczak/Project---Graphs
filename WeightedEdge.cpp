#include "pch.h"
#include "WeightedEdge.h"

WeightedEdge::WeightedEdge(int f, int t, int c) {
	from = f;
	to = t;
	cost = c;
}

bool WeightedEdge::operator<(const WeightedEdge &edge) const {
	return cost < edge.cost;
}
