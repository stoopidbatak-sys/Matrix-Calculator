#ifndef DOUBLE_MATRIX_FEATURES_H
    #define DOUBLE_MATRIX_FEATURES_H

    #include "config.h"

    namespace Double { 

        
        double* Transpose (double *matrix, int rows, int cols);
        
        #if DEV_MODE 

            double* Addition (double *matrix1, double *matrix2, int rows, int cols);

            double* Subtraction (double *matrix1, double *matrix2, int rows, int cols);

        #endif

            double* Multiplication (double *matrix1, double *matrix2, int rows1, int cols1, int rows2, int cols2);

        #if DEV_MODE

            double* PowerMatrix(double* matrix, int size, int power);
            
        #endif
        
        double* Inverse (double* matrix, int size);

        long long Determinant (double *matrix, int size);

        double* rowEchelon (double* matrix, int rows, int cols, int &rowswaps);

        #if DEV_MODE

            double* reducedEchelon (double* matrix, int rows, int cols, int &rowswaps);

        #endif

        int Rank (double *matrix, int rows, int cols);

        void CramersRule(double *Coffmatrix, double *Constmatrix, int size); 

        void InverseMethod (double *Coffmatrix, double *Constmatrix, int size);

        #if DEV_MODE

            void Guass_Jordan_Elimination (double *Coffmatrix, double* Constmatrix, int equations, int variables);

        #endif
    }

#endif