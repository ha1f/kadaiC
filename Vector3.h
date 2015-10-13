#include <stdio.h>
#include <stdlib.h>

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

typedef struct{
    double vals[3];
} Vector3;


void Vector3_init(Vector3* this, double x, double y, double z);

double* Vector3_getVals(Vector3* this);

void Vector3_normalize(Vector3* this);

void Vector3_multiply(Vector3* this, double alpha);

double Vector3_length(Vector3* this);

double Vector3_distTo(Vector3* this, Vector3* target);

double Vector3_dotProduct(Vector3* this, Vector3* vec);

void deleteVector3(Vector3* this);

void Vector3_show(Vector3* this);

// staticがいい
Vector3* newVector3(double x, double y, double z);
#endif
