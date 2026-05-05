#include "double_matrix_features.h"
#include "double_matrix_utilities.h"
#include "basic_utilities.h"
#include "Matrix_utilities.h"

#include <iostream>
#include <cmath>
using namespace std;

namespace Double {

    double* Transpose (double *matrix, int rows, int cols) {
        
        double *result = new double[rows*cols];
        
        for (int i=0; i<cols; i++) {
            for (int j=0; j<rows; j++) {
                result[i*rows+j] = matrix[j*cols+i];
            }
        }
        
        return result;
    }

    double* Addition (double *matrix1, double *matrix2, int rows, int cols) {

        double *result = new double[rows*cols];

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                result[i*cols+j] = matrix1[i*cols+j] + matrix2[i*cols+j];
            }
        }

        return result;
    }

    double* Subtraction (double *matrix1, double *matrix2, int rows, int cols) {
        double *result = new double[rows*cols];

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                result[i*cols+j] = matrix1[i*cols+j] - matrix2[i*cols+j];
            }
        }

        return result;
    }

    double* Multiplication (double *matrix1, double *matrix2, int rows1, int cols1, int rows2, int cols2) {  
        double *result = new double[rows1*cols2];

        for (int i=0; i<cols2; i++) {
            for (int j=0; j<rows1; j++) {
                result[j*cols2+i] = 0;
                for (int k=0; k<cols1; k++) {
                    result[j*cols2+i] += matrix1[j*cols1+k]*matrix2[k*cols2+i];
                }
            }
        }

        return result;
    }

    double* PowerMatrix(double* matrix, int size, int power) {
        double* result = Copy(matrix, size, size);

        for (int i = 1; i < power; i++) {
            double* temp = Multiplication(result, matrix, size, size, size, size);
            delete[] result;
            result = temp;
        }

        return result;
    }

    double* Inverse (double* matrix, int size) {
        double* temp = new double[size*size];
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                double* minor = Minor(matrix, size, i+1, j+1);
                temp[i*size+j] = cofactor(minor, size-1, i+1, j+1);
                delete[] minor;
            }
        }
        double* result = Transpose(temp, size, size);
        delete[] temp;
        return result;
    }

    long long Determinant (double* matrix, int size) {
        int rowswaps = 0;
        double* temp = rowEchelon(matrix, size, size, rowswaps);
        long double det = 1;
        for (int i=0; i<size; i++) {
            det *= temp[i*size+i];
        }
        delete[] temp;

        det *= pow(-1, rowswaps);
        long long determinant = (long long)(det + (det > 0? 0.5 : -0.5));
        return determinant;
    }

    double* rowEchelon (double* matrix, int rows, int cols, int &rowswaps) {
        double* temp = Copy(matrix, rows, cols);
        for (int i=0; i<rows-1; i++) {
            for (int j=0; j<rows-1-i; j++) {
                if (temp[j*cols]==0) {
                    rowswap(temp, cols, j+1, j+2);
                    rowswaps++;
                }
                else if (temp[j*cols] > temp[(j+1)*cols] && temp[(j+1)*cols] != 0) {
                    rowswap(temp, cols, j+1, j+2);
                    rowswaps++;
                }    
            }
        }

        int column_pivot_shift = 0;
        for (int i=0; i<rows-1; i++) {
            int row_pivot_shift = 0;
            while (temp[i*cols+i+column_pivot_shift]==0) {
                if(i+1+row_pivot_shift >= rows) {
                    column_pivot_shift++;
                    row_pivot_shift = 0;
                }
                else {
                    rowswap(temp, cols, i+1, i+2+row_pivot_shift);
                    rowswaps++;
                    row_pivot_shift++;
                }
                if(i+column_pivot_shift == cols) {
                    return temp;
                }
            } 
            for (int j=0; j<rows-1-i; j++) {
                double scalar = -temp[(i+j+1)*cols + i+column_pivot_shift]/temp[i*cols+i+column_pivot_shift];
                rowaddition (temp, cols, i+1+j+1, i+1, scalar);
            }
        }

        MatrixCleanup(temp, rows, cols);
        return temp;
    }

    double* reducedEchelon (double* matrix, int rows, int cols, int &rowswaps) {
        double* temp = rowEchelon(matrix, rows, cols, rowswaps);
        DisplayMatrix(temp, rows, cols);

        int column_pivot_shift;
        for(int i=rows-1; i>=0; i--) {
            column_pivot_shift = 0;
            while(temp[i*cols+i+column_pivot_shift]==0) {
                column_pivot_shift++;

                if(i+column_pivot_shift >= cols)
                    break;  
            }
            if(i+column_pivot_shift >= cols)
                continue;

            descaledRow(temp, cols, i+1, temp[i*cols+i+column_pivot_shift]);
            for(int j=0; j<i; j++) {
                double scalar = -temp[(i-1-j)*cols+i+column_pivot_shift]/temp[i*cols+i+column_pivot_shift];
                rowaddition(temp, cols, i-j, i+1, scalar);
            }
        }

        MatrixCleanup(temp, rows, cols);
        return temp;
    }

    int Rank (double *matrix, int rows, int cols) {
        int rowswaps = 0;
        double *Echelonform = rowEchelon(matrix, rows, cols, rowswaps);
        int rank = 0;
        bool zeroRow;
        for(int i=0; i<rows; i++) {
            zeroRow = true;
            for(int j=0; j<cols; j++) {
                if(Echelonform[i*cols+j] != 0) {
                    zeroRow = false;
                    break;
                }
            }
            if(!zeroRow)
                rank++;
        }

        delete[] Echelonform;
        return rank;
    }

    void CramersRule(double *Coffmatrix, double *Constmatrix, int size) {
        double *temp = new double[size*size];
        long long matrixdet = Determinant(Coffmatrix, size);
        long long num, den;
        if(matrixdet == 0) {
            cout<<"Singular Matrix!"<<endl;
            return;
        }
        int a=0;
        for(int i=0; i<size; i++) {
            for(int i=0; i<size; i++) {
                for(int j=0; j<size; j++) {
                    if(j==a) 
                        temp[i*size+j] = Constmatrix[i];
                    else
                        temp[i*size+j] = Coffmatrix[i*size+j];
                }
            }
                num = Determinant(temp, size);
                den = matrixdet;
                Simplifier(num, den);
                cout<<::variables[i]<<" = "<<num;
                if (den != 1)
                    cout<<"/"<<den<<endl;
                a++;
        }

        delete[] temp;
    }

    void InverseMethod (double *Coffmatrix, double *Constmatrix, int size) {
        long long det = Determinant(Coffmatrix, size);
        double *inverse = Inverse(Coffmatrix, size);
        double *product = Multiplication(inverse, Constmatrix, size, size, size, 1);

        long long num, den;
        for(int i=0; i<size; i++) {
            den = det;
            num = product[i];
            Simplifier(num, den);
            cout<<::variables[i]<<" = "<<num;
            if (den != 1)
                cout<<"/"<<den<<endl;
        }

        delete[] inverse;
        delete[] product;
    }

    void Guass_Jordan_Elimination (double *Coffmatrix, double* Constmatrix, int equations, int variables) {
        int rank = Rank(Coffmatrix, equations, variables);
        int rows = equations;
        int cols = variables+1;
        double* Augmatrix = AugmentedMatrix(Coffmatrix, Constmatrix, equations, variables);

        int rowswaps = 0;
        double* reducedEchelonform = reducedEchelon(Augmatrix, rows, cols, rowswaps);

        if(Inconsistency_check(reducedEchelonform, rank, rows, cols)) {
            cout<<"\nThe System is Inconsistent!"<<endl;
            return;
        }

        bool* free_variables = freeVariables(reducedEchelonform, rank, cols);
        for(int i=0; i<cols-1; i++) {
            if(free_variables[i]) {
                cout<<::variables[i]<<" = "<<"free variable"<<endl;
            }
            else {
                int row = leadingPlacetoRow(reducedEchelonform, rank, cols, i+1)-1;
                cout<<::variables[i]<<" = "<<reducedEchelonform[row*cols+cols-1];      
                for(int j=i+1; j<cols-1; j++) {
                    if(free_variables[j]) {
                        if(reducedEchelonform[row*cols + j] != 0) {
                            if(reducedEchelonform[row*cols + j] < 0)
                                cout<<" + "<<-reducedEchelonform[row*cols + j]<<"("<<::variables[j]<<")";
                            else 
                                cout<<" - "<<reducedEchelonform[row*cols + j]<<"("<<::variables[j]<<")";
                        }
                    }
                }
                cout<<endl;
            }
        }

        delete[] Augmatrix;
        delete[] reducedEchelonform;
        delete[] free_variables;
    }

}