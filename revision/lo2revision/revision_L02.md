# Learning Outcome 2 Revision
## 2.1 Examine typical language scope
Consider the following program:
```c
#include <stdio.h>
void test() { 
    /*static*/ int count = 0; 
    printf("%d\n", ++count); 
}
int main(int argc, char *argv[]) { 
    for (int i=0; i<5; i++) test(); 
}
```

Questions:
* What is the output when you run this program?
* How will the output change if ```static``` is uncommented?
* Can you explain this difference?

Consider the following program:
```
1.  void test2(int param) 
2.  { 
3.    int var1 = 0; 
4.    if (param > 0) 
5.    { 
6.      int var2 = 0; 
7.      var2 = 10; 
8.    } 
9.    var1++; 
10.   var2++; 
11. } 
12. char c; 
13. int main(int argc, char *argv[]) { 
14.   c = 55; 
15.   test2(c); 
16. }
```
Tasks:
* How many variables can you identify in this program? For each variable list the line numbers in which it is in scope
* Identify and explain any compilation errors

## 2.2 Produce relevant code to implement a data structure
Implement and LIFO structure (just like the stack works) twice:
1. The first time using an array
2. A second time using a linked list

**Using an array**

Start from the following files:
* [revision\lo2revision\use_array.c](use_array.c)
* [revision\lo2revision\stack_array.h](stack_array.h)

Using the variables and the macros defined in the header, add a body to the four functions using the comments as a guideline. Once ready the C file should be fully functional; use it to test your code.

**Using a linked list**

Start from the following files:
- [revision\lo2revision\use_list.c](use_list.c)
- [revision\lo2revision\stack_list.h](stack_list.h)

Using ```struct item``` declared in the header for each item in the linked list, you are to add a body to the five functions using the comments as a guideline. Another two functions in the C file require that you implement a body for them. Once ready use the code already present in the main function as a way to test your implementation.

## 2.3 Outline specific use-cases which could require the use of specific memory management
Outline the main difference between a ```union``` and a ```struct``` in C, using the following code as part of your explanation:
```c
union uuu {
  int x;
  char y;
};
struct sss {
  int x;
  char y;
};
```
Outline one specific use case where you would prefer to use a ```union``` instead of a ```struct```.

## 2.4 Evaluate the type of program memory management required for a given use-case (structured static or dynamically allocated) 

Consider the following programs. For each:
- What is the output when you run this program?
- Can you explain this output?

```c
#include <stdio.h> 
int g;
int main(int argc, char *argv[]) { 
    int l; 
    printf("%d\n", g); 
    printf("%d\n", l); 
    return 0; 
}
```
```c
#include <stdio.h>
int main(int argc, char *argv[]) { 
    char string[48] = "Inspiration exists but it must find you working"; 
    printf("%s.\n", string); 
    for (int i=0; i < 75; i++) 
        printf("%c", string[i]); 
    printf(".\n"); 
    return 0; 
}
```
Consider the following incomplete program:
```c
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
int main(int argc, char *argv[]) { 
    const char *sentence = "The best teacher is your last mistake"; 
    /* more code here */ 
    return 0; 
}
```

Tasks:
- Create two buffers of 50 bytes each, one on the stack and the other in the heap
- Copy sentence to both buffers
- Print out the two buffers
- Make sure there are no memory leaks

Final exercise:
- Write a new program that takes a number as a command line argument
- The program creates two int arrays one on the stack and the other in the heap
- Each should hold an amount of values as specified in the command line argument
- Fill both arrays with random values between 0 and 1024
- Print out the two arrays
- Make sure there are no memory leaks
