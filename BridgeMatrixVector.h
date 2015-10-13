/** MatrixとVectorの相互変換 */

#include "Matrix.h"
#include "Vector.h"

#ifndef _BRIDGE_MATRIX_VECTOR_H_
#define _BRIDGE_MATRIX_VECTOR_H_

// 使い終わったやつの削除もしてくれる
Vector* newVectorFromMatrix(Matrix* matrix);
Matrix* newMatrixFromVector(Vector* vector);

#endif
