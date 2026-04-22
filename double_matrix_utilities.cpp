#include "double_matrix_utilities.h"
#include "double_matrix_features.h"

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
 

double* MatrixInput2 (int rows, int cols) {

    double *matrix = new double[rows*cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout<<"a ["<<i+1<<"] ["<<j+1<<"] : ";
            cin>>matrix[i*cols + j];        
        }
    }

    return matrix;
}

void DisplayMatrix (double* matrix, int rows, int cols) {
    cout<<" --";
    for (int i=0; i<7*cols; i++) 
        cout<<" ";
    cout<<"--"<<endl;

    for (int i=0; i<rows; i++) {
        cout<<"|";
        for (int j=0; j<cols; j++) {
            cout<<" "<<setw(5)<<matrix[i*cols+j]<<" ";
        }
        cout<<"    |"<<endl;
    }

    cout<<" --";
    for (int i=0; i<7*cols; i++) 
        cout<<" ";
    cout<<"--"<<endl;
}    

void DisplayAugmented (double* Augmatrix, int rows, int cols) {
    cout<<" --";
    for (int i=0; i<7*cols+5; i++) 
        cout<<" ";
    cout<<"--"<<endl;

    for (int i=0; i<rows; i++) {
        cout<<"|";
        for (int j=0; j<cols-1; j++) {
            cout<<" "<<setw(5)<<Augmatrix[i*cols+j]<<" ";
        }
        cout<<"    | "<<setw(5)<<Augmatrix[i*cols+cols-1]<<" ";
        cout<<"    |"<<endl;
    }

    cout<<" --";
    for (int i=0; i<7*cols+5; i++) 
        cout<<" ";
    cout<<"--"<<endl;
}

void DisplayInverse (double* matrix, double* inverse, int size) {
    DisplayMatrix(inverse, size, size);
    cout<<" --";
    for (int i=0; i<7*size; i++) 
        cout<<"-";
    cout<<"--"<<endl;
    for (int i=0; i<3*size+size/2+1; i++) 
        cout<<" ";
    double det = (double)Determinant(matrix, size);
    cout<<det<<endl;
}

void scalarMultiplication(double *matrix, int rows, int cols, double scalar) {
    for(int i=0; i<rows; i++) {
        scaledRow(matrix, cols, i+1, scalar);
    }
}

void scalarDivision(double *matrix, int rows, int cols, double scalar) {
    for(int i=0; i<rows; i++) {
        descaledRow(matrix, cols, i+1, scalar);
    }
}

double* Minor (double* matrix, int size, int row, int col) {
    double* cofactor = new double[(size-1)*(size-1)];
    int a=0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if (i==(row-1) || j==(col-1))
                continue;
            else {
                cofactor[a] = matrix[i*size+j];
                a++;
            }
        }
    }
    return cofactor;
}

double cofactor (double* minor, int size, int row, int col) {
    double cofactor = pow(-1, (row+col))*Determinant(minor, size);
    return cofactor;
}

void rowswap (double* matrix, int cols, int row1, int row2) {
    for(int i=0; i<cols; i++) {
        double temp = matrix[(row1-1)*cols+i];
        matrix[(row1-1)*cols+i] = matrix[(row2-1)*cols+i];
        matrix[(row2-1)*cols+i] = temp;
    }
}

void columnswap (double* matrix, int rows, int cols, int col1, int col2) {
    for(int i=0; i<rows; i++) {
        double temp = matrix[i*cols+(col1-1)];
        matrix[i*cols+(col1-1)] = matrix[i*cols+(col2-1)];
        matrix[i*cols+(col2-1)] = temp;
    }
}

void scaledRow (double* matrix, int cols, int row, double scalar) {
    for (int i=0; i<cols; i++) {
        matrix[(row-1)*cols+i] *= scalar;
    }
}

void scaledCol (double* matrix, int rows, int cols, int col, double scalar) {
    for (int i=0; i<rows; i++) {
        matrix[i*cols+(col-1)] *= scalar;
    }
}

void descaledRow (double* matrix, int cols, int row, double scalar) {
    for (int i=0; i<cols; i++) {
        matrix[(row-1)*cols+i] /= scalar;
    }
}

void descaledCol (double* matrix, int rows, int cols, int col, double scalar) {
    for (int i=0; i<rows; i++) {
        matrix[i*cols+(col-1)] /= scalar;
    }
}

void rowaddition (double* matrix, int cols, int rowout, int rowin, double scalar) {
    for (int i=0; i<cols; i++) {
        matrix[(rowout-1)*cols+i] += matrix[(rowin-1)*cols+i]*scalar; 
    }
}

double* AugmentedMatrix(double* Coffmatrix, double* Constmatrix, int equations, int variables) {
    double* AugMatrix = new double[equations*(variables + 1)];
    for (int i=0; i<equations; i++) {
        for(int j=0; j<variables+1; j++) {
            if(j == variables)
                AugMatrix[i*(variables+1)+j] = Constmatrix[i];
            else 
                AugMatrix[i*(variables+1)+j] = Coffmatrix[i*variables + j]; 
        }
    }
        
    return AugMatrix;
}
    
int rowtoLeadingPlace (double* Echelonform, int cols, int input_row) {
    int leadingplace = 0;
    for (int i=0; i<cols-1; i++) {
        if (Echelonform[(input_row-1)*cols+i] != 0) {
            leadingplace = i+1;
            break;
        }
    }
    return leadingplace;
}

int leadingPlacetoRow (double* Echelonform, int Rank, int cols, int LeadingPlace) {
    for(int i=0; i<Rank; i++) {
        if(rowtoLeadingPlace(Echelonform, cols, i+1) == LeadingPlace)
        return i+1;
    }
}

bool* freeVariables (double* reducedEchelonform, int Rank, int cols) {
    bool* free_variables = new bool[cols-1];
    for (int i=0; i<cols-1; i++) {
        free_variables[i] = true;
    }
    
    for(int i=0; i<Rank; i++) {
        free_variables[rowtoLeadingPlace(reducedEchelonform, cols, i+1)-1] = false;
    }
    
    return free_variables;
}

bool Inconsistency_check(double* reducedEchelonform, int Rank, int rows, int cols) {
    bool check = false;
    for(int i=Rank; i<rows; i++) {
        if(reducedEchelonform[i*cols + cols-1] != 0) {
            check = true;
            break;
        }
    }
    return check;
}

double* RandomMatrix (int rows, int cols) {
    double* temp = new double[rows*cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            temp[i*cols+j] = rand()%15-6;
        }
    }
    return temp;
}

double* IdentityGenerator(int size) {
    double* temp = new double[size*size];
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(i==j)
                temp[i*size + j] = 1;
            else
                temp[i*size + j] = 0;
        }
    }
    return temp;
}

void MatrixCleanup (double* matrix, int rows, int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (abs(matrix[i*cols+j])<0.00001)
                matrix[i*cols+j]=0;
        }
    }
}

double* Copy(double* matrix, int rows, int cols) {
    double* temp = new double[rows*cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            temp[i*cols+j] = matrix[i*cols+j];
        }
    }
    return temp;
}