#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "Vector.h"

bool Vector_isHomo(Vector* vec1, Vector* vec2) {
    return (vec1->dim == vec2->dim);
}

Vector* newVector(int dim, double* vals) {
    Vector* vec = malloc(sizeof(Vector));
    vec->dim = dim;
    vec->components = malloc(sizeof(double) * dim);

    memcpy(vec->components, vals, sizeof(double) * dim);
    return vec;
}

void deleteVector(Vector* this) {
    free(this->components);
    free(this);
}

double* Vector_getComponents(Vector* this) {
    return this->components;
}

int Vector_getDim(Vector* this) {
    return this->dim;
}

double Vector_get(Vector* this, int index) {
    if (index >= this->dim) {
        printf("Error! index out of range!");
        return 0;
    }
    return this->components[index];
}

void Vector_set(Vector* this, int index, double value) {
    if (index >= this->dim) {
        printf("Error! index out of range!");
        return;
    }
    this->components[index] = value;
}

//実数倍
void Vector_multiply(Vector* this, double alpha) {
    for(int i=0; i < this->dim; i++) {
        this->components[i] *= alpha;
    }
}

//長さを取得
double Vector_length(Vector* this) {
    double res=0;
    for(int i=0; i < this->dim; i++) {
        res += pow(this->components[i],2);
    }
    return sqrt(res);
}

// 正規化
void Vector_normalize(Vector* this) {
    Vector_multiply(this, 1.0/(Vector_length(this)));
    return;
}

// 描画
void Vector_show(Vector* this) {
    printf("[");
    for(int i=0; i < this->dim; i++) {
        printf("%lf, ", this->components[i]);
    }
    printf("]\n");
}

//内積
double Vector_dotProduct(Vector* vec1, Vector* vec2) {
    if (!Vector_isHomo(vec1, vec2)) {
        printf("Not same dimention!");
        return -1;
    }

    double res=0;
    for(int i=0; i < vec1->dim; i++) {
        res += vec1->components[i] * vec2->components[i];
    }
    return res;
}

//距離
double Vector_distTo(Vector* vec1, Vector* vec2) {
    if (!Vector_isHomo(vec1, vec2)) {
        printf("Not same dimention!");
        return -1;
    }

    double dist2 = 0;
    for(int i=0; i < vec1->dim; i++) {
        dist2 += pow((vec1->components[i] - vec2->components[i]),2);
    }
    return sqrt(dist2);
}

void Vector_add(Vector* this, Vector* vec2) {
    if (!Vector_isHomo(this, vec2)) {
        printf("Not same dimention!");
        return;
    }
    for(int i=0; i < this->dim; i++) {
        this->components[i] += vec2->components[i];
    }
}
