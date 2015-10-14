#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

int main() {
    char* p = malloc(500);
    printf("%ld\n", (long)p);
    printf("%zu\n", malloc_size(p));

    char* p2 = malloc(200);
    printf("%ld\n", (long)p2);
    printf("%zu\n", malloc_size(p2));


    printf("%ld\n", ((long)p2 - (long)p));

    free(p);
    free(p2);


    return 0;
}
