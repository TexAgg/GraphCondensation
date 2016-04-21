/*
	Vertex.cpp
	Matt Gaikema
	CSCE 221: 504
*/

#include "Vertex.h"

namespace matt {

/**
	The constructor for the Vertex class.
	Takes in an integer and sets it as the 
	label.
	@param l an int, to be set as the label.
*/
Vertex::Vertex(int l) : label(l) {

}

Vertex::Vertex() : label(0) {

}

Vertex::~Vertex() {

}

void Vertex::operator=(const Vertex& vertex) {
	label = vertex.label;
	edge_list = vertex.edge_list;
}

/**
	Connect this Vertex to another Vertex.
	@param end The Vertex to connect to.
*/
void Vertex::connect_to(int end) {
	edge_list.emplace_back(label, end);
}

/**
	Print the Edges of a Vertex.
	@param os the output stream to
	display the Edges.
*/
void Vertex::print_edges(std::ostream& os) {
	std::list<Edge> temp_list = edge_list;
	os << label << ": ";
	while (!temp_list.empty()) {
		os << temp_list.front() << " ";
		temp_list.pop_front();
	}
	os << -1 << std::endl;
}

bool operator<(const Vertex& lhs, const Vertex& rhs) {
	return lhs.label < rhs.label;
}

std::ostream& operator<<(std::ostream& os, const Vertex& vertex) {
	os << vertex.label;
	return os;
}

} // End matt namespace