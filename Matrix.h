typedef struct {
    int line;
    int row;
    double* components;
} Matrix;

#define MIN(a,b) ((a<b) ? a : b)

void Matrix_init(Matrix* this, int line, int row, double *data);
void Matrix_changeComponents(Matrix* this, double *data);
int Matrix_getLine(Matrix* this);
int Matrix_getRow(Matrix* this);
double* Matrix_getComponents(Matrix* this);
Matrix* newMatrix(int line, int row, double *data);
void Matrix_delete(Matrix* this);
void Matrix_show(Matrix* this);
double Matrix_get(Matrix* this, int x, int y);
void Matrix_set(Matrix* this, int x, int y, double value);
void Matrix_multiplyScalar(Matrix* this, double alpha);
Matrix* Matrix_mlt(Matrix* this, Matrix* matrix);
double Matrix_determinant(Matrix* this);
void Matrix_add(Matrix* this, Matrix* matrix);
void Matrix_sub(Matrix* this, Matrix* matrix);
