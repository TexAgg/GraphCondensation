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
#include "Edge.h"

namespace matt {

//------------------------------------------------------------------------------

class Vertex {

public:
	Vertex(int l);
	~Vertex();

	// Connect this vertex to a specific vertex
	void connect_to(int end);

private:
	// Label of this vertex
	int label;
	// Linked list to manage edges
	std::list<Edge> edge_list;

	friend class Edge;
	friend class Graph;
};

//------------------------------------------------------------------------------

} // End matt namespace

#endif // VERTEX_H