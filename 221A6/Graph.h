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

	std::vector<Vertex> vertices;
};

//------------------------------------------------------------------------------

} // End matt namespace

#endif // GRAPH_H