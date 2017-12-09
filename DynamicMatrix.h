#ifndef DYNAMICMATRIX_H
#define	DYNAMICMATRIX_H

class DynamicMatrix {
public:
    DynamicMatrix(int width, int length);
    DynamicMatrix(DynamicMatrix& o);
    virtual ~DynamicMatrix();    
    void transpose();
    void printMatrix();
    int getWidth();
    int getLength();
    bool setIndexValue(int width, int length, int value);
    int getIndexValue(int width, int length);
private:
    int width, length;
    int** matrix;
    int** createMatrix(int width, int length);
};

#endif	/* DYNAMICMATRIX_H */
