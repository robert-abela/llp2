#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* memset */

#include "stack_list.h"

struct item *head1 = NULL, *head2 = NULL;

/* Join the two lists in a new one 
 * Hint: use push_item()
 */
struct item *join_lists()
{
    struct item *joined = NULL;
    return joined;
}

/* Return a list that contains the values present in both lists 
 * Hint: use push_item() and exists()
 */
struct item *find_overlap()
{
    struct item *overlap = NULL;
    return overlap;
}

int main(int argc, char *argv[]) 
{
    struct item *overlap, *joined;

    /*create a linked list 5->4->3->2->1 */
    push_item(&head1, 1);
    push_item(&head1, 2);
    push_item(&head1, 2); /* duplicate: push_item should be ignored */
    push_item(&head1, 3);
    push_item(&head1, 4);
    push_item(&head1, 5);

    /*create a linked list 10->8->6->4->2 */
    push_item(&head2, 2);
    push_item(&head2, 4);
    push_item(&head2, 6);
    push_item(&head2, 8);
    pop_item(&head2);     /* remove last added to test pop_item */
    push_item(&head2, 8);
    push_item(&head2, 10);

    overlap = find_overlap();
    joined = join_lists();

    printf("1st list: ");
    print_stack(head1);

    printf("2nd list: ");
    print_stack(head2);

    printf("Overlap:  ");
    print_stack(overlap);

    printf("Joined:   ");
    print_stack(joined);

    free_list(head1);
    free_list(head2);
    free_list(overlap);
    free_list(joined);

    return 0;
}
