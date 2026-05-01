#include "fraction.h"
#include "matrix_utilities.h"
#include "double_matrix_features.h"
#include "double_matrix_utilities.h"
#include "fraction_matrix_features.h"
#include "fraction_matrix_utilities.h"

#include <iostream>
using namespace std;

char variables[20] = {
    'x','y','z','w','v',
    'u','t','s','r','q',
    'p','o','n','m','l',
    'k','j','i','h','g'
};

void MainMenu() {
    cout<<"\n=======Welcome To Matrix Calculator=======\n"<<endl;

    cout<<"Perform any Matrix Operation you want But Before that!"<<endl;
    cout<<"A few things to Remember : "<<endl;
    cout<<"      1) The Calculator is still in Beta Version and is accurate upto 10 x 10 matrices"<<endl;
    cout<<"      2) The Input Mechanism works on fractions"<<endl;
    cout<<"      3) Enter Simplified Coefficients (integers) for Linear Equations"<<endl;
    cout<<"      4) If you have any suggestions or feedback, Dont feel free to Contact Us"<<endl<<endl;

    Features();
}

void Features() {
    cout<<"\nSelect Your Operation"<<endl;
    cout<<"1 --> Transpose"<<endl;
    cout<<"2 --> Addition"<<endl;
    cout<<"3 --> Subtraction"<<endl;
    cout<<"4 --> Multiplication"<<endl;
    cout<<"5 --> Matrix Power"<<endl;
    cout<<"6 --> Determinant"<<endl;
    cout<<"7 --> Inverse"<<endl;
    cout<<"8 --> Row Echelon Form"<<endl;
    cout<<"9 --> Reduced row Echelon Form"<<endl;
    cout<<"10 --> Rank of Matrix"<<endl;
    cout<<"11 --> Cramer's Rule"<<endl;
    cout<<"12 --> Inverse Method"<<endl;
    cout<<"13 --> Guass-Jordan Elimination"<<endl;
    cout<<"14 --> Exit"<<endl;
}

void SizeInput (int &rows, int &cols) {
    cout<<"Enter the Size of your Matrix : "<<endl;
    cout<<"Rows : ";
    cin>>rows;
    while (rows <= 0) {
        cout<<"Enter a Positive Integer!"<<endl;
        cout<<"Rows : ";
        cin>>rows;
    }
    cout<<"Columns : ";
    cin>>cols;
    while (cols <= 0) {
        cout<<"Enter a Positive Integer!"<<endl;
        cout<<"Columns : ";
        cin>>cols;
    }
    cout<<endl;
}

void SizeInput (int &size) {
    cout<<"Enter the Size of your Matrix : "<<endl;
    cout<<"Rows = Cols = ";
    cin>>size;
    while (size <= 0) {
        cout<<"Enter a Positive Integer!"<<endl;
        cout<<"Rows = Cols = : ";
        cin>>size;
    }
}

fraction* MatrixInput(int rows, int cols) {
    fraction *matrix = new fraction[rows*cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout<<"a ["<<i+1<<"] ["<<j+1<<"] : ";
            cin>>matrix[i*cols + j];        
        }
    }

    return matrix;
}

int InputChoice() {
    int choice;
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice < 1 || choice > 14) {
        cout<<"Invalid Input!"<<endl;
        cout<<"Input a number from 1-14 : ";    
        cin>>choice;
    }

    return choice;
}

Operations InputEnum(int choice) {
    Operations temp;
    switch(choice) {
        case 1 : 
            return Operations :: Transpose;

        case 2 : 
            return Operations :: Addition;

        case 3 : 
            return Operations :: Subtraction;

        case 4 : 
            return Operations :: Multiplication;

        case 5 : 
            return Operations :: Matrix_Power;

        case 6 : 
            return Operations :: Determinant;

        case 7 : 
            return Operations :: Inverse;

        case 8 :
            return Operations :: Row_Echelon_Form;

        case 9 : 
            return Operations :: Reduced_row_Echelon_Form;

        case 10 : 
            return Operations :: Rank;

        case 11 : 
            return Operations :: Cramers_Rule;

        case 12 : 
            return Operations :: Inverse_Method;

        case 13 : 
            return Operations :: Guass_Jordon_Elimination;

        case 14 : 
            return Operations :: Exit;
    }
}

