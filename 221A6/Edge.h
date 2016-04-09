#ifndef EDGE_H
#define EDGE_H

namespace matt {

class Edge
{
	// Start vertex's label
	int start;
	// End vertex's label
	int end;
	// Weight of the edge
	int weight;

public:
	Edge(int start, int end, int weight);
	~Edge();

	friend class Vertex;
};

} // End matt namespace

#endif