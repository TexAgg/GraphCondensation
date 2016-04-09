#ifndef VERTEX_H
#define VERTEX_H

#include <stdio.h>
#include <list>
#include <string>
#include <vector>
#include "Edge.h"

namespace matt {

class Vertex
{
	// Label of this vertex
	int label;
	// Linked list to manage edges
	std::list<Edge> edge_list;

public:
	Vertex(int l);
	~Vertex();

	// Connect this vertex to a specific vertex
	void connect_to(int end);

	friend class Edge;
};

} // End matt namespace

#endif