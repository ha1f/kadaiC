#include <stdio.h>

#include "Vector.h"

int main() {
    Vector* a = newVector(3, (double []){1,2,3});
    Vector* b = newVector(3, (double []){2,3,4});
    Vector_show(a);
    Vector_multiply(a, 3);
    Vector_show(a);
    Vector_show(b);
    printf("%lf\n", Vector_dotProduct(a, b));

    deleteVector(a);
    deleteVector(b);
    return 0;
}
