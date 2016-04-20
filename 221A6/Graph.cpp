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
	// idk
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
		std::cerr << "Exception occurred opening/closing/reading file." << std::endl;
	}
}

/**
	Copy constructor for a Graph.
*/
Graph::Graph(const Graph& graph) {
	vertices = graph.vertices;
}

/**
	Creates a Graph with just one Vertex.
*/
Graph::Graph(Vertex vertex) {
	vertices.push_back(vertex);
}

Graph::~Graph() {

}

void Graph::insert(Vertex vertex, int end) {
	//vertex.edge_list.clear();
	vertices.push_back(vertex);
	//reorder();
	//vertices[end - 1].connect_to(vertex.label);

	vertex.connect_to(end);
	reorder();
}

/**
	@return The number of vertices.
*/
const int Graph::size() {
	return vertices.size();
}

void Graph::build_graph() {
	// idk
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

/**
	Visits the vertex during a DFS,
	updating its search status and time stamps.
	Called by depth_first_search and recursively
	by its self.
	@param vertex A reference to the vertex that is
	currently being visited.
	@param time A pointer to the current time,
	which is the number of vertices visited.
*/
void Graph::dfs_visit(Vertex& vertex, int* time) {
	vertex.time_stamp.state = Color::GREY;
	(*time)++;
	vertex.time_stamp.start = *time;

	for (auto& e : vertex.edge_list) {
		if (vertices[e.end - 1].time_stamp.state == Color::WHITE) {
			dfs_visit(vertices[e.end - 1], time);
		}
	}

	vertex.time_stamp.state = Color::BLACK;
	(*time)++;
	vertex.time_stamp.stop = *time;
}

/**
	Does a depth-first search on the graph,
	visiting each vertex once.
*/
void Graph::depth_first_search(int start) {
	// Reset the vertices.
	for (auto& v : vertices) {
		v.time_stamp.start = -1;
		v.time_stamp.stop = -1;
		v.time_stamp.state = Color::WHITE;
	}

	int time = start;
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].time_stamp.state == Color::WHITE)
			dfs_visit(vertices[i], &time);
	}
}

/**
	Displays the time stamps calculated
	by performing a depth-first search.
	@param os The ostream to display the data.
*/
void Graph::display_dfs(int start, std::ostream& os) {
	depth_first_search(start);
	for (auto v : vertices) {
		std::cout << v.label << "(" << v.time_stamp.start << "," << v.time_stamp.stop << "), ";
	}
}

Graph Graph::get_acyclic() {
	//Graph acycle;
	Graph t = transpose();
	std::vector<Vertex> acyclic_vertices;
	Vertex magic;

	//depth_first_search();
	t.depth_first_search(t.size());
	for (auto v : t.vertices) {
		if (v.time_stamp.stop < 2 * t.size()) {
			acyclic_vertices.push_back(vertices[v.label-1]);
		}
		else if (v.time_stamp.start == 2 * t.size()) {
			magic = vertices[v.label-1];
		}
	}

	// There are still extra elements.

	magic.edge_list.clear();
	//for (auto k : acyclic_vertices) k.edge_list.clear();
	Graph acycle(magic);
	for (auto k : acyclic_vertices) {
		acycle.insert(k, magic.label);
	}

	for (auto& v : vertices) {
		for (auto& e : v.edge_list) {
			// If e.end is not in acyclic_vertices,
			// replace it with magic.

			if (!contains(acyclic_vertices, e.end) && e.start!=magic.label) {
				e.end = magic.label;
			}
		}
	}

	return acycle;
}

void Graph::reorder() {
	std::vector<Vertex> new_vertices;
	
	int new_size = std::max_element(vertices.begin(), vertices.end())->label;
	new_vertices.resize(new_size);

	for (auto v : vertices) {
		if (v.label != 0)
			new_vertices[v.label - 1] = v;
	}
	vertices = new_vertices;
}

bool contains(std::vector<Vertex> vector, int end) {
	//bool flag = false;

	for (auto v : vector) {
		if (v.label == end)
			return true;
	}
	return false;
}

} // End matt namespace