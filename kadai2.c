#include <stdio.h>
#include "Matrix.h"

#define PRO(a) ((1-s)*a/6)

const double s = 0.2;

int main() {
    Matrix* pos = newMatrix(1, 6, (double []){
        1,
        0,
        0,
        0,
        0,
        0
    });

    Matrix_show(pos);

    Matrix* matrix = newMatrix(6, 6, (double []){
        (s+PRO(3)),PRO(2),PRO(1),0,0,0,
        PRO(3),s,PRO(2), PRO(1),0,0,
        PRO(1),PRO(2),s,PRO(2),PRO(1),0,
        0,PRO(1),PRO(2),s,PRO(2),PRO(1),
        0,0,PRO(1),PRO(2),s,PRO(3),
        0,0,0,PRO(1),PRO(2),s+PRO(3)
    });

    Matrix* res;
    res = Matrix_mlt(pos,matrix);
    Matrix_show(res);
    Matrix_delete(res);

    Matrix_delete(matrix);
    Matrix_delete(pos);
    return 0;
}
