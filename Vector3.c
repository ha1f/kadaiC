#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Vector3.h"

void Vector3_init(Vector3* this, double x, double y, double z) {
    this->vals[0] = x;
    this->vals[1] = y;
    this->vals[2] = z;
    return;
}

double* Vector3_getVals(Vector3* this) {
    return this->vals;
}

Vector3* newVector3(double x, double y, double z) {
    Vector3* this = malloc(sizeof(Vector3));
    Vector3_init(this, x, y, z);
    return this;
}

void deleteVector3(Vector3* this) {
    free(this);
}

//実数倍
void Vector3_multiply(Vector3* this, double alpha) {
    for(int i=0; i<3; i++) {
        this->vals[i] *= alpha;
    }
}

//長さを取得
double Vector3_length(Vector3* this) {
    return sqrt(pow(this->vals[0],2) + pow(this->vals[1],2) + pow(this->vals[2],2));
}

// 正規化
void Vector3_normalize(Vector3* this) {
    Vector3_multiply(this, 1.0/(Vector3_length(this)));
    return;
}

// 描画
void Vector3_show(Vector3* this) {
    printf("Vector3(%lf, %lf, %lf)",this->vals[0], this->vals[1], this->vals[2]);
    return;
}

//内積
double Vector3_dotProduct(Vector3* this, Vector3* vec) {
    return (this->vals[0]*vec->vals[0] + this->vals[1]*vec->vals[1] + this->vals[2]*vec->vals[2]);
}

//距離
double Vector3_distTo(Vector3* this, Vector3* target) {
    return pow((this->vals[0]-target->vals[0]), 2) + pow((this->vals[1]-target->vals[1]), 2) + pow((this->vals[2]-target->vals[2]), 2);
}
