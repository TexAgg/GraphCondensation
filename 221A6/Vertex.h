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

/**
	The Color represents the state of the Vertex.
	White -> unvisited
	Grey -> visited once
	Black -> visited twice
*/
enum Color { WHITE, GREY, BLACK};

/**
	The Time_Stamp is used in depth-first search.
*/
struct Time_Stamp {
	int start = -1;
	int stop = -1;
	Color state = Color::WHITE;
};

//------------------------------------------------------------------------------

/**
	A Vertex has a list of edges that connect to it, 
	and a label.
*/
class Vertex {

	void print_edges(std::ostream& os = std::cout);
	
	// Label of this vertex.
	int label;
	// Linked list to manage edges.
	std::list<Edge> edge_list;
	Time_Stamp time_stamp;

public:
	Vertex(int l);
	Vertex();
	~Vertex();

	// Assignment operator
	void operator=(const Vertex& vertex);
	// Connect this vertex to a specific vertex.
	void connect_to(int end);
	// Fill the edge_list from a string.
	void parse_list(std::string str);

	friend bool operator<(const Vertex& lhs, const Vertex& rhs);
	friend class Edge;
	friend class Graph;
};

//------------------------------------------------------------------------------

} // End matt namespace

#endif // VERTEX_H