#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Matrix.h"

void Matrix_init(Matrix* this, int line, int row, double *data) {
    this->line = line;
    this->row = row;
    this->components = malloc(sizeof(double) * line * row);
    memcpy(this->components, data, sizeof(double) * line * row);
}

void Matrix_changeComponents(Matrix* this, double *data) {
    memcpy(this->components, data, sizeof(double) * this->line * this->row);
}

//line*row = row*lineを利用、
void Matrix_transpose(Matrix* this) {
    double data[this->row * this->line];
    for(int i=0; i < this->line; i++) {
        for(int j=0; j < this->row; j++) {
            data[j*this->line+i] = this->components[i*this->row+j];
        }
    }
    Matrix_changeComponents(this, data);

    int tmpLine = this->line;
    this->line = this->row;
    this->row = tmpLine;
}

int Matrix_getLine(Matrix* this) {
    return this->line;
}

int Matrix_getRow(Matrix* this) {
    return this->row;
}

double* Matrix_getComponents(Matrix* this) {
    return this->components;
}

Matrix* newMatrix(int line, int row, double *data) {
    Matrix* this = malloc(sizeof(Matrix));
    Matrix_init(this, line, row, data);
    return this;
}

Matrix* newZeroMatrix(int line, int row) {
    Matrix* this = malloc(sizeof(Matrix));
    this->line = line;
    this->row = row;
    this->components = malloc(sizeof(double) * line * row);
    memset(this->components, 0, sizeof(double) * line * row);
    return this;
}

Matrix* newUnitMatrix(int line, int row) {
    if (line != row) {
        printf("Unit Matrix Error!\nNot Same Dimention!\n");
        return NULL;
    }
    Matrix* this = newZeroMatrix(line, row);
    for(int i=0; i<line; i++) {
        Matrix_set(this, i, i, 1.0);
    }
    return this;
}

void deleteMatrix(Matrix* this) {
    free(this->components);
    free(this);
}

void Matrix_show(Matrix* this) {
    printf("matrix{\n");
    for(int i=0; i<this->line; i++) {
        printf("{ ");
        for(int j=0; j<this->row; j++) {
            printf("%3g ", this->components[i*this->row+j]);
        }
        printf("},\n");
    }
    printf("};\n");
}

// そのままPythonのコードに
void Matrix_showFlat(Matrix* this) {
    printf("[ ");
    for(int i=0; i<this->line; i++) {
        for(int j=0; j<this->row; j++) {
            printf("%g, ", this->components[i*this->row+j]);
        }
    }
    printf("],\n");
}

// 成分をget
double Matrix_get(Matrix* this, int x, int y) {
    if ((x >= this->line) || (y >= this->row)) {
        printf("get Error! index out of range!\n");
        return 0;
    }
    return this->components[x * this->row + y];
}

// 成分をset
void Matrix_set(Matrix* this, int x, int y, double value) {
    if ((x >= this->line) || (y >= this->row)) {
        printf("set Error! index out of range!\n");
        return;
    }
    this->components[x * this->row + y] = value;
}

// 実数倍
void Matrix_multiplyScalar(Matrix* this, double alpha) {
    for(int i=0; i<this->line; i++) {
        for(int j=0; j<this->row; j++) {
            Matrix_set(this, i, j, Matrix_get(this, i, j) * alpha);
        }
    }
}

/*
Matrix* Matrix_newClone(Matrix* this) {
    double a[1] = {(&Matrix_getComponents(this))};
    return Matrix_new(Matrix_getLine(this), Matrix_getRow(this), a);
}*/

// 行列積として新たなベクトルを返す(deleteし忘れないように！)
Matrix* newMatrix_mlt(Matrix* this, Matrix* matrix) {
    if (this->row != matrix->line){
        printf("%d,%d", this->row, matrix->line);
        printf("Error! can't mutiply!\n");
        double dummy[1] = {0};
        return newMatrix(0, 0, dummy);
    }

    double res[this->line][matrix->row];
    for(int i=0; i<matrix->row; i++) {
        for(int j=0; j<this->line; j++) {
            res[j][i] = 0;
        }
    }

    for(int i=0; i < this->line; i++) {
        for(int j=0; j < matrix->row; j++) {
            for(int k=0; k < this->row; k++) {
                res[i][j] += Matrix_get(this, i, k) * Matrix_get(matrix, k, j);
            }
        }
    }
    return newMatrix(this->line, matrix->row, res[0]);
}

// 行列式
double Matrix_determinant(Matrix* this) {
    if(this->line != this->row) {
        printf("Error!\nNot Square Matrix!\n");
        return 0;
    }
    int dimen = this->line;
    double det = 0;
    if (dimen == 1) {
        det = Matrix_get(this, 0, 0);
    } else if (dimen == 2) {
        det = Matrix_get(this, 0, 0)*Matrix_get(this, 1, 1) - Matrix_get(this, 0, 1)*Matrix_get(this, 1, 0);
    } else if (dimen == 3) {
        det =  Matrix_get(this, 0, 0)*Matrix_get(this, 1, 1)*Matrix_get(this, 2, 2);
        det += Matrix_get(this, 1, 0)*Matrix_get(this, 2, 1)*Matrix_get(this, 0, 2);
        det += Matrix_get(this, 2, 0)*Matrix_get(this, 0, 1)*Matrix_get(this, 1, 2);
        det -= Matrix_get(this, 2, 0)*Matrix_get(this, 1, 1)*Matrix_get(this, 0, 2);
        det -= Matrix_get(this, 1, 0)*Matrix_get(this, 0, 1)*Matrix_get(this, 2, 2);
        det -= Matrix_get(this, 0, 0)*Matrix_get(this, 2, 1)*Matrix_get(this, 1, 2);
    } else {
        printf("Error!\nNot High Dimension!\n");
        return 0;
    }
    return det;
}

