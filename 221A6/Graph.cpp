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

/**
	This constructor constructs a Graph from
	a file.
	@param The name of file to be read from.
*/
Graph::Graph(std::string filename) {
	try {
		std::ifstream infile;
		infile.open(filename);
		while (infile) {
			std::string str;
			std::getline(infile, str);
			std::stringstream ss(str);

			Vertex vertex((int)ss.peek());
			vertices.push_back(vertex);

			while (ss) {
				int e;
				ss >> e;
			}
		}
	}
	catch (std::ifstream::failure e) {
		std::cerr << "Exception ocurred opening/closing/reading file." << std::endl;
	}
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