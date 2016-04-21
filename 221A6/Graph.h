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
#include <iterator>
#include <stack>
#include <map>
#include "Vertex.h"

namespace matt {

//------------------------------------------------------------------------------

/**
	The Graph class is a collection of Vertices
	with functions to access them.
*/
class Graph {

	void insert(Vertex vertex);
	void dfs_visit(Vertex& vertex, int* time, std::list<Vertex>& lst);
	void depth_first_search(int start = 0);

	std::vector<Vertex> vertices;
	std::map<Vertex, std::list<Vertex>> scc;

public:
	Graph();
	Graph(int size);
	Graph(std::string filename);
	Graph(const Graph& graph);
	Graph(Vertex vertex);
	~Graph();

	const int size();
	void build_graph();
	void display_graph(std::ostream& os = std::cout);
	Graph transpose();
	void display_dfs(int start = 0, std::ostream& os = std::cout);
	Graph get_acyclic();
	void print_scc();
};

//------------------------------------------------------------------------------

} // End matt namespace

#endif // GRAPH_H