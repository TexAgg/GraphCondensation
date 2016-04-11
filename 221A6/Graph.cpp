/*
	Graph.cpp
	Matt Gaikema
	CSCE 221: 504
*/

#include "Graph.h"

namespace matt {

Graph::Graph() {

}

Graph::Graph(int size) {

}


Graph::~Graph() {

}

void Graph::build_graph() {

}

void Graph::display_graph(std::ostream& os) {

}

/**
	The input operator for a Graph,
	intended to read data from a file.
	Data must be formatted such that
	the file contains just one graph,
	with the edge lists on each line, 
	and a -1 indicating the end of
	an edge list.
*/
std::istream& operator>>(std::istream& is, Graph graph) {
	
	// Do stuff
	
	return is;
}

} // End matt namespace