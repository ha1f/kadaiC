#include <stdio.h>

#include "Matrix.h"
#include "Vector.h"
#include "BridgeMatrixVector.h"

Vector* newVectorFromMatrix(Matrix* matrix) {
    if (!Matrix_isVector(matrix)) {
        printf("Not Vector!");
        return NULL;
    }

    int dim = ((Matrix_getLine(matrix) > 1) ? Matrix_getLine(matrix):Matrix_getRow(matrix));
    Vector* vec = newVector(dim, Matrix_getComponents(matrix));
    deleteMatrix(matrix);

    return vec;
}

//とりあえず縦
Matrix* newMatrixFromVector(Vector* vector) {

    Matrix* matrix = newMatrix(Vector_getDim(vector), 1, Vector_getComponents(vector));

    deleteVector(vector);

    return matrix;
}
