#include "display.h"
#include "fraction.h"
#include <iostream>
using namespace std;

int numLength(const long long &num) {
    if (num ==0)
        return 1;

    if (num > 0) {
        int length = 0;
        for(long long i=num; i>0; i/=10) {
            length++;
        }
        return length;
    }

    int length = 1;
    for(long long i=-num; i>0; i/=10) {
        length++;
    }
    return length;

}

int fractionLength(const fraction &obj) {
    int length = 0;
    length += numLength(obj.getNum());
    if(obj.getDen() != 1) 
        length += numLength(obj.getDen())+1;

    return length;
}

int max_length_Column(fraction* matrix, int rows, int cols, int column) {
    int max = fractionLength(matrix[column-1]);
    for(int i=1; i<rows; i++) {
        if(fractionLength(matrix[i*cols + column-1]) > max) 
            max = fractionLength(matrix[i*cols + column-1]);
    }

    return max;
}

int* max_length_Columns_array(fraction* matrix, int rows, int cols) {
    int* length_array = new int[cols];
    for(int i=0; i<cols; i++) {
        length_array[i] = max_length_Column(matrix, rows, cols, i+1);
    }

    return length_array;
}

int length_array_Sum (int* array, int cols) {
    int sum = 0;
    for(int i=0; i<cols; i++) {
        sum += array[i];
    }

    return sum;
}

void DisplayMatrix (fraction* matrix, int rows, int cols) {
    int* lengthArray = max_length_Columns_array(matrix, rows, cols);
    int sum_max_lengths = length_array_Sum(lengthArray, cols);
    cout<<" --";
    for (int i=0; i<sum_max_lengths+4*cols; i++) 
        cout<<" ";
    cout<<"--"<<endl;

    for (int i=0; i<rows; i++) {
        cout<<"|  ";
        for (int j=0; j<cols; j++) {
            int diff = lengthArray[j] - fractionLength(matrix[i*cols+j]);
            bool odd = (diff % 2 != 0);
            bool negative = (matrix[i*cols+j] < 0);
            for(int k=0; k<2+(diff/2)-negative; k++)
                cout<<" ";
            cout<<matrix[i*cols+j];
            for(int k=0; k<2+(diff/2)+odd+negative; k++)
                cout<<" ";
        }
        cout<<"  |"<<endl;
    }

    cout<<" --";
    for (int i=0; i<sum_max_lengths+4*cols; i++) 
        cout<<" ";
    cout<<"--"<<endl;
} 

void DisplayAugmented (fraction* Augmatrix, int equations, int variables) {
    int* lengthArray = max_length_Columns_array(Augmatrix, equations, variables+1);
    int sum_max_lengths = length_array_Sum(lengthArray, variables+1);
    cout<<" --";
    for (int i=0; i<sum_max_lengths+4*(variables+1); i++) 
        cout<<" ";
    cout<<"--"<<endl;

    for (int i=0; i<equations; i++) {
        cout<<"|  ";
        for (int j=0; j<variables+1; j++) {
            int diff = lengthArray[j] - fractionLength(Augmatrix[i*(variables+1)+j]);
            bool odd = (diff % 2 != 0);
            bool negative = (Augmatrix[i*(variables+1)+j] < 0);
            for(int k=0; k<2+(diff/2)-negative; k++)
                cout<<" ";
            cout<<Augmatrix[i*(variables+1)+j];
            for(int k=0; k<2+(diff/2)+odd+negative; k++)
                cout<<" ";

            if(j == variables-1) 
                cout<<" | ";
        }
        cout<<"  |"<<endl;
    }

    cout<<" --";
    for (int i=0; i<sum_max_lengths+4*(variables+1); i++) 
        cout<<" ";
    cout<<"--"<<endl;
}