#include <stdio.h>

int main (int argc, char *argv[], char **env) {
    char **p = env;
    int n = 1;
    while (*p != NULL) {
        printf ("%03d: %s\n", n, *p);
        p++;
        n++;
    }
    return 1;
}
