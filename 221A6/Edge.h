/*
	Edge.h
	Matt Gaikema
	CSCE 221: 504
*/

#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <list>

namespace matt {

//------------------------------------------------------------------------------

/**
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
	Edge(const Edge& edge);
	~Edge();

	void reverse();

	void operator=(const Edge& edge);

	friend std::ostream& operator<<(std::ostream& os, Edge& edge);
	friend bool contains(std::list<Edge> vector, Edge end);
	friend bool contains(std::list<Edge> vector, int end);
	friend bool operator==(Edge lhs, Edge rhs);
	friend class Vertex;
	friend class Graph;
};

//------------------------------------------------------------------------------

} // End matt namespace

#endif // EDGE_H