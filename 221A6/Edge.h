/*
	Edge.h
	Matt Gaikema
	CSCE 221: 504
*/

#ifndef EDGE_H
#define EDGE_H

#include <iostream>

namespace matt {

//------------------------------------------------------------------------------

/*
	An Edge is a connection between two Vertices.
	Since this graph is a directed graph,
	the Edges have direction.
*/
class Edge {

	// Start vertex's label
	int start;
	// End vertex's label
	int end;
	// Weight of the edge
	int weight;

public:
	Edge(int start, int end, int weight = 0);
	~Edge();

	friend std::ostream& operator<<(std::ostream& os, Edge& edge);

	friend class Vertex;
	friend class Graph;
};

//------------------------------------------------------------------------------

} // End matt namespace

#endif // EDGE_H