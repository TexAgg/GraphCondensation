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
	
	matt::Graph graph(argv[1]);
	graph.display_graph();

	return 0;
}