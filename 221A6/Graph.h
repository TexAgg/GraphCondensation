/*
	Graph.h
	Matt Gaikema
	CSCE 221: 504
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Vertex.h"

namespace matt {

//------------------------------------------------------------------------------

/**
	The Graph class is a collection of Vertices
	with functions to access them.
*/
class Graph {

	std::vector<Vertex> vertices;

public:
	Graph();
	Graph(int size);
	Graph(std::string filename);
	Graph(const Graph& graph);
	~Graph();

	void build_graph();
	void display_graph(std::ostream& os = std::cout);
	Graph transpose();

	friend void depth_first_search(Graph graph);
};

//------------------------------------------------------------------------------

} // End matt namespace

#endif // GRAPH_H