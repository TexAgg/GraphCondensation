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

/*
	The Graph class is a collection of Vertices
	with functions to access them.
*/
class Graph {

	std::vector<Vertex> vertices;

public:
	Graph();
	Graph(int size);
	~Graph();

	void build_graph();
	void display_graph();

	friend std::istream& operator>>(std::istream is, Graph graph);
};

//------------------------------------------------------------------------------

} // End matt namespace

#endif // GRAPH_H