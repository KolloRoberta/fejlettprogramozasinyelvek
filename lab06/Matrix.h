//
// Created by Kollo Szende-Roberta on 10/28/2024.
//

#ifndef CPP_2024_MATRIX_H
#define CPP_2024_MATRIX_H

#include <iostream>

using namespace std;

class Matrix {
public:
    Matrix(int mRows = 10, int mCols = 10);

    Matrix(const Matrix &what);

    Matrix(Matrix &&what);

    ~Matrix();

    ///feltolto es kiirato metodusok
    void fillMatrix(double value);

    void randomMatrix(int a, int b);

    void printMatrix(ostream &os = cout) const;

    ///lekerdezo metodusok
    bool isSquare() const;

    int getMRows() const;

    int getMCols() const;

    ///operatorfuggvenyek -> operator tulterheles
    ///osszeadas es szorzas
    friend Matrix operator+(const Matrix &x, const Matrix &y);

    friend Matrix operator*(const Matrix &x, const Matrix &y);

    ////olvasas es iras

    friend istream &operator>>(istream &is, Matrix &mat);

    friend ostream &operator<<(ostream &os, const Matrix &mat);

    ///indexeles

    double *operator[](int index);

    double *operator[](int index) const;

    ///ertekadas operatorok
    Matrix &operator=(const Matrix &mat);

    Matrix &operator=(Matrix &&mat);

private:
    double **mElements;
    int mRows;
    int mCols;
};


#endif //CPP_2024_MATRIX_H
