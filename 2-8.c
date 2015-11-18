#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Matrix.h"

int main() {
    const int n=3;

    Matrix* matrixHn = newZeroMatrix(n, n);
    for(int i=0; i<Matrix_getLine(matrixHn); i++) {
        for(int j=0; j<Matrix_getRow(matrixHn); j++) {
            Matrix_set(matrixHn, i, j, pow(0.5, abs(i-j)));
        }
    }

    Matrix* res = newMatrix_inverse(matrixHn);

    printf("逆行列:");
    Matrix_show(res);

    printf("確認1:");
    Matrix* product1 = newMatrix_mlt(matrixHn, res);
    Matrix_show(product1);
    deleteMatrix(product1);

    printf("確認2:");
    Matrix* product2 = newMatrix_mlt(res, matrixHn);
    Matrix_show(product2);
    deleteMatrix(product2);

    deleteMatrix(matrixHn);
    deleteMatrix(res);
}
