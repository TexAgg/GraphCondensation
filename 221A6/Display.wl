(* ::Package:: *)

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
(* Create a map to the first element in the list 
from the list it resides in. *)
AssociationMap[#[[1]]&,input];
(* Reverse that map. *)
AssociationMap[Reverse,%];
(* Drop the first element in each value. *)
Drop[#,1]&/@Values[%];
(* Create a new map from the first element in the list
to its line, minus the first and last elements. 
Now I have an association map of vertices to adjacent vertices. *)
AssociationThread[Keys[%%]->%]
