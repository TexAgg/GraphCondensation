# Planning

## File input
1. The file is opened.
2. Each line of the file is read and passed to the `Graph`.
3. The first element in the line is used to make a new `Vertex`,
which is pushed into the `Graph`'s Vertex vector.
4. Using >> and `peek`, edges will be emplaced into the `edge_list`.

## Transpose
Given a Graph `G`, create a new Graph `GT` with the same number of vertices.
For ever Vertex `v` in `G`, iterate through the Edges `e` in `v`. 