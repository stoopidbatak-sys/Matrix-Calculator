#ifndef FRACTION_MATRIX_UTILITIES_H
    #define FRACTION_MATRIX_UTILITIES_H

#include "fraction.h"

fraction* Double_to_Fraction_Matrix(double* matrix, int rows, int cols);

void Equations(fraction* Augmatrix, int rows, int cols);
void EquationSimplifier(fraction* Coffmatrix, fraction* Constmatrix, int equations, int variables);

fraction DeterminantSimplifier (fraction* matrix, int size);

void scalarMultiplication(fraction *matrix, int rows, int cols, fraction scalar);
void scalarDivision(fraction *matrix, int rows, int cols, fraction scalar);

fraction* Minor (fraction* matrix, int size, int row, int col);
fraction cofactor (fraction* minor, int size, int row, int col);

fraction* getRow (fraction* matrix, int cols, int row);
fraction rowfactor(fraction* row, int cols);

void rowswap (fraction* matrix, int cols, int row1, int row2);
void columnswap (fraction* matrix, int rows, int cols, int col1, int col2);
void scaledRow (fraction* matrix, int cols, int row, fraction scalar);
void scaledCol (fraction* matrix, int rows, int cols, int col, fraction scalar);
void descaledRow (fraction* matrix, int cols, int row, fraction scalar);
void descaledCol (fraction* matrix, int rows, int cols, int col, fraction scalar);
void rowaddition (fraction* matrix, int cols, int rowout, int rowin, fraction scalar);

fraction* AugmentedMatrix(fraction* Coffmatrix, fraction*Constmatrix, int equations, int variables);

int rowtoLeadingPlace (fraction* Echelonform, int cols, int input_row);
int leadingPlacetoRow (fraction* Echelonform, int Rank, int cols, int leadingPlace);
bool* freeVariables (fraction* reducedEchelonform, int Rank, int cols);
bool Inconsistency_check(fraction* reducedEchelonform, int Rank, int rows, int cols);

fraction* RandomMatrix (int rows, int cols);
fraction* IdentityGenerator (int size);
fraction* Copy(fraction* matrix, int rows, int cols);

#endif