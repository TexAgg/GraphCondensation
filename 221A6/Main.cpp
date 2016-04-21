/*
	Main.cpp
	Matt Gaikema
	CSCE 221: 504
*/

#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

/*
	The command line argument should be 
	a filename with the graph data.
*/
int main(int argc, char ** argv) {
	if (argc < 2) {
		// Insufficient arguments
		cout << "Usage: ./main + <filename>";
		return 1;
	}
	
	cout << "The file input was " << argv[1] << "." << endl;
	matt::Graph graph(argv[1]);
	cout << "Here is the first graph:" << endl;
	graph.display_graph();

	matt::Graph graph_t = graph.transpose();
	cout << "\nHere is the transpose:" << endl;
	graph_t.display_graph();

	/*
	// Test copy constructor.
	matt::Graph graph2(graph);
	cout << "\nHere is the second graph:" << endl;
	graph2.display_graph();
	*/

	/*
	cout << "\nNow we will display the results of a depth-first search:" << endl;
	graph.display_dfs();
	cout << "\n";
	cout << "\nNow we will display the results of a depth-first search on the transpose:" << endl;
	//graph_t.display_dfs(graph_t.size()*2);
	graph_t.display_dfs();
	cout << "\n";
	*/

	cout << "\nNow I will show the strongly connected components:" << endl;
	graph_t.print_scc();

	cout << "\nNow I will display the acyclic component:\n" << endl;
	matt::Graph graph_a = graph.get_acyclic();
	graph_a.display_graph();

	return 0;
}