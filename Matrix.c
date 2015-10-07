#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int line;
    int row;
    double* components;
} Matrix;

void Matrix_init(Matrix* this, int line, int row, double *data) {
    this->line = line;
    this->row = row;
    this->components = malloc(sizeof(double) * line * row);
    for(int i=0; i<line; i++) {
        for(int j=0; j<row; j++) {
            this->components[i*row+j] = data[i*row+j];
        }
    }
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

void Matrix_delete(Matrix* this) {
    free(this->components);
    free(this);
}

void Matrix_show(Matrix* this) {
    printf("matrix\n");
    for(int i=0; i<this->line; i++) {
        for(int j=0; j<this->row; j++) {
            printf("%lf ", this->components[i*this->row+j]);
        }
        printf("\n");
    }
}

// 成分をget
double Matrix_get(Matrix* this, int x, int y) {
    if ((x >= this->line) || (y >= this->row)) {
        printf("Error! index out of range!");
        return 0;
    }
    return this->components[x * this->line + y];
}

// 成分をset
void Matrix_set(Matrix* this, int x, int y, double value) {
    this->components[x * this->line + y] = value;
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
Matrix* Matrix_newMultiplyProduct(Matrix* this, Matrix* matrix) {
    if ((this->row != matrix->line) || (this->line != matrix->row)){
        printf("Error! can't mutiply!");
        double dummy[1] = {0};
        return newMatrix(0, 0, dummy);
    }
    double res[matrix->row][this->line];
    for(int i=0; i < this->line ; i++) {
        for(int j=0; j < matrix->row; j++) {
            for(int k=0; k < this->row; k++) {
                res[i][j] = Matrix_get(this, i, k) * Matrix_get(this, k, j);
            }
        }
    }
    return newMatrix(matrix->row, this->line, res[0]);
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

int main() {
    Matrix* matrix = newMatrix(3, 3, (double []){
        1,0,0,
        0,1,0,
        0,0,1
    });
    Matrix_show(matrix);
    printf("%lf\n", Matrix_determinant(matrix));
    Matrix_delete(matrix);
    return 0;
}
