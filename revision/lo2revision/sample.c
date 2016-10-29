#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_list.h"

/* Function to get union of two linked lists head1 and head2 */
struct item *getUnion(struct item *head1, struct item *head2)
{
    struct item *result = NULL;
    struct item *t1 = head1, *t2 = head2;

    // Insert all elements of list1 to the result list
    while (t1 != NULL)
    {
        push_item(&result, t1->value);
        t1 = t1->next;
    }

    // Insert those elements of list2 which are not
    // present in result list
    while (t2 != NULL)
    {
        if (!exists(result, t2->value))
            push_item(&result, t2->value);
        t2 = t2->next;
    }

    return result;
}

/* Function to get intersection of two linked lists
  head1 and head2 */
struct item *getIntersection(struct item *head1, 
                              struct item *head2)
{
    struct item *result = NULL;
    struct item *t1 = head1;

    // Traverse list1 and search each element of it in
    // list2. If the element is present in list 2, then
    // insert the element to result
    while (t1 != NULL)
    {
        if (exists(head2, t1->value))
            push_item(&result, t1->value);
        t1 = t1->next;
    }

    return result;
}

int main()
{
    /* Start with the empty list */
    struct item* head1 = NULL;
    struct item* head2 = NULL;
    struct item* intersecn = NULL;
    struct item* unin = NULL;

    /*create a linked lits 10->15->5->20 */
    push_item(&head1, 20);
    push_item(&head1, 4);
    push_item(&head1, 15);
    push_item(&head1, 10);
    push_item(&head1, 10); /* duplicate: will be ignored */

    /*create a linked lits 8->4->2->10 */
    push_item(&head2, 10);
    push_item(&head2, 2);
    push_item(&head2, 4);
    push_item(&head2, 8);
    pop_item(&head2);
    push_item(&head2, 8);

    intersecn = getIntersection (head1, head2);
    unin = getUnion (head1, head2);

    printf("\n First list is \n");
    print_stack(head1);

    printf("\n Second list is \n");
    print_stack(head2);

    printf("\n Intersection list is \n");
    print_stack(intersecn);

    printf("\n Union list is \n");
    print_stack(unin);

    return 0;
}