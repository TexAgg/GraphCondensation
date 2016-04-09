/*
	Graph.h
	Matt Gaikema
	CSCE 221: 504
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <vector>
#include "Vertex.h"

namespace matt {

//------------------------------------------------------------------------------

class Graph {
public:
	Graph(int size);
	~Graph();

	void build_graph();

private:
	std::vector<Vertex> vertices;
};

//------------------------------------------------------------------------------

} // End matt namespace

#endif // GRAPH_H