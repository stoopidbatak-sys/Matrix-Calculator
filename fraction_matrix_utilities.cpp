#include "fraction_matrix_utilities.h"
#include "fraction_matrix_features.h"
#include "Matrix_utilities.h"

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

fraction* Double_to_Fraction_Matrix(double* matrix, int rows, int cols) {
    fraction* temp = new fraction[rows*cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            temp[i*cols+j] = matrix[i*cols+j];
        }
    }
    return temp;
}

void DisplayMatrix (fraction* matrix, int rows, int cols) {
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

void DisplayAugmented (fraction* Augmatrix, int rows, int cols) {
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

void Equations(fraction* Augmatrix, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        cout<<Augmatrix[i*cols]<<::variables[0];
        for(int j=1; j<cols-1; j++) {
            if(Augmatrix[i*cols+j] < 0)
                cout<<" - "<<-Augmatrix[i*cols+j]<<::variables[j];
            else 
                cout<<" + "<<Augmatrix[i*cols+j]<<::variables[j];
        }
        cout<<" = "<<Augmatrix[i*cols+cols-1]<<endl;
    }
}

void scalarMultiplication(fraction *matrix, int rows, int cols, fraction scalar) {
    for(int i=0; i<rows; i++) {
        scaledRow(matrix, cols, i+1, scalar);
    }
}

void scalarDivision(fraction *matrix, int rows, int cols, fraction scalar) {
    for(int i=0; i<rows; i++) {
        descaledRow(matrix, cols, i+1, scalar);
    }
}

fraction* Minor (fraction* matrix, int size, int row, int col) {
    fraction* cofactor = new fraction[(size-1)*(size-1)];
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

fraction cofactor (fraction* minor, int size, int row, int col) {
    fraction cofactor = pow(-1, (row+col))*Fraction :: Determinant(minor, size);
    return cofactor;
}

void rowswap (fraction* matrix, int cols, int row1, int row2) {
    for(int i=0; i<cols; i++) {
        fraction temp = matrix[(row1-1)*cols+i];
        matrix[(row1-1)*cols+i] = matrix[(row2-1)*cols+i];
        matrix[(row2-1)*cols+i] = temp;
    }
}

void columnswap (fraction* matrix, int rows, int cols, int col1, int col2) {
    for(int i=0; i<rows; i++) {
        fraction temp = matrix[i*cols+(col1-1)];
        matrix[i*cols+(col1-1)] = matrix[i*cols+(col2-1)];
        matrix[i*cols+(col2-1)] = temp;
    }
}

void scaledRow (fraction* matrix, int cols, int row, fraction scalar) {
    for (int i=0; i<cols; i++) {
        matrix[(row-1)*cols+i] *= scalar;
    }
}

void scaledCol (fraction* matrix, int rows, int cols, int col, fraction scalar) {
    for (int i=0; i<rows; i++) {
        matrix[i*cols+(col-1)] *= scalar;
    }
}

void descaledRow (fraction* matrix, int cols, int row, fraction scalar) {
    for (int i=0; i<cols; i++) {
        matrix[(row-1)*cols+i] /= scalar;
    }
}

void descaledCol (fraction* matrix, int rows, int cols, int col, fraction scalar) {
    for (int i=0; i<rows; i++) {
        matrix[i*cols+(col-1)] /= scalar;
    }
}

void rowaddition (fraction* matrix, int cols, int rowout, int rowin, fraction scalar) {
    for (int i=0; i<cols; i++) {
        matrix[(rowout-1)*cols+i] += matrix[(rowin-1)*cols+i]*scalar; 
    }
}

fraction* AugmentedMatrix(fraction* Coffmatrix, fraction* Constmatrix, int equations, int variables) {
    fraction* AugMatrix = new fraction[equations*(variables + 1)];
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
    
int rowtoLeadingPlace (fraction* Echelonform, int cols, int input_row) {
    int leadingplace = 0;
    for (int i=0; i<cols-1; i++) {
        if (Echelonform[(input_row-1)*cols+i] != 0) {
            leadingplace = i+1;
            break;
        }
    }
    return leadingplace;
}

int leadingPlacetoRow (fraction* Echelonform, int Rank, int cols, int LeadingPlace) {
    for(int i=0; i<Rank; i++) {
        if(rowtoLeadingPlace(Echelonform, cols, i+1) == LeadingPlace)
        return i+1;
    }
}

bool* freeVariables (fraction* reducedEchelonform, int Rank, int cols) {
    bool* free_variables = new bool[cols-1];
    for (int i=0; i<cols-1; i++) {
        free_variables[i] = true;
    }
    
    for(int i=0; i<Rank; i++) {
        free_variables[rowtoLeadingPlace(reducedEchelonform, cols, i+1)-1] = false;
    }
    
    return free_variables;
}

bool Inconsistency_check(fraction* reducedEchelonform, int Rank, int rows, int cols) {
    bool check = false;
    for(int i=Rank; i<rows; i++) {
        if(reducedEchelonform[i*cols + cols-1] != 0) {
            check = true;
            break;
        }
    }
    return check;
}

fraction* RandomMatrix (int rows, int cols) {
    fraction* temp = new fraction[rows*cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            temp[i*cols+j].Set(rand()%15-6, rand()%15-6);
        }
    }
    return temp;
}

fraction* IdentityGenerator(int size) {
    fraction* temp = new fraction[size*size];
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

fraction* Copy(fraction* matrix, int rows, int cols) {
    fraction* temp = new fraction[rows*cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            temp[i*cols+j] = matrix[i*cols+j];
        }
    }
    return temp;
}