/*
	Main.cpp
*/

#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main(int argc, const char * argv[]) {
	
	ifstream infile;
	
	cout << "Hello, world." << endl;
	cout << *argv[1] << endl;

	infile.open(argv[1]);

	if (!infile) {
		cout << "Error!" << endl;
	}

	return 0;
}