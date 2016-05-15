(* ::Package:: *)

(* ::Title:: *)
(*Graph Condensation*)


(* ::Subtitle:: *)
(*Matt Gaikema*)
(*May 2016*)


(* ::Section:: *)
(*Information*)


(* ::Text:: *)
(*Display a graph, its transpose, and its directed acyclic component.*)


(* 
	Display.wl
	Displays a graph, its transpose,
	and its directed acyclic components.
*)


(* ::Section:: *)
(*Setup Code*)


(* Clear variables. *)
ClearAll["Global`*"]
(* Limit variable scope to just this document. *)
SetOptions[EvaluationNotebook[], CellContext -> Notebook]
(* Set working directory to package directory. *)
SetDirectory[NotebookDirectory[]]


(* ::Section:: *)
(*File Parsing*)


(* Import the file. *)
Import["test1.txt","Table"];
(* Remove the deliminating -1 at the end of each line. *)
input = Drop[#,-1]&/@%;
(* http://mathematica.stackexchange.com/a/47530/39769 *)
Flatten[Thread[#1 -> {##2}] & @@@ input];


(* ::Section:: *)
(*Graphs*)


(* ::Subsection:: *)
(*Original Graph*)


(* The original graph. *)
g =Graph[%,VertexLabels->"Name"]


(* ::Subsection:: *)
(*Transpose*)


(* The transpose of g. *)
gt = ReverseGraph[g]


(* ::Subsection:: *)
(*Condensation*)


(* Find the connected components of g. *)
c = ConnectedComponents[g]


(* https://www.wolfram.com/mathematica/new-in-8/graph-and-network-analysis/topological-sorting.html *)
edges = Union[
   Cases[EdgeList[g] /. 
     Table[v -> First[Select[c, MemberQ[#, v] &]], {v, 
       VertexList[g]}], u_ \[DirectedEdge] v_ /; u =!= v]];
(* Condensation graph. *)
cond = Graph[c, edges, VertexLabels->"Name"]
