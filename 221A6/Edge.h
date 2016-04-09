#ifndef EDGE_H
#define EDGE_H

namespace matt {

class Edge {

public:
	Edge(int start, int end, int weight);
	~Edge();

private:
	// Start vertex's label
	int start;
	// End vertex's label
	int end;
	// Weight of the edge
	int weight;

	friend class Vertex;
	friend class Graph;
};

} // End matt namespace

#endif