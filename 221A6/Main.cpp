/*
	Main.cpp
*/

#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main(int argc, char ** argv) {
	if (argc < 2) {
		// Insufficient arguments
		cout << "Usage: ./main + <filename>";
		return 1;
	}

	ifstream infile;
	
	/*
	cout << "Hello, world." << endl;
	for (int i = 0; i < argc; i++) {
		cout << string(argv[i]) << endl;
	}
	*/

	infile.open(argv[1]);
	if (!infile) {
		cout << "Error! file does not exist" << endl;
		return 1;
	}

	return 0;
}