void SwitchBody(const Operations &op) {
    switch(op) {
        case Operations :: Transpose : {
            cout<<"\n=====Operation Selected : Transpose====="<<endl<<endl; 

            cout<<"---Enter the Size of your Matrix---"<<endl;
            int rows, cols;
            SizeInput(rows, cols);

            cout<<"\n---Enter matrix Elements---"<<endl;
            fraction* matrixinput = MatrixInput(rows, cols);
            cout<<"\nInput Matrix :"<<endl;
            DisplayMatrix(matrixinput, rows, cols);

            fraction* result = Fraction :: Transpose(matrixinput, rows, cols);
            cout<<"\nResult :"<<endl;
            DisplayMatrix(result, rows, cols);

            delete[] matrixinput;
            delete[] result;
            matrixinput =  nullptr;
            result = nullptr;
            break;
        }

        case Operations :: Addition : {
            cout<<"\n=====Operation Selected : Addition====="<<endl<<endl; 

            cout<<"---Enter the Size of your Matrices---"<<endl;
            int rows, cols;
            SizeInput(rows, cols);

            cout<<"\n---Enter matrix Elements for 1st matrix---"<<endl;
            fraction* matrixinput1 = MatrixInput(rows, cols);
            cout<<"\nInput Matrix no 1 : "<<endl;
            DisplayMatrix(matrixinput1, rows, cols);

            cout<<"\n---Enter matrix Elements for 2nd matrix---"<<endl;
            fraction* matrixinput2 = MatrixInput(rows, cols);
            cout<<"\nInput Matrix no 2 : "<<endl;
            DisplayMatrix(matrixinput2, rows, cols);

            fraction* result = Fraction :: Addition(matrixinput1, matrixinput2, rows, cols);
            cout<<"\nResult : "<<endl;
            DisplayMatrix(result, rows, cols);

            delete[] matrixinput1;
            delete[] matrixinput2;
            delete[] result;
            matrixinput1 =  nullptr;
            matrixinput2 = nullptr;
            result = nullptr;
            break;
        }

        case Operations :: Subtraction : {
            cout<<"\n=====Operation Selected : Subtraction====="<<endl<<endl; 

            cout<<"---Enter the Size of your Matrices---"<<endl;
            int rows, cols;
            SizeInput(rows, cols);

            cout<<"\n---Enter matrix Elements for 1st matrix---"<<endl;
            fraction* matrixinput1 = MatrixInput(rows, cols);
            cout<<"\nInput Matrix no 1 : "<<endl;
            DisplayMatrix(matrixinput1, rows, cols);

            cout<<"\n---Enter matrix Elements for 2nd matrix---"<<endl;
            fraction* matrixinput2 = MatrixInput(rows, cols);
            cout<<"\nInput Matrix no 2 : "<<endl;
            DisplayMatrix(matrixinput2, rows, cols);

            fraction* result = Fraction :: Subtraction(matrixinput1, matrixinput2, rows, cols);
            cout<<"\nResult : "<<endl;
            DisplayMatrix(result, rows, cols);

            delete[] matrixinput1;
            delete[] matrixinput2;
            delete[] result;
            matrixinput1 =  nullptr;
            matrixinput2 = nullptr;
            result = nullptr;
            break;
        }


        case Operations :: Multiplication : {
            cout<<"\n=====Operation Selected : Multiplication====="<<endl<<endl; 

            cout<<"---Enter the Size of your 1st matrix---"<<endl;
            int rows1, cols1;
            SizeInput(rows1, cols1);

            cout<<"\n---Enter matrix Elements for 1st matrix---"<<endl;
            fraction* matrixinput1 = MatrixInput(rows1, cols1);
            cout<<"\nInput Matrix no 1 : "<<endl;
            DisplayMatrix(matrixinput1, rows1, cols1);

            cout<<"---Enter the Size of your 2st matrix Matrix---"<<endl;
            cout<<"Rows (Same as cols of 1st Matrix) : "<<cols1<<endl;
            int cols2;
            cout<<"Cols :";
            cin>>cols2;

            cout<<"\n---Enter matrix Elements for 2nd matrix---"<<endl;
            fraction* matrixinput2 = MatrixInput(cols1, cols2);
            cout<<"\nInput Matrix no 2 : "<<endl;
            DisplayMatrix(matrixinput2, cols1, cols2);

            fraction* result = Fraction :: Multiplication(matrixinput1, matrixinput2, rows1, cols1, cols1, cols2);
            cout<<"\nResult : "<<endl;
            DisplayMatrix(result, rows1, cols2);

            delete[] matrixinput1;
            delete[] matrixinput2;
            delete[] result;
            matrixinput1 =  nullptr;
            matrixinput2 = nullptr;
            result = nullptr;
            break;
        }

        case Operations :: Matrix_Power : {
            cout<<"\n=====Operation Selected : Matrix Power====="<<endl<<endl; 

            cout<<"---Enter the Size of your Matrix---"<<endl;
            int size;
            SizeInput(size);

            cout<<"\n---Enter matrix Elements---"<<endl;
            fraction* matrixinput = MatrixInput(size, size);
            cout<<"\nInput Matrix :"<<endl;
            DisplayMatrix(matrixinput, size, size);

            cout<<"\nEnter the exponent you wanna raise the matrix to : ";
            int power;
            cin>>power;

            fraction* result = Fraction :: PowerMatrix(matrixinput, size, power);
            cout<<"\nResult :"<<endl;
            DisplayMatrix(result, size, size);

            delete[] matrixinput;
            delete[] result;
            matrixinput =  nullptr;
            result = nullptr;
            break;
        }

        case Operations :: Determinant : {
            cout<<"\n=====Operation Selected : Determinant====="<<endl<<endl; 

            cout<<"---Enter the Size of your Matrix---"<<endl;
            int size;
            SizeInput(size);

            cout<<"\n---Enter matrix Elements---"<<endl;
            fraction* matrixinput = MatrixInput(size, size);
            cout<<"\nInput Matrix :"<<endl;
            DisplayMatrix(matrixinput, size, size);

            double* Double_Input = Fraction_to_Double_Matrix(matrixinput, size, size);

            long long determinant = Double :: Determinant(Double_Input, size);
            cout<<"\nDeterminant : "<<determinant<<endl;

            delete[] Double_Input;
            delete[] matrixinput;
            Double_Input = nullptr;
            matrixinput =  nullptr;
            break;
        }

        case Operations :: Inverse : {
            cout<<"\n=====Operation Selected : Inverse====="<<endl<<endl; 

            cout<<"---Enter the Size of your Matrix---"<<endl;
            int size;
            SizeInput(size);

            cout<<"\n---Enter matrix Elements---"<<endl;
            fraction* matrixinput = MatrixInput(size, size);
            cout<<"\nInput Matrix :"<<endl;
            DisplayMatrix(matrixinput, size, size);

            long long det = Fraction :: Determinant(matrixinput, size);

            if(det == 0) {
                cout<<"\nThe Matrix has no Inverse!"<<endl;
                delete[] matrixinput;
                matrixinput = nullptr;
                break;
            }
            else {
                fraction* result = Fraction :: Inverse(matrixinput, size);
                cout<<"\nResult : "<<endl;
                DisplayMatrix(result, size, size);

                delete[] matrixinput;
                delete[] result;
                matrixinput =  nullptr;
                result = nullptr;
                break;
            }
        }

        case Operations :: Row_Echelon_Form : {
            cout<<"\n=====Operation Selected : Row Echelon Form====="<<endl<<endl; 

            cout<<"---Enter the Size of your Matrix---"<<endl;
            int rows, cols;
            SizeInput(rows, cols);

            cout<<"\n---Enter matrix Elements---"<<endl;
            fraction* matrixinput = MatrixInput(rows, cols);
            cout<<"\nInput Matrix :"<<endl;
            DisplayMatrix(matrixinput, rows, cols);

            int rowswaps = 0;
            fraction* result = Fraction :: rowEchelon(matrixinput, rows, cols, rowswaps);
            cout<<"\nResult : "<<endl;
            DisplayMatrix(result, rows, cols);

            delete[] matrixinput;
            delete[] result;
            matrixinput =  nullptr;
            result = nullptr;
            break;
        }

        case Operations :: Reduced_row_Echelon_Form : {
            cout<<"\n=====Operation Selected : Reduced Row Echelon Form====="<<endl<<endl; 

            cout<<"---Enter the Size of your Matrix---"<<endl;
            int rows, cols;
            SizeInput(rows, cols);

            cout<<"\n---Enter matrix Elements---"<<endl;
            fraction* matrixinput = MatrixInput(rows, cols);
            cout<<"\nInput Matrix :"<<endl;
            DisplayMatrix(matrixinput, rows, cols);

            int rowswaps = 0;
            fraction* result = Fraction :: reducedEchelon(matrixinput, rows, cols, rowswaps);
            cout<<"\nResult : "<<endl;
            DisplayMatrix(result, rows, cols);

            delete[] matrixinput;
            delete[] result;
            matrixinput =  nullptr;
            result = nullptr;
            break;
        }
        
        case Operations :: Rank : {
            cout<<"\n=====Operation Selected : Rank of Matrix====="<<endl<<endl; 

            cout<<"---Enter the Size of your Matrix---"<<endl;
            int rows, cols;
            SizeInput(rows, cols);

            cout<<"\n---Enter matrix Elements---"<<endl;
            fraction* matrixinput = MatrixInput(rows, cols);
            cout<<"\nInput Matrix :"<<endl;
            DisplayMatrix(matrixinput, rows, cols);

            double* Double_Input = Fraction_to_Double_Matrix(matrixinput, rows, cols);

            int rank = Double :: Rank(Double_Input, rows, cols);
            cout<<"\nRank : "<<rank<<endl;

            delete[] Double_Input;
            delete[] matrixinput;
            matrixinput =  nullptr;
            Double_Input = nullptr;
            break;
        }

        case Operations :: Cramers_Rule : {
            cout<<"\n=====Operation Selected : Cramer's Rule====="<<endl<<endl; 

            cout<<"---Enter the Information about the Linear System---"<<endl;
            int size;
            cout<<"\nNo of Equations = No of Variables : ";
            cin>>size;
            while (size <= 0) {
                cout<<"Enter a Positive Integer!"<<endl;
                cout<<"No of Equations = No of Variables : ";
                cin>>size;
            }

            double* Coffmatrix = new double[size*size];
            double* Constmatrix = new double[size];
            cout<<"Enter values for equations :"<<endl;
            for(int i=0; i<size; i++) {
                cout<<"\nEquation no "<<i+1<<" : "<<endl;
                for(int j=0; j<size; j++) {
                    cout<<"Cofficient of "<<i+1<<" variable : ";
                    cin>>Coffmatrix[i*size + j];
                }
                cout<<"Constant : ";
                cin>>Constmatrix[i];
            }

            double* AugMatrix = AugmentedMatrix(Coffmatrix, Constmatrix, size, size);
            cout<<"\n====Equations===="<<endl;
            Equations(AugMatrix, size, size+1);

            cout<<"\n====Solution===="<<endl;
            Double :: CramersRule(Coffmatrix, Constmatrix, size);

            delete[] Coffmatrix;
            delete[] Constmatrix;
            delete[] AugMatrix;
            Coffmatrix = nullptr;
            Constmatrix = nullptr;
            AugMatrix = nullptr;
            break;
        }

        case Operations :: Inverse_Method : {
            cout<<"\n=====Operation Selected : Inverse Method====="<<endl<<endl; 

            cout<<"---Enter the Information about the Linear System---"<<endl;
            int size;
            cout<<"\nNo of Equations = No of Variables : ";
            cin>>size;
            while (size <= 0) {
                cout<<"Enter a Positive Integer!"<<endl;
                cout<<"No of Equations = No of Variables : ";
                cin>>size;
            }

            double* Coffmatrix = new double[size*size];
            double* Constmatrix = new double[size];
            cout<<"Enter values for equations :"<<endl;
            for(int i=0; i<size; i++) {
                cout<<"\nEquation no "<<i+1<<" : "<<endl;
                for(int j=0; j<size; j++) {
                    cout<<"Cofficient of "<<i+1<<" variable : ";
                    cin>>Coffmatrix[i*size + j];
                }
                cout<<"Constant : ";
                cin>>Constmatrix[i];
            }

            double* AugMatrix = AugmentedMatrix(Coffmatrix, Constmatrix, size, size);
            cout<<"\n====Equations===="<<endl;
            Equations(AugMatrix, size, size+1);

            cout<<"\n====Solution===="<<endl;
            Double :: InverseMethod(Coffmatrix, Constmatrix, size);

            delete[] Coffmatrix;
            delete[] Constmatrix;
            delete[] AugMatrix;
            Coffmatrix = nullptr;
            Constmatrix = nullptr;
            AugMatrix = nullptr;
            break;
        }

        case Operations :: Guass_Jordon_Elimination : {
            cout<<"\n=====Operation Selected : Guass Jordon Elimination====="<<endl<<endl; 

            cout<<"---Enter the Information about the Linear System---"<<endl;
            int rows, cols;
            cout<<"No of Equations : ";
            cin>>rows;
            while (rows <= 0) {
                cout<<"Enter a Positive Integer!"<<endl;
                cout<<"No of Equations : ";
                cin>>rows;
            }
            cout<<"No of Variables : ";
            cin>>cols;
            while (cols <= 0) {
                cout<<"Enter a Positive Integer!"<<endl;
                cout<<"No of Variables : ";
                cin>>cols;
            }

            fraction* Coffmatrix = new fraction[rows*cols];
            fraction* Constmatrix = new fraction[rows];
            cout<<"Enter values for equations :"<<endl;
            for(int i=0; i<rows; i++) {
                cout<<"\nEquation no "<<i+1<<" : "<<endl;
                for(int j=0; j<cols; j++) {
                    cout<<"Cofficient of "<<j+1<<" variable : ";
                    cin>>Coffmatrix[i*cols + j];
                }
                cout<<"Constant : ";
                cin>>Constmatrix[i];
            }

            fraction* AugMatrix = AugmentedMatrix(Coffmatrix, Constmatrix, rows, cols);
            cout<<"\n====Equations===="<<endl;
            Equations(AugMatrix, rows, cols+1);

            cout<<"\nAugmented Matrix :"<<endl;
            DisplayAugmented(AugMatrix, rows, cols+1);

            cout<<"\n====Solution===="<<endl;
            Fraction :: Guass_Jordan_Elimination(Coffmatrix, Constmatrix, rows, cols);

            delete[] Coffmatrix;
            delete[] Constmatrix;
            delete[] AugMatrix;
            Coffmatrix = nullptr;
            Constmatrix = nullptr;
            AugMatrix = nullptr;

            break;
        }

        case Operations :: Exit : {
            cout<<"\nBie! Hope to See you Again"<<endl;
        }
    }
}