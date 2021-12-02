# Learning Outcome 1 Revision
## 1.1 Arrange the operation of a multi-source file compilation
Write a program (```lo1.c```) that reads a line of text from the user and calculates the number of words entered. If executed with the command line argument __–c__ the number of characters should also be counted. Example usage:

```
$ ./counter 
Enter text: this is a test 
4 words
$ ./counter –c 
Enter text: this is a test 
4 words (14 characters)
```

You are to write the logic yourself. The only system header files allowed are: stdio.h & stdbool.h

## 1.2 Examine specific tools used to solve common build problems
Your solution should include a header file (lo1.h) with the implementation of following functions:
```
/* returns true if –c is passed as the first command line argument */ 
bool should_count_chars(int argc, char* argv[]);
/* returns true if the character passed is a space or a tab */ 
bool is_space(char c);
```
Your header file should include a mechanism to avoid duplicate inclusion

## 1.3 Arrange a ‘Make’ or ‘Build’ utility
Create a makefile for your solution with the following targets:
* build: creates the executable
* clean: removes the executable
* rebuild: clean followed by build

The default target should be rebuild

## 1.5 Examine typical usage of conditional compilation within a program 
Extend your program to have two versions of the executable:
* Normal: read only one line of text
* Extended: keep reading line after line forever.

Conditional compilation (#ifdef) should be used for this task. The makefile should be updated to produce two outputs: 
* __counter__ (normal version) and 
* __counter2__ (extended version)

## 1.4 Construct a multi-source tool-chain for a given device 
Finally you are to extend your makefile further to allow for debug and release builds of both program versions. The debug versions will be used by developers while the release versions will be used for customer devices.
The difference between debug and release versions stands in the flags passed to GCC
* Debug: no optimization and include debugging symbols
* Release: optimization and no debug symbols

Use the GCC manual to research what flags are to be used in each case.
Your makefile will create 2 folders: debug and release (if they do not exist yet) and the executables should be placed in the respective folder. The resulting folder structure is shown below:
```
lo1_revision/
|- lo1.c
|- lo1.h
|- makefile
|- debug/
|   |- counter
|   |- counter2
|- release/
    |- counter
    |- counter2
```
Check the size of the debug and release executables. Take note of the difference the flags make.

## 1.6 Evaluate functionality of multi-source code using a debug toolchain 
For this course you are expected to know how to use a debugger of your choice.  
Mention at least two instances where a debugger was useful while doing this task.

A number of programs with their respective core dumps can be found at: [crashes/intel](crashes/intel) (or [crashes/apple_m1](crashes/apple_m1) if you are using Apple M1 CPU). There Load each pair of files (e.g. one_binary and one_core) in gdb and answer the following questions:

* What line number of the program code was executed last?
* Generate a stack trace of the execution at the time the core dump was created.
* How many command line arguments were passed when the program was executed?
* Explain what caused the core dump to be created.
