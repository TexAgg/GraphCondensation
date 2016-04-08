/*
	Graph.h
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

namespace matt{

template <typename T> class Graph;
template <typename T> class Vertex;
template <typename T> class Edge;

template <typename T>
class Vertex {
private:
	vector<Edge> edges;
	
	friend class Edge;
	friend class Graph;
};


template <typename T>
class Edge {
private:
	Vertex previous, next;

	friend class Vertex;
	friend class Graph;
};


template <typename T>
class Graph {

};


} // End matt namespace

#endif