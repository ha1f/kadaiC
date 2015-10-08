/** Vector.h */

#include <stdbool.h>

typedef struct {
    int dim;
    double* components;
} Vector;

bool Vector_isHomo(Vector* vec1, Vector* vec2);
Vector* newVector(int dim, double* vals);
void deleteVector(Vector* this);
double* Vector_getComponents(Vector* this);
int Vector_getDim(Vector* this);
double Vector_get(Vector* this, int index);
void Vector_set(Vector* this, int index, double value);
void Vector_multiply(Vector* this, double alpha);
double Vector_length(Vector* this);
void Vector_normalize(Vector* this);
void Vector_show(Vector* this);
double Vector_dotProduct(Vector* vec1, Vector* vec2);
double Vector_distTo(Vector* vec1, Vector* vec2);
void Vector_add(Vector* this, Vector* vec2);
