#ifndef DOUBLE_MATRIX_FEATURES_H
    #define DOUBLE_MATRIX_FEATURES_H

double* Transpose (double *matrix, int rows, int cols);

double* Addition (double *matrix1, double *matrix2, int rows, int cols);

double* Subtraction (double *matrix1, double *matrix2, int rows, int cols);

double* Multiplication (double *matrix1, double *matrix2, int rows1, int cols1, int rows2, int cols2);

double* PowerMatrix(double* matrix, int size, int power);

double* Inverse (double* matrix, int size);

long long Determinant (double *matrix, int size);

double* rowEchelon (double* matrix, int rows, int cols, int &rowswaps);

double* reducedEchelon (double* matrix, int rows, int cols, int &rowswaps);

int Rank (double *matrix, int rows, int cols);

void CramersRule(double *Coffmatrix, double *Constmatrix, int size); 

void InverseMethod (double *Coffmatrix, double *Constmatrix, int size);

void Guass_Jordan_Elimination (double *Coffmatrix, double* Constmatrix, int equations, int variables);

#endif