void Matrix_add(Matrix* this, Matrix* matrix) {
    if((this->line != matrix->line) || (this->row != matrix->row)) {
        printf("Error!\nNot Same Dimention!\n");
        return;
    }
    for(int i=0; i<this->line; i++) {
        for(int j=0; j<this->row; j++) {
            Matrix_set(this, i, j, Matrix_get(this, i, j) + Matrix_get(matrix, i, j));
        }
    }
}

void Matrix_sub(Matrix* this, Matrix* matrix) {
    if((this->line != matrix->line) || (this->row != matrix->row)) {
        printf("Error!\nNot Same Dimention!\n");
        return;
    }
    for(int i=0; i<this->line; i++) {
        for(int j=0; j<this->row; j++) {
            Matrix_set(this, i, j, Matrix_get(this, i, j) - Matrix_get(matrix, i, j));
        }
    }
}

bool Matrix_isVector(Matrix* this) {
    if ((this->line == 1) || (this->row == 1)) {
        return true;
    }
    return false;
}

bool Matrix_isSymmetric(Matrix* this) {
    if (this->line != this->row) {
        return false;
    }
    //右上の三角領域を評価
    for (int i=0; i<this->line; i++) {
        for (int j=i+1; j<this->row; j++) {
            //１つでも違えばfalse
            if (Matrix_get(this,i,j) != Matrix_get(this, j, i)) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix_isEqual(Matrix* m1, Matrix* m2) {
    if ((m1->line != m2->line) || (m1->row != m2->row) ){
        return false;
    }
    for (int i=0; i<m1->line; i++) {
        for (int j=i+1; j<m1->row; j++) {
            if (Matrix_get(m1, i, j) != Matrix_get(m2, i, j)) {
                return false;
            }
        }
    }
    return true;
}

Matrix* newFS(Matrix* matrixL, Matrix* matrixY) {
    Matrix* res = newZeroMatrix(matrixL->line,1);

    for (int i=0; i<res->line; i++) {
        double value = Matrix_get(matrixY, i,0);
        for(int k=0; k<i; k++) {
            value -= Matrix_get(matrixL, i, k) * Matrix_get(res, k, 0);
        }
        value /= Matrix_get(matrixL, i, i);
        Matrix_set(res, i, 0, value);
    }

    return res;
}

Matrix* newBS(Matrix* matrixU, Matrix* matrixY) {
    Matrix* res = newZeroMatrix(matrixU->line, 1);

    for (int i=(res->line-1); i>=0; i--) {
        double value = Matrix_get(matrixY, i, 0);
        for(int k=i; k<res->line; k++) {
            value -= Matrix_get(res, k, 0) * Matrix_get(matrixU, i, k);
        }
        value /= Matrix_get(matrixU, i, i);
        Matrix_set(res, i, 0, value);
    }

    return res;
}

Matrix* newMatrix_getRowOf(Matrix* this, int row) {
    Matrix* res = newZeroMatrix(this->line, 1);
    for(int i=0; i<this->line; i++) {
        Matrix_set(res, i, 0, Matrix_get(this, i, row));
    }
    return res;
}

Matrix* newMatrix_inverse(Matrix* this) {
    // 単位行列をつくる
    Matrix* matrixI = newUnitMatrix(this->line, this->row);
    // this res = I　を解く
    Matrix* res = newMatrix_solve(this, matrixI);
    deleteMatrix(matrixI);
    return res;
}

Matrix* newMatrix_solve(Matrix* matrixA, Matrix* matrixY) {
    if (matrixA->row != matrixY->line) {
        printf("solve Error!");
        return NULL;
    }

    // LとUを求める
    Matrix* matrixL = newUnitMatrix(matrixA->line, matrixA->row);
    Matrix* matrixU = newZeroMatrix(matrixA->row, matrixA->line);
    for(int j=0; j<Matrix_getRow(matrixA); j++) {
        for(int i=0; i<Matrix_getLine(matrixA); i++) {
            double value = Matrix_get(matrixA, i, j);
            if (i<=j) {
                //uの計算
                for(int k=0; k<i; k++) {
                    value -= Matrix_get(matrixL, i, k) * Matrix_get(matrixU, k, j);
                }
                Matrix_set(matrixU, i, j, value);
            } else {
                //lの計算
                for(int k=0; k<j; k++) {
                    value -= Matrix_get(matrixL, i, k) * Matrix_get(matrixU, k, j);
                }
                value = value/Matrix_get(matrixU, j, j);
                Matrix_set(matrixL, i, j, value);
            }
        }
    }

    // LU分解に成功していることの確認
    Matrix* product = newMatrix_mlt(matrixL, matrixU);
    if (!Matrix_isEqual(matrixA, product)) {
        printf("Failed LU distribution!\n");
    }
    deleteMatrix(product);

    Matrix* res = newZeroMatrix(matrixY->line, matrixY->row);
    for(int i=0; i<Matrix_getRow(matrixY); i++) {
        // matrixYから、i列目を縦ベクトルを取り出す
        Matrix* vec = newMatrix_getRowOf(matrixY, i);

        Matrix* res1 = newFS(matrixL, vec);
        deleteMatrix(vec);
        Matrix* res2 = newBS(matrixU, res1);
        deleteMatrix(res1);
        // res2の結果をresのi列目としてコピー
        for(int j=0; j<vec->line; j++) {
            Matrix_set(res, j, i, Matrix_get(res2, j,0));
        }
        deleteMatrix(res2);
    }
    deleteMatrix(matrixL);
    deleteMatrix(matrixU);

    return res;
}
