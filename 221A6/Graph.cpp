/*
	Graph.cpp
	Matt Gaikema
	CSCE 221: 504
*/

#include "Graph.h"

namespace matt {

Graph::Graph() {

}

/**
	Inserts a Vertex and adds an edge
	from it to the Vertex of label end.
	@param vertex The vertex to insert.
	@param end The label of the Vertex to
	connect it to.
*/
void Graph::insert(Vertex vertex, int end) {
	//vertex.edge_list.clear();
	vertices.push_back(vertex);
	//reorder();
	//vertices[end - 1].connect_to(vertex.label);

	vertex.connect_to(end);
	reorder();
}

/**
	Supposed to create a Graph
	with size vertices.
	It does nothing.
*/
Graph::Graph(int size) {

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

/**
	@return The number of vertices.
*/
const int Graph::size() {
	return vertices.size();
}

/**
	We were told to implement this function,
	but were never told what it is supposed to do,
	so it does nothing.
*/
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
	// in the new Graph.
	for (auto& v : new_graph.vertices) {
		v.edge_list.clear();
	}
	// Populate edge lists.
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
	@param lst A list of strongly-connected vertices.
*/
void Graph::dfs_visit(Vertex& vertex, int* time, std::list<Vertex>& lst) {
	vertex.time_stamp.state = Color::GREY;
	(*time)++;
	vertex.time_stamp.start = *time;

	for (auto& e : vertex.edge_list) {
		if (vertices[e.end - 1].time_stamp.state == Color::WHITE) {
			lst.push_back(vertices[e.end - 1]);
			dfs_visit(vertices[e.end - 1], time, lst);
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
		if (vertices[i].time_stamp.state == Color::WHITE) {
			scc.emplace(vertices[i], std::list<Vertex>{});
			dfs_visit(vertices[i], &time, scc[vertices[i]]);
		}
	}
}

/**
	Displays the time stamps calculated
	by performing a depth-first search.
	@param start The Vertex to start at.
	@param os The ostream to display the data.
*/
void Graph::display_dfs(int start, std::ostream& os) {
	depth_first_search(start);
	for (auto v : vertices) {
		std::cout << v.label << "(" << v.time_stamp.start << "," << v.time_stamp.stop << "), ";
	}
}

/**
	@return The acyclic component of the Graph.
	Very bad code. It can certainly be cleaned
	up and optimized but I am too afraid to touch it.
	I think that a good chunk of it is useless.
*/
Graph Graph::get_acyclic() {
	// Make sure the SCCs are up-to-date.
	depth_first_search();
	Graph t = transpose();
	t.depth_first_search();
	Graph acycle;
	std::map<Vertex, std::list<Vertex>> temp_scc_t = t.scc;

	// I think this loop is useless, but I'm too scared to delete it.
	for (std::pair<Vertex, std::list<Vertex>> rep : temp_scc_t) {
		for (Vertex mem : rep.second) {
			for (std::list<Edge>::iterator e = mem.edge_list.begin(); e != mem.edge_list.end(); e++) {
				rep.first.edge_list.push_back(*e);
			}
		}
		acycle.insert(rep.first);
	}

	// Add edges of strongly connected components 
	// the edge list of the representative Vertex.
	std::vector<Vertex> temp_vertices;
	for (std::pair<Vertex, std::list<Vertex>> rep : temp_scc_t) {
		Vertex temp_new_vertex = vertices[rep.first.label-1];
		for (Vertex mem : rep.second) {
			for (std::list<Edge>::iterator e = vertices[mem.label-1].edge_list.begin(); e != vertices[mem.label-1].edge_list.end(); e++) {
				temp_new_vertex.edge_list.push_back(*e);
			}
		}
		temp_vertices.push_back(temp_new_vertex);
	}
	
	// This loop might also be useless.
	for (auto k : temp_scc_t) {
		acycle.insert(vertices[k.first.label-1]);
	}

	// Remove repeated Edges.
	for (auto& v : temp_vertices) {
		for (auto e = v.edge_list.begin(); e != v.edge_list.end();) {
			if (!contains(temp_vertices, e->end) || e->end == v.label) {
				e = v.edge_list.erase(e);
			}
			else {
				e++;
			}
		}
	}
	acycle.vertices = temp_vertices;
	return acycle;
}

/**
	Displays the strongly connected components.
*/
void Graph::print_scc() {
	depth_first_search();
	for (auto k : scc) {
		std::cout << k.first << ", ";
		for (auto j : k.second) {
			std::cout << j << ", ";
		}
		std::cout << "\n";
	}
}

/**
Makes sure the the labels for vertices
match their place in the vertices vector.
*/
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

/**
	Insert a Vertex, without specifying what
	it connects to.
	This method is private because a Vertex
	shouldn't be an island.
	@param vertex A Vertex.
*/
void Graph::insert(Vertex vertex) {
	vertices.push_back(vertex);
	reorder();
}

} // End matt namespace