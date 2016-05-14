(* ::Package:: *)

(* Matt Gaikema
5/14/2016 *)


(* Clear variables. *)
ClearAll["Global`*"]
(* Limit variable scope to just this document. *)
SetOptions[EvaluationNotebook[], CellContext -> Notebook]
(* Set working directory to package directory. *)
SetDirectory[NotebookDirectory[]]


(* http://mathematica.stackexchange.com/questions/46598/how-do-i-upload-a-graph-as-an-adjacency-list-and-find-the-betweenness-centrality *)


(* Import the file. *)
Import["test1.txt","Table"];
(* Remove the deliminating -1 at the end of each line. *)
input = Drop[#,-1]&/@%;
(* Create a map to the first element in the list 
from the list it resides in. *)
AssociationMap[#[[1]]&,input];
(* Reverse that map. *)
AssociationMap[Reverse,%];
(* Drop the first element in each value. *)
b=Drop[#,1]&/@Values[%];
(* Create a new map from the first element in the list
to its line, minus the first and last elements. 
Now I have an association map of vertices to adjacent vertices. *)
AssociationThread[Keys[%%]->%]


at = %;
Normal[at]


input
edges = Union[
  Sort /@ Flatten[MapIndexed[Thread[First[#2] -> #] &, input]]]
Graph[%]


b
Union[
  Sort /@ Flatten[MapIndexed[Thread[First[#2] -> #] &, b]]]
Graph[%,VertexLabels->"Name"]


(* ::InheritFromParent:: *)
(*Graph[{1, 2, 4, 5, 3, 7, 6}, {{{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 3}, {2, 6}, {5, 3}, {3, 4}, {3, 7}, {3, 6}, {4, 7}, {7, 6}}, Null}, {FormatType -> TraditionalForm, FormatType -> TraditionalForm, GraphLayout -> Automatic, VertexLabels -> {"Name"}}]*)


Graph[{1->2,1->4,1->5,2->3,2->4,2->7,3->4,4->6,4->7,5->4,6->5,7->6},VertexLabels->"Name"]
