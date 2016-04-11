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
	@param an int, to be set as the label.
*/
Vertex::Vertex(int l) : label(l) {

}


Vertex::~Vertex() {

}

void Vertex::connect_to(int end) {

}

std::istream& operator>>(std::istream& is, Vertex) {

}

} // End matt namespace