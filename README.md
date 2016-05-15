# CSCE 221 A6
Find the acyclic component graph, or condensation graph, 
of a graph, implemented in C++ as well as in Mathematica.

I originally did in in C++ for an assignment, 
and decided to try it in Mathematica for fun.

---
# Assignment
Assignment [here](https://www.dropbox.com/s/vfoyy1ye5c5xkyi/221-16a-A6.pdf?dl=0), 
and supplementary files [here](https://www.dropbox.com/sh/rcykbptpvj9og7n/AADdbkxw-lxc0gcjXpwOeh90a?dl=0).

Due April 21.

The assignment is to make a graph data structure.
Using the graph, we are supposed to find the strongly connected components using
depth-first search on the graph and on the transpose.

I have done it in C++ and also in Mathematica.

---

# Instructions

## Mathematica
Enter the text file in Display.wl and run the package.

## Windows
Open the [.sln](https://bitbucket.org/gaikema/csce221-a6/src/983578edd3dae28726b37fc0e60ca098925fafb4/221A6.sln?at=master&fileviewer=file-view-default) file in Visual Studio.
To add command line parameters, go to 'project->221A6 properties' and, in the window, under configuration properties, 
go to the 'debugging' tab and enter the text file.

## Linux
In the root, go to the folder '221A6'.
Type `make` to compile the program.
Type `make test` to run with the command line argument 'input.txt',
or type	`./Main <filename>` to run it with your own file.
Type `make clean` to remove all of the output files.

## Mac
I dunno, open it in xcode or something.

## CMake
```
$ mkdir _build
$ cd _build
$ cmake ..\cmakelists.txt
```
The build files will be in the `_build` folder.
If you are using Visual Studio, this will essentially just clone the folder in the `_build` folder as well as add some other files,
which is essentially useless, but makes me feel cool.

---

# Tests
* [test1.txt](https://bitbucket.org/gaikema/csce221-a6/src/41209edfb34d93d6df8f381c5e0af4cc4e433666/221A6/test1.txt?at=master&fileviewer=file-view-default)
is the graph example given in the assignment.
* [test2.txt](https://bitbucket.org/gaikema/csce221-a6/src/41209edfb34d93d6df8f381c5e0af4cc4e433666/221A6/test2.txt?at=master&fileviewer=file-view-default)
is the graph shown in class as an example for finding the strongly connected components.
* [test3.txt](https://bitbucket.org/gaikema/csce221-a6/src/41209edfb34d93d6df8f381c5e0af4cc4e433666/221A6/test3.txt?at=master&fileviewer=file-view-default)
is the graph found [here](http://courses.cs.tamu.edu/teresa/cpsc211/BFS-DFS/DFS/DFS.html).
