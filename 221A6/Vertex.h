/*
	Vertex.h
	Matt Gaikema
	CSCE 221: 504
*/

#ifndef VERTEX_H
#define VERTEX_H

#include <stdio.h>
#include <list>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "Edge.h"

namespace matt {

//------------------------------------------------------------------------------

/*
	A Vertex has a list of edges that connect to it, 
	and a label.
*/
class Vertex {

	void print_edges(std::ostream& os = std::cout);
	
	// Label of this vertex.
	int label;
	// Linked list to manage edges.
	std::list<Edge> edge_list;

public:
	Vertex(int l);
	~Vertex();

	// Connect this vertex to a specific vertex.
	void connect_to(int end);
	// Fill the edge_list from a string.
	void parse_list(std::string str);

	friend class Edge;
	friend class Graph;
};

//------------------------------------------------------------------------------

} // End matt namespace

#endif // VERTEX_H