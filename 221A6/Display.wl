(* ::Package:: *)

(* Matt Gaikema
5/14/2016 *)


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
