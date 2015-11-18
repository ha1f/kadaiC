#include <stdio.h>
#include "Matrix.h"

int main() {

    Matrix* matrixL = newMatrix(3, 3, (double []){
        1.0, 0.0, 0.0,
        3.0, 1.0, 0.0,
        -2.0, 2.0, 1.0
    });

    /*Matrix* matrixU = newMatrix(3, 3, (double []){
        2.0, 1.0, -1.0,
        0.0, 3.0, 2.0,
        0.0, 0.0, -3.0
    });*/


    Matrix* matrixY = newMatrix(3, 1, (double []){
        2.0,
        3.0,
        -1.0,
    });

    /*Matrix* matrixY2 = newMatrix(3, 1, (double []){
        2.0,
        -3.0,
        9.0,
    });*/

    Matrix* c = newFS(matrixL, matrixY);
    //Matrix* c = newBS(matrixU, matrixY2);
    Matrix_showFlat(c);

    deleteMatrix(matrixL);
    //deleteMatrix(matrixU);
    deleteMatrix(matrixY);
    //deleteMatrix(matrixY2);
    deleteMatrix(c);
}
