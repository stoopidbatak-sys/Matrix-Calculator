#include "config.h"
#include "fraction_matrix_features.h"
#include "fraction_matrix_utilities.h"
#include "basic_utilities.h"
#include "matrix_utilities.h"
#include "fraction.h"

#include <iostream>
#include <cmath>
using namespace std;

namespace Fraction {

    fraction* Transpose (fraction *matrix, int rows, int cols) {
        
        fraction *result = new fraction[rows*cols];
        
        for (int i=0; i<cols; i++) {
            for (int j=0; j<rows; j++) {
                result[i*rows+j] = matrix[j*cols+i];
            }
        }
        
        return result;
    }

    fraction* Addition (fraction *matrix1, fraction *matrix2, int rows, int cols) {

        fraction *result = new fraction[rows*cols];

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                result[i*cols+j] = matrix1[i*cols+j] + matrix2[i*cols+j];
            }
        }

        return result;
    }

    fraction* Subtraction (fraction*matrix1, fraction*matrix2, int rows, int cols) {
        fraction*result = new fraction[rows*cols];

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                result[i*cols+j] = matrix1[i*cols+j] - matrix2[i*cols+j];
            }
        }

        return result;
    }

    fraction* Multiplication (fraction *matrix1, fraction *matrix2, int rows1, int cols1, int rows2, int cols2) {  
        fraction *result = new fraction[rows1*cols2];

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

    fraction* PowerMatrix(fraction* matrix, int size, int power) {
        fraction* result = Copy(matrix, size, size);

        for (int i = 1; i < power; i++) {
            fraction* temp = Multiplication(result, matrix, size, size, size, size);
            delete[] result;
            result = temp;
        }

        return result;
    }

    fraction* Inverse (fraction* matrix, int size) {
        fraction* temp = new fraction[size*size];
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                fraction* minor = Minor(matrix, size, i+1, j+1);
                temp[i*size+j] = cofactor(minor, size-1, i+1, j+1);
                delete[] minor;
            }
        }
        fraction* result = Transpose(temp, size, size);
        delete[] temp; 

        fraction determinant = Determinant(matrix, size);
        scalarDivision(result, size, size, determinant);
        return result;
    }

    fraction Determinant (fraction* matrix, int size) {
        int rowswaps = 0;
        fraction* copy = Copy(matrix, size, size);
        fraction factor = DeterminantSimplifier(copy, size);
        fraction* temp = rowEchelon(copy, size, size, rowswaps);
        fraction determinant = 1;
        for (int i=0; i<size; i++) {
            determinant *= temp[i*size+i];
        }
        delete[] copy;
        delete[] temp;
        copy = nullptr;
        temp = nullptr;
        determinant *= pow(-1, rowswaps);
        determinant *= factor;
        return determinant;
    }

    fraction* rowEchelon (fraction* matrix, int rows, int cols, int &rowswaps) {
        fraction* temp = Copy(matrix, rows, cols);
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
                fraction scalar = -temp[(i+j+1)*cols + i+column_pivot_shift]/temp[i*cols+i+column_pivot_shift];
                rowaddition (temp, cols, i+1+j+1, i+1, scalar);
            }
        }

        return temp;
    }

    fraction* reducedEchelon (fraction* matrix, int rows, int cols, int &rowswaps) {
        fraction* temp = rowEchelon(matrix, rows, cols, rowswaps);

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
                fraction scalar = -temp[(i-1-j)*cols+i+column_pivot_shift]/temp[i*cols+i+column_pivot_shift];
                rowaddition(temp, cols, i-j, i+1, scalar);
            }
        }

        return temp;
    }

    int Rank (fraction *matrix, int rows, int cols) {
        int rowswaps = 0;
        fraction *Echelonform = rowEchelon(matrix, rows, cols, rowswaps);
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

    #if DEV_MODE
    
        void CramersRule(fraction*Coffmatrix, fraction*Constmatrix, int size) {
            fraction *temp = new fraction[size*size];
            fraction matrixdet = Determinant(Coffmatrix, size);
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
                    fraction solution = Determinant(temp, size);
                    solution /= matrixdet;
                    cout<<::variables[i]<<" = "<<solution<<endl;
                    a++;
            }

            delete[] temp;
        }

        void InverseMethod (fraction*Coffmatrix, fraction*Constmatrix, int size) {
            fraction det = Determinant(Coffmatrix, size);
            if(det == 0) {
                cout<<"Singular Matrix!"<<endl;
                return;
            }
            fraction*inverse = Inverse(Coffmatrix, size);
            fraction*product = Multiplication(inverse, Constmatrix, size, size, size, 1);

            fraction solution;
            for(int i=0; i<size; i++) {
                solution = product[i] / det;
                cout<<::variables[i]<<" = "<<solution<<endl;
            }

            delete[] inverse;
            delete[] product;
        }

    #endif

    void Guass_Jordan_Elimination (fraction *Coffmatrix, fraction* Constmatrix, int equations, int variables) {
        int rank = Rank(Coffmatrix, equations, variables);

        fraction* Augmatrix = AugmentedMatrix(Coffmatrix, Constmatrix, equations, variables);
        int rows = equations;
        int cols = variables+1; 

        int rowswaps = 0;
        fraction* reducedEchelonform = reducedEchelon(Augmatrix, rows, cols, rowswaps);

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
                            if(reducedEchelonform[row*cols + j].getNum() < 0)
                                cout<<" + "<<-reducedEchelonform[row*cols + j].getNum()<<"("<<::variables[j]<<")";
                            else 
                                cout<<" - "<<reducedEchelonform[row*cols + j].getNum()<<"("<<::variables[j]<<")";
                            if(reducedEchelonform[row*cols + j].getDen() != 1)
                                cout<<"/"<<reducedEchelonform[row*cols + j].getDen();
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