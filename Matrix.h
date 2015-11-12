#include <stdbool.h>

#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef struct {
    int line;
    int row;
    double* components;
} Matrix;

/** コンストラクタ、デストラクタ、イニシャライザ */
Matrix* newMatrix(int line, int row, double *data);
void Matrix_init(Matrix* this, int line, int row, double *data);
void deleteMatrix(Matrix* this);
Matrix* newZeroMatrix(int line, int row);
Matrix* newUnitMatrix(int line, int row);

Matrix* newFS(Matrix* matrixL, Matrix* matrixY);
Matrix* newBS(Matrix* matrixU, Matrix* matrixY);
// row列目を縦ベクトルとして取り出す
Matrix* newMatrix_getRowOf(Matrix* matrix, int row);
// LU分解を用いて、Ax = Yのxを求める
Matrix* newMatrix_solve(Matrix* matrixA, Matrix* matrixY);
// LU分解を用いて、逆行列を求める
Matrix* newMatrix_inverse(Matrix* this);

/** 表示 */
//行列表示
void Matrix_show(Matrix* this);
//ベクトルみたいに
void Matrix_showFlat(Matrix* this);

//get
double* Matrix_getComponents(Matrix* this);
int Matrix_getLine(Matrix* this);
int Matrix_getRow(Matrix* this);
double Matrix_get(Matrix* this, int x, int y);

/** 計算 */
//行列式
double Matrix_determinant(Matrix* this);
//和・差
void Matrix_add(Matrix* this, Matrix* matrix);
void Matrix_sub(Matrix* this, Matrix* matrix);
//積
void Matrix_multiplyScalar(Matrix* this, double alpha);
//行列積（newなので注意）
Matrix* newMatrix_mlt(Matrix* this, Matrix* matrix);

/** 編集 */
// 転置行列にする
void Matrix_transpose(Matrix* this);
// 値をまとめて書き換え、領域をリユース
void Matrix_changeComponents(Matrix* this, double *data);
//成分ごとに書き換え
void Matrix_set(Matrix* this, int x, int y, double value);

/** その他 */
// 行数か列数どちらかが1ならベクトルと判定
bool Matrix_isVector(Matrix* this);
// 対称行列かどうか
bool Matrix_isSymmetric(Matrix* this);
// すべての成分が等しいかどうか
bool Matrix_isEqual(Matrix* m1, Matrix* m2);

#endif
