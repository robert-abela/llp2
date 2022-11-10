#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct FullName {
    char name[50];
    char surname[50];
};

int main(void) {
    //Option 1
    char *buffer = malloc(100);
    if (buffer == NULL)
        return -1;

    char *name = buffer, *surname = buffer + 50;
    strcpy(name, "Robert");
    strcpy(surname, "Abela");
    for (int i = 0; i < 100; i++)
        printf("buffer[%d] %hu -> %c\n", i, buffer[i], buffer[i]);
    free(buffer);

    //Option 2
    struct FullName *structure = malloc(sizeof(struct FullName));
    strcpy(structure->name, "Robert");
    strcpy(structure->surname, "Abela");

    char *test = (char*)structure;
    for (int i = 0; i < 100; i++)
        printf("structure[%d] %hu -> %c\n", i, test[i], test[i]);
    free(structure);
    return 0;
}