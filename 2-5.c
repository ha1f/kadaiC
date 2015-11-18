#include <stdio.h>
#include "Matrix.h"

#define BOOL_STRING(a) (a ? "true" : "false")

// Ax = Yをみたすxをもとめる
int main() {
    Matrix* matrixA = newMatrix(3, 3, (double []){
         2.0,  1.0, -1.0,
         6.0,  6.0, -1.0,
        -4.0,  4.0,  3.0
    });

    // LとUを求める
    Matrix* matrixL = newUnitMatrix(matrixA->line, matrixA->row);
    Matrix* matrixU = newZeroMatrix(matrixA->row, matrixA->line);
    for(int j=0; j<Matrix_getRow(matrixA); j++) {
        for(int i=0; i<Matrix_getLine(matrixA); i++) {
            double value = Matrix_get(matrixA, i, j);
            if (i<=j) {
                //uの計算
                int k=0;
                while(k <= (i-1)) {
                    value -= Matrix_get(matrixL, i, k) * Matrix_get(matrixU, k, j);
                    k++;
                }
                Matrix_set(matrixU, i, j, value);
            } else {
                //lの計算
                int k=0;
                while(k <= (j-1)) {
                    value -= Matrix_get(matrixL, i, k) * Matrix_get(matrixU, k, j);
                    k++;
                }
                value = value/Matrix_get(matrixU, j, j);
                Matrix_set(matrixL, i, j, value);
            }
        }
    }

    Matrix_show(matrixA);

    printf("matrixL:\n");
    Matrix_show(matrixL);
    printf("matrixU:\n");
    Matrix_show(matrixU);

    // LU分解に成功していることの確認
    Matrix* res = newMatrix_mlt(matrixL, matrixU);
    Matrix_show(res);
    printf("%s\n", BOOL_STRING(Matrix_isEqual(matrixA, res)));
    deleteMatrix(res);

    Matrix* matrixY = newMatrix(3, 1, (double []){
        2.0,
        3.0,
        -1.0,
    });

    //これが U x
    Matrix* res1 = newFS(matrixL, matrixY);
    printf("Ux:\n");
    Matrix_showFlat(res1);

    Matrix* res2 = newBS(matrixU, res1);
    printf("x:\n");
    Matrix_showFlat(res2);


    deleteMatrix(matrixA);
    deleteMatrix(matrixL);
    deleteMatrix(matrixU);

    deleteMatrix(matrixY);

    deleteMatrix(res1);
    deleteMatrix(res2);
}
