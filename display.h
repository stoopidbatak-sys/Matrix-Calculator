#ifndef DISPLAY_H
    #define DISPLAY_H

    #include "config.h"
    #include "fraction.h"

    int numLength(const long long &num);   

    int fractionLength(const fraction &obj);

    int max_length_Column(fraction* matrix, int rows, int cols, int column);

    int* max_length_Columns_array(fraction* matrix, int rows, int cols);

    int length_array_Sum (int* array, int cols);

    void DisplayMatrix (fraction* matrix, int rows, int cols);

    void DisplayAugmented (fraction* Augmatrix, int equations, int variables);

    #if DEV_MODE
        void DisplayMatrix(double* matrix, int rows, int cols);

        void DisplayAugmented (double* Augmatrix, int rows, int cols);

        void DisplayInverse (double* matrix, double* inverse, int size);
    #endif

#endif