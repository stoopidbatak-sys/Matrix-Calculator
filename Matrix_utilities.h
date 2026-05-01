#ifndef MATRIX_UTILITIES_H
    #define MATRIX_UTILITIES_H

#include "fraction.h"
char variables[20] = {
    'x','y','z','w','v',
    'u','t','s','r','q',
    'p','o','n','m','l',
    'k','j','i','h','g'
};

enum class Operations {
    Transpose,
    Addition,
    Subtraction,
    Multiplication,
    Matrix_Power,
    Determinant,
    Inverse,
    Row_Echelon_Form,
    Reduced_row_Echelon_Form,
    Rank,
    Cramers_Rule,
    Inverse_Method,
    Guass_Jordon_Elimination,
    Exit,
};

void MainMenu();

void Features();

void SizeInput (int &rows, int &cols);

void SizeInput (int &size);

fraction* MatrixInput(int rows, int cols);

int InputChoice();

void Equations(double* Augmatrix, int rows, int cols);

Operations InputEnum(int choice);

void SwitchBody(const Operations &op);

#endif