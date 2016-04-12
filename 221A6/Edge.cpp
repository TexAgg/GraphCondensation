/*
	Edge.cpp
	Matt Gaikema
	CSCE 221: 504
*/

#include "Edge.h"

namespace matt {

/**
	The constructor for the Edge class.
	Creates an Edge connecting the two Vertices
	whose labels are passed as arguments.
	@param start The label for the first Vertex.
	@param end The label for the second Vertex.
	@param weight The weight of the Edge.
*/
Edge::Edge(int start, int end, int weight): 
start(start),
end(end),
weight(weight) {

}


Edge::~Edge() {

}

/**
	The output stream for an Edge only prints the
	end variable.
*/
std::ostream& operator<<(std::ostream& os, Edge& edge) {
	//os << edge.start << "->" << edge.end;
	os << edge.end;
	return os;
}

} // End matt namespace