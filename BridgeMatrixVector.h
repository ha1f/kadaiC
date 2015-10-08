#include "Matrix.h"
#include "Vector.h"

#ifndef _BRIDGE_MATRIX_VECTOR_H_
#define _BRIDGE_MATRIX_VECTOR_H_

Vector* newVectorFromMatrix(Matrix* matrix);
Matrix* newMatrixFromVector(Vector* vector);

#endif
