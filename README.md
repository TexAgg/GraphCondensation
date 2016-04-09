# CSCE 221 A6
Assignment [here](https://www.dropbox.com/s/vfoyy1ye5c5xkyi/221-16a-A6.pdf?dl=0), 
and supplementary files [here](https://www.dropbox.com/sh/rcykbptpvj9og7n/AADdbkxw-lxc0gcjXpwOeh90a?dl=0).

Due April 21.

---

# Instructions

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
Typing `make run` runs the program without any command line arguments, 
which will do nothing.
