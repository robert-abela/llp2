#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define BOOL int

typedef struct Persons
{
   char name[50];
   char surname[50];
   char address[100];
   int  yob;
   struct Persons* next;
} person;

/* Head of the list. NULL means empty list */
person *list_head = NULL;

/* Retrieves the list head record or NULL if list is empty */
person* get_list_head()
{
    return list_head;
}

/* Set first element of the list */
void set_list_head(person* new_head)
{
    list_head = new_head;
}
