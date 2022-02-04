# IC - Projecto 3

Development of Finite Context Models with the purpose of obtaining statistical information
about a text file and to serve as a base of comparison when we want to guess the language
of a text file

## Installation

No installation of any software is needed. All libraries are from the standard library (std). 

## Languages

[<img src="https://raw.githubusercontent.com/isocpp/logos/64ef037049f87ac74875dbe72695e59118b52186/cpp_logo.svg" width="35"/>](cpp.png)

All of the classes, as well as their testing programs have been writte using C++.

## Running

All directories have an example file containing a simple g++ config to run the program and a running configuration.
There's also a Makefile on each folder to simplify the compilation process

Example of a g++ config:
```bash
g++ main.cpp FiniteContextModel.cpp CircularBuffer.cpp -o fcm
```
Example of a running configuration
```bash 
./fcm 5 0.3 ../../Texts/Analysis_texts/Os_Maias.txt
```
