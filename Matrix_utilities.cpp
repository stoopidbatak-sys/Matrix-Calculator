#include "matrix_utilities.h"
#include <iostream>
using namespace std;

void Menu() {
    cout<<"\n-----Matrix Calculator-----"<<endl<<endl;
    cout<<"\nSelect Your Operation"<<endl;
    cout<<"1 --> Transpose"<<endl;
    cout<<"2 --> Addition"<<endl;
    cout<<"3 --> Multiplication"<<endl;
    cout<<"4 --> Matrix Power"<<endl;
    cout<<"5 --> Determinant"<<endl;
    cout<<"6 --> Inverse"<<endl;
    cout<<"7 --> Row Echelon Form"<<endl;
    cout<<"8 --> Reduced row Echelon Form"<<endl;
    cout<<"9 --> Rank of Matrix"<<endl;
    cout<<"10 --> Cramer's Rule"<<endl;
    cout<<"11 --> Inverse Method"<<endl;
    cout<<"12 --> Guass-Jordon Elimination"<<endl;
    cout<<"13 --> Exit"<<endl;
    cout<<"\nYour Choice : ";
}

void MatrixInput1 (int &rows, int &cols) {
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
        cin>>rows;
    }
    cout<<endl;
}