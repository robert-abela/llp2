#ifndef REVISION_LO2_STACK_LIST_INCLUDED
#define REVISION_LO2_STACK_LIST_INCLUDED

#include <stdbool.h>

/* Stack (linked list) item */
struct item
{
    int value;
    struct item* next;
};

/* Returns true if value exists in the linked list (or false if it doesn't) */
bool exists(struct item *head, int value)
{
    return false;
}

/* Prints out all the items in a linked list */
void print_stack(struct item *item)
{
    printf("\n");
}

/* Add an item at the begining of a linked list */
void push_item(struct item** head_ref, int new_value)
{
    ;
}

/* Add an item at the begining of a linked list */
void pop_item(struct item** head_ref)
{
    ;
}

void free_list(struct item *head)
{
    ;
}

#endif // REVISION_LO2_STACK_LIST_INCLUDED
