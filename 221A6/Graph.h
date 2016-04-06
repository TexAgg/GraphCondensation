/*
	Graph.h
*/

#ifndef GRAPH_H
#define GRAPH_H

namespace matt{

template <typename T> class Graph;
template <typename T> class Vertex;
template <typename T> class Edge;

template <typename T>
class Vertex {

	friend class Edge;
	friend class Graph;
};


template <typename T>
class Edge {

	friend class Vertex;
	friend class Graph;
};


template <typename T>
class Graph {

}


} // End matt namespace

#endif