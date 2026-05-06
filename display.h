#ifndef DISPLAY_H
    #define DISPLAY_H

#include "fraction.h"

int numLength(const long long &num);   

int fractionLength(const fraction &obj);

int max_length_Column(fraction* matrix, int rows, int cols, int column);

int* max_length_Columns_array(fraction* matrix, int rows, int cols);

int length_array_Sum (int* array, int cols);

void DisplayMatrix (fraction* matrix, int rows, int cols);

#endif