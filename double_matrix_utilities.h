#ifndef DOUBLE_MATRIX_UTILITIES_H
    #define DOUBLE_MATRIX_UTILITIES_H

#include "fraction.h"

double* Fraction_to_Double_Matrix (fraction* matrix, int rows, int cols);

void DisplayMatrix (double* matrix, int rows, int cols);
void DisplayInverse (double* matrix, double* inverse, int size);

void Equations(double* Augmatrix, int rows, int cols);

void scalarMultiplication(double *matrix, int rows, int cols, double scalar);
void scalarDivision(double *matrix, int rows, int cols, double scalar);

double* Minor (double* matrix, int size, int row, int col);
double cofactor (double* minor, int size, int row, int col);

void rowswap (double* matrix, int cols, int row1, int row2);
void columnswap (double* matrix, int rows, int cols, int col1, int col2);
void scaledRow (double* matrix, int cols, int row, double scalar);
void scaledCol (double* matrix, int rows, int cols, int col, double scalar);
void descaledRow (double* matrix, int cols, int row, double scalar);
void descaledCol (double* matrix, int rows, int cols, int col, double scalar);
void rowaddition (double* matrix, int cols, int rowout, int rowin, double scalar);

double* AugmentedMatrix(double* Coffmatrix, double*Constmatrix, int equations, int variables);
void DisplayAugmented (double* Augmatrix, int rows, int cols);

int rowtoLeadingPlace (double* Echelonform, int cols, int input_row);
int leadingPlacetoRow (double* Echelonform, int Rank, int cols, int leadingPlace);
bool* freeVariables (double* reducedEchelonform, int Rank, int cols);
bool Inconsistency_check(double* reducedEchelonform, int Rank, int rows, int cols);

void MatrixCleanup (double* matrix, int rows, int cols);
double* Copy(double* matrix, int rows, int cols);

#endif