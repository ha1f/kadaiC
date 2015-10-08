#include <stdio.h>

#include "BridgeMatrixVector.h"
#include "Matrix.h"
#include "Vector.h"

int main() {
    Matrix* matrix = newMatrix(3, 1, (double []){
        1,
        2,
        3,
    });

    Vector* vec = newVectorFromMatrix(matrix);
    Vector_show(vec);

    matrix = newMatrixFromVector(vec);
    Matrix_show(matrix);

    Matrix_delete(matrix);
}
