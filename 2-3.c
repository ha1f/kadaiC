#include <stdio.h>
#include "Matrix.h"

int main() {

    Matrix* matrix1 = newMatrix(3, 3, (double []){
        1.0, 0.0, 0.0,
        3.0, 1.0, 0.0,
        -2.0, 2.0, 1.0
    });

    Matrix* matrix2 = newMatrix(3, 3, (double []){
        2.0, 1.0, -1.0,
        0.0, 3.0, 2.0,
        0.0, 0.0, -3.0
    });

    Matrix* res = newMatrix_mlt(matrix1, matrix2);

    Matrix_show(res);

    deleteMatrix(res);
    deleteMatrix(matrix1);
    deleteMatrix(matrix2);

}
