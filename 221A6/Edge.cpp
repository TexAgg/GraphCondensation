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

Edge::Edge(const Edge& edge): 
start(edge.start),
end(edge.end),
weight(edge.weight) {
}

Edge::~Edge() {

}

/**
	Reverses the direction of the Edge.
*/
void Edge::reverse() {
	std::swap(start, end);
}

void Edge::operator=(const Edge& edge) {
	start = edge.start;
	end = edge.end;
	weight = edge.weight;
}

/**
	The output operator for an Edge only prints the
	end variable.
*/
std::ostream& operator<<(std::ostream& os, Edge& edge) {
	//os << edge.start << "->" << edge.end;
	os << edge.end;
	return os;
}

bool contains(std::list<Edge> vector, Edge end) {
	for (auto v : vector) {
		if (end == v)
			return true;
	}
	return false;
}

bool contains(std::list<Edge> vector, int end) {
	for (auto v : vector) {
		if (v.end == end)
			return true;
	}
	return false;
}

bool operator==(Edge lhs, Edge rhs) {
	return lhs.start == rhs.start && lhs.end == rhs.end && lhs.weight == rhs.weight;
}

} // End matt namespace