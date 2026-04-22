#ifndef FRACTION_MATRIX_FEATURES_H
    #define FRACTION_MATRIX_FEATURES_H

fraction* Transpose (fraction *matrix, int rows, int cols);

fraction* Addition (fraction *matrix1, fraction *matrix2, int rows, int cols);

fraction* Subtraction (fraction*matrix1, fraction*matrix2, int rows, int cols);

fraction* Multiplication (fraction *matrix1, fraction *matrix2, int rows1, int cols1, int rows2, int cols2);

fraction* PowerMatrix(fraction* matrix, int size, int power);

fraction* Inverse (fraction* matrix, int size);

long long Determinant (fraction *matrix, int size);

fraction* rowEchelon (fraction* matrix, int rows, int cols, int &rowswaps);

fraction* reducedEchelon (fraction* matrix, int rows, int cols, int &rowswaps);

int Rank (fraction *matrix, int rows, int cols);

void CramersRule(fraction *Coffmatrix, fraction *Constmatrix, int size); 

void InverseMethod (fraction *Coffmatrix, fraction *Constmatrix, int size);

void Guass_Jordan_Elimination (fraction *Coffmatrix, fraction* Constmatrix, int equations, int variables);

#endif