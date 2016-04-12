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


Vertex::~Vertex() {

}

void Vertex::connect_to(int end) {

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

} // End matt namespace