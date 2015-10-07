#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Vector3.h"

int main() {
    printf("HelloWorld!\n");

    /**  */
    Vector3* vectors[5] = {
        newVector3(1.109, 4.202, 4.689),
        newVector3(5.014, 1.508, 3.478),
        newVector3(1.991, 3.846, 4.163),
        newVector3(2.818, 6.848, 0.333),
        newVector3(3.284, 2.13, 4.587)
    };

    for (int i=0; i<5; i++) {
        printf("%lf\n", Vector3_length(vectors[i]));
        Vector3_normalize(vectors[i]);
        printf("%lf\n", Vector3_length(vectors[i]));
    }

    for (int i=0; i<5; i++) {
        deleteVector3(vectors[i]);
    }
    return 0;
}
