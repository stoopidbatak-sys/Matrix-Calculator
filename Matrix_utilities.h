#ifndef MATRIX_UTILITIES_H
    #define MATRIX_UTILITIES_H

#include "fraction.h"
extern char variables[20];

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

Operations InputEnum(int choice);

void SwitchBody(const Operations &op);

#endif