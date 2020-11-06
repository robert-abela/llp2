# Learning outcome 1 revision
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

## 1.2 Examine specific tools used to protect from duplicate inclusion
Your solution should include a header file (lo1.h) with the implementation of following functions:
```
/* returns true if –c is passed as the first command line argument */ 
bool should_count_chars(int argc, char* argv[]);
/* returns true if the character passed is a space or a tab */ 
bool is_space(char c);
```
Your header file should include a mechanism to avoid duplicate inclusion

## 1.3 Arrange a ‘C’ language ‘Make’ or ‘Build’ utility
Create a makefile for your solution with the following targets:
* build: creates the executable
* clean: removes the executable
* rebuild: clean followed by build

The default target should be rebuild
