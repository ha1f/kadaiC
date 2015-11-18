#include <stdio.h>
#include "Matrix.h"
#include <math.h>
#include <stdlib.h>

#define BOOL_STRING(a) (a ? "true" : "false")

bool Matrix_isAll1(Matrix* matirx) {
    for(int i=0; i<Matrix_getLine(matirx); i++) {
        for(int j=0; j<Matrix_getRow(matirx); j++) {
            if( Matrix_get(matirx, i, j) != 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    const int n=7;

    Matrix* matrixA = newZeroMatrix(n, n);
    for(int i=0; i<Matrix_getLine(matrixA); i++) {
        for(int j=0; j<Matrix_getRow(matrixA); j++) {
            Matrix_set(matrixA, i, j, pow(0.5, abs(i-j)));
        }
    }

    Matrix* matrixY = newZeroMatrix(n, 1);
    for(int i=0; i<Matrix_getLine(matrixY); i++) {
        Matrix_set(matrixY, i, 0, (3 - pow(2,(i-n+1)) - pow(2,(-i))));
    }


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

    //これが U x
    Matrix* res1 = newFS(matrixL, matrixY);
    printf("Ux:\n");
    Matrix_showFlat(res1);

    Matrix* res2 = newBS(matrixU, res1);
    printf("x:\n");
    Matrix_showFlat(res2);

    // 全ての要素が1であるかチェック
    printf("%s\n", BOOL_STRING(Matrix_isAll1(res2)));



    deleteMatrix(matrixA);
    deleteMatrix(matrixL);
    deleteMatrix(matrixU);

    deleteMatrix(matrixY);

    deleteMatrix(res1);
    deleteMatrix(res2);
}
