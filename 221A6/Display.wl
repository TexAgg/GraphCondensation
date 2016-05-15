(* ::Package:: *)

(* 
	Display.wl
	Matt Gaikema
	Displays a graph, its transpose,
	and its directed acyclic components.
*)


(* Clear variables. *)
ClearAll["Global`*"]
(* Limit variable scope to just this document. *)
SetOptions[EvaluationNotebook[], CellContext -> Notebook]
(* Set working directory to package directory. *)
SetDirectory[NotebookDirectory[]]


(* Import the file. *)
Import["test1.txt","Table"];
(* Remove the deliminating -1 at the end of each line. *)
input = Drop[#,-1]&/@%;
(* http://mathematica.stackexchange.com/a/47530/39769 *)
Flatten[Thread[#1 -> {##2}] & @@@ input];


(* The original graph. *)
g =Graph[%,VertexLabels->"Name"]


(* The transpose of g. *)
gt = ReverseGraph[g]


(* Perform DFS on the graph and its transpose. *)
DepthFirstScan[g]
DepthFirstScan[gt,%[[1]]]


(* Find the connected components of g. *)
c = ConnectedComponents[g]


(* https://www.wolfram.com/mathematica/new-in-8/graph-and-network-analysis/topological-sorting.html *)
edges = Union[
   Cases[EdgeList[g] /. 
     Table[v -> First[Select[c, MemberQ[#, v] &]], {v, 
       VertexList[g]}], u_ \[DirectedEdge] v_ /; u =!= v]];
cond = Graph[c, edges, VertexLabels->"Name"]


(* http://mathematica.stackexchange.com/questions/33638/remove-redundant-dependencies-from-a-directed-acyclic-graph *)
