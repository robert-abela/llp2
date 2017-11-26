#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

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


/* Finds the last allocation entry in list, or returns NULL if list is empty */
person* find_last() {
	return NULL;
}

/* Add a person to the end of the list */
void add_person_at_end(person* new_person) {

}

/* Prints a string representation of a person */
void print_person(person* p) {

}

/* Returns a pointer to the person at the specified index or NULL if nothing is there */
person* get_person_at_index(int index) {
	return NULL;
}

/* Remove a person from list and free memory */
bool remove_person_at_index(int index) {
	return true;
}

/* Frees all the persons in the list */
void free_list() {

}

/* Calculate the total number of persons in the list */
int count_list_size() {
	return 0;
}

/* Generate an amount of identical persons - for testing purposes */
void generate_persons(int amount)
{
    for (int i=0; i < amount; i++)
    {
        person* p = (person*)malloc(sizeof(person));
        sprintf (p->name, "John %d", i);
        strcpy(p->surname, "Doe");
        strcpy(p->address, "unknown");
        p->yob = 2000+i;
        add_person_at_end(p);
    }
}

int main (int argc, char *argv[])
{
	/*
	//confirm that the list is empty when we start
	assert (count_list_size() == 0);
    
    //generate 10 persons and check that the count is 10
    generate_persons(10);
    assert (count_list_size() == 10);

    //confirm that there is a person at index 0 and 9
    assert (get_person_at_index(0) != NULL);
    assert (get_person_at_index(9) != NULL);

    //get the last person and confirm yob
    person *last = get_person_at_index(9);
    assert (last != NULL);
    assert (last->yob == 2009);

    //remove last person and confirm it was successful
	assert (remove_person_at_index(9) == true);
	assert (count_list_size() == 9);

	//free list and confirm count is zero
    free_list();
    assert (count_list_size() == 0);
    */

    return 0;
}