//
// Created by Kollo Szende-Roberta on 10/28/2024.
//

#include "Matrix.h"

int Matrix::getMRows() const {
    return this->mRows;
}

int Matrix::getMCols() const {
    return this->mCols;
}

///alapertelmezett konstruktor
Matrix::Matrix(int mRows, int mCols) {
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = 0;
        }
    }
}


///masolo konstruktor
Matrix::Matrix(const Matrix &what) : Matrix(what.mRows, what.mCols) {
    //this->mRows = what.mRows;
    //this->mCols = what.mCols;
    //this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        // this->mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

///athelyezo konstruktor///move konstruktor
Matrix::Matrix(Matrix &&what) : mRows(what.mRows), mCols(what.mCols), mElements(what.mElements) {
    what.mRows = 0;
    //what.mCols = 0;
    what.mElements = nullptr;
}

///destruktor
Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        delete[]this->mElements[i];
    }
    delete[]this->mElements;
}

///matrix feltoltese azonos elemekkel
void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }

}

///matrix feltoltese veletlen szamokkal
void Matrix::randomMatrix(int a, int b) {
    srand(time(nullptr));
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = a + (rand() / (RAND_MAX / (b - a)));
        }
    }
}

///matrix kiiratasa
void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << " ";
        }
        os << endl;
    }
}

///negyzetes matrix ellenorzese
bool Matrix::isSquare() const {
    return mRows == mCols;
}

///osszeadas operator
Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw out_of_range("NEM NEM");
    }
    Matrix result(x.mRows, y.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols; ++j) {
            result.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return result;
}

///szorzas operator
Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mCols != y.mRows) {
        throw out_of_range("Nem megfelelo matrix meret szorzashoz.");
    }
    Matrix result(x.mRows, y.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols; ++j) {
            result.mElements[i][j] = 0;
            for (int k = 0; k < x.mCols; ++k) {
                result.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }
    return result;


}

///indexeles operator tulterhelese
double *Matrix::operator[](int index) {
    if (index < 0 || index >= mRows) {
        throw out_of_range("NEM JO");
    }

    return mElements[index];
}

////indexeles operator tulterhelese kostans matrixon
double *Matrix::operator[](int index) const {
    if (index < 0 || index >= mRows) {
        throw out_of_range("NEM JO");
    }
    return mElements[index];
}

////beolvasas operator
istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}


////kiiratas operator
ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os << mat.mElements[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

///ertekado operator masolasa
Matrix &Matrix::operator=(const Matrix &mat) {
    if (this != &mat) {
        if (mRows != mat.mRows || mCols != mat.mCols) {
            for (int i = 0; i < mRows; ++i) {
                delete[] mElements[i];
            }
            delete[] mElements;

            ///uj meretek beallitasa es memoria foglalas
            mRows = mat.mRows;
            mCols = mat.mCols;
            mElements = new double*[mRows];
            for (int i = 0; i < mRows; ++i) {
                mElements[i] = new double[mCols];
            }
        }
    }
    ///elemek masolasa///
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = mat.mElements[i][j];
        }
    }
    return *this;
}

////ertekado operator athelyezese
Matrix &Matrix::operator=(Matrix &&mat) {
    if (this != &mat) {
        ///meglevo elemek torlese
        for (int i = 0; i < mRows; ++i) {
            delete[]mElements[i];
        }
        delete[]mElements;
        ///uj ertek atvetele
        mRows = mat.mRows;
        mCols = mat.mCols;
        mElements = mat.mElements;

        ///forras matrix alaphelyzetbe allitasa
        mat.mRows = 0;
        mat.mCols = 0;
        mat.mElements = nullptr;
    }
    return *this;
}











