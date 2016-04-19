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
	//vertices.resize(size);
}

/**
	This constructor constructs a Graph from
	a file. Data must be formatted such that
	the file contains just one graph,
	with the edge lists on each line, 
	and a -1 indicating the end of
	an edge list.
	@param filename The name of file to be read from.
*/
Graph::Graph(std::string filename) {
	try {
		std::ifstream infile;
		infile.open(filename);
		while (infile) {
			std::string str;
			std::getline(infile, str);
			std::stringstream ss(str);

			Vertex vertex(int(ss.peek()-'0'));
			//vertices.push_back(vertex);
			std::vector<int> line;
			while (ss) {
				int e;
				ss >> e;
				line.push_back(e);
			}
			for (int i = 0; i < line.size() - 1; i++) {
				if (line[i + 1] == -1) break;
				vertex.edge_list.emplace_back(line[i], line[i + 1]);
			}
			vertices.push_back(vertex);
		}
		// Last element is garbage.
		vertices.pop_back();
	}
	catch (std::ifstream::failure e) {
		std::cerr << "Exception ocurred opening/closing/reading file." << std::endl;
	}
}

Graph::Graph(const Graph& graph) {
	vertices = graph.vertices;
}

Graph::~Graph() {

}

void Graph::build_graph() {

}

/**
	Display the graph.
	Example output (from input.txt):
	1: 2 4 5 -1
	2: 3 4 7 -1
	3: 4 -1
	4: 6 7 -1
	5: 4 -1
	6: 5 -1
	7: 6 -1
	@param os the output stream to
	display the Graph.
*/
void Graph::display_graph(std::ostream& os) {
	for (auto k : vertices) {
		k.print_edges(os);
	}
}

/**
	Returns the transpose of the Graph.
*/
Graph Graph::transpose() {
	Graph new_graph = Graph(*this);

	// Empty the edge list for each Vertex
	// in the new Graph
	for (auto& v : new_graph.vertices) {
		v.edge_list.clear();
	}
	// Populate edge lists
	for (int i = 0; i < vertices.size(); i++) {
		for (auto e : vertices[i].edge_list) {
			new_graph.vertices[e.end-1].connect_to(i+1);
		}
	}

	return new_graph;
}

void Graph::dfs_visit(Vertex& vertex, int* time) {
	vertex.time_stamp.state = Color::GREY;
	time++;
	vertex.time_stamp.start = *time;

	Edge child = vertex.edge_list.front();
}

void Graph::depth_first_search() {
	// Reset the vertices.
	for (auto& v : vertices) {
		v.time_stamp.start = -1;
		v.time_stamp.stop = -1;
		v.time_stamp.state = Color::WHITE;
	}
	int time = 0;
	for (auto v : vertices) {
		if (v.time_stamp.state == Color::WHITE)
			dfs_visit(v, &time);
	}

}

} // End matt namespace