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
	
	matt::Graph graph;
	ifstream infile;

	infile.open(argv[1]);
	if (!infile) {
		cout << "Error! file does not exist" << endl;
		return 1;
	}
	while (infile) {
		string str;
		getline(infile, str);
	}

	return 0;
}