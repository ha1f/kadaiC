#include <stdio.h>
#include "Matrix.h"

#define PRO(a) ((1-s)*a/6)

const double s = 0.8;

// posをupdate
void move(Matrix** pos, Matrix* matrix) {
    Matrix* res = newMatrix_mlt(matrix, *pos);
    deleteMatrix(*pos);
    *pos = res;
}

int main() {
    // 遷移行列
    Matrix* matrix = newMatrix(6, 6, (double []){
        (s+PRO(3)),PRO(2),PRO(1),0,0,0,
        PRO(3), s,PRO(2), PRO(1),0,0,
        PRO(1),PRO(2),s,PRO(2),PRO(1),0,
        0,PRO(1),PRO(2),s,PRO(2),PRO(1),
        0,0,PRO(1),PRO(2),s,PRO(3),
        0,0,0,PRO(1),PRO(2),s+PRO(3)
    });
    Matrix_show(matrix);
    // 転置
    Matrix_transpose(matrix);

    //初期位置
    Matrix* pos = newMatrix(6, 1, (double []){
        1,
        0,
        0,
        0,
        0,
        0
    });
    Matrix_showFlat(pos);
    for(int i=0; i < 31; i++) {
        move(&pos, matrix);
        Matrix_showFlat(pos);
    }

    deleteMatrix(pos);
    deleteMatrix(matrix);
    return 0;
}
