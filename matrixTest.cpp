#include "DynamicMatrix.h"
#include <iostream>
using namespace std;

DynamicMatrix::DynamicMatrix(int width, int length) {
    this->length = length;
    this->width = width;
    this->matrix = createMatrix(width, length);
}

DynamicMatrix::DynamicMatrix(DynamicMatrix& o) {
    if (this->width == o.getWidth() && this->length == o.getWidth()) {
        for (int i = 0; i < width; i++)
            for (int j = 0; j < length; j++)
                setIndexValue(i, j, o.getIndexValue(i + 1, j + 1));
    } else {
        cout << "Matrix dimensions do not match copy constructor failed!" << endl;
    }
}

DynamicMatrix::~DynamicMatrix() {
}

int DynamicMatrix::getWidth() {
    return width;
}

int DynamicMatrix::getLength() {
    return length;
}

int** DynamicMatrix::createMatrix(int width, int length) {
    int** newArray = new int*[width];
    for (int i = 0; i < width; i++)
        newArray[i] = new int[length];
    return newArray;
}

void DynamicMatrix::transpose() {
    int** newMatrix = createMatrix(length, width);
    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            newMatrix[j][i] = getIndexValue(i + 1, j + 1);
    delete[] matrix;
    matrix = newMatrix;
    int temp = width;
    width = length;
    length = temp;
}

void DynamicMatrix::printMatrix() {
    for (int i = 1; i <= width; i++)
        for (int j = 1; j <= length; j++)
            cout << "a[" << i << "][" << j << "]: " << getIndexValue(i, j) << endl;
}

bool DynamicMatrix::setIndexValue(int width, int length, int value) {
    if (length >= 1 && (length - 1) <= this->length && width >= 1 && (width - 1) <= this->width) {
        matrix[width - 1][length - 1] = value;       
        return true;
    } else
        return false;
}

int DynamicMatrix::getIndexValue(int width, int length) {
    if (length >= 1 && (length - 1) <= this->length && width >= 1 && (width - 1) <= this->width) {
        return matrix[width - 1][length - 1];
    } else
        return -999999;
}

int main() {   
    DynamicMatrix m(4, 5);
    DynamicMatrix m2 = m;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 5; j++)
            if (!m.setIndexValue(i, j, ((i - 1) * 5) + j)) {
                break;
                cout << "Error incorrect index value(s)";
            }
    m.printMatrix();
    m.transpose();
    cout << "After transpose Width: " << m.getWidth() << " Length: " << m.getLength() << endl;
    m.printMatrix();
}
