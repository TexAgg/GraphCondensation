OBJ = main.o Graph.o Vertex.o Edge.o
MAIN = main

$(MAIN): $(OBJ)
	g++ -std=c++11 -o $(MAIN) $(OBJ)

main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

Graph.o: Graph.cpp Graph.h
	g++ -std=c++11 -c Graph.cpp

Vertex.o: Vertex.cpp Vertex.h
	g++ -std=c++11 -c Vertex.cpp

Edge.o: Edge.cpp Edge.h
	g++ -std=c++11 -c Edge.cpp

clean: 
	rm -f $(OBJ) $(MAIN)
