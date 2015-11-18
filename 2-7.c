#include <stdio.h>
#include "Matrix.h"

int main() {
    Matrix* matrixA = newMatrix(3, 3, (double []){
         2.0,  1.0, -1.0,
         6.0,  6.0, -1.0,
        -4.0,  4.0,  3.0
    });

    Matrix* res = newMatrix_inverse(matrixA);

    printf("逆行列:");
    Matrix_show(res);

    printf("確認:");
    Matrix* product = newMatrix_mlt(matrixA, res);
    Matrix_show(product);
    deleteMatrix(product);

    deleteMatrix(matrixA);
    deleteMatrix(res);
}
