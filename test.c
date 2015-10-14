#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

int main() {
    char* p = malloc(112);
    printf("%ld\n", (long)p);
    printf("%zu\n", malloc_size(p));
    void* q = p;
    free(q);

    char* p2 = malloc(112);
    printf("%ld\n", (long)p2);
    printf("%zu\n", malloc_size(p2));
    free(p2);

    return 0;
}
