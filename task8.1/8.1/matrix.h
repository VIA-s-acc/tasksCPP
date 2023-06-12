
#include <iostream>
#include <stdexcept>

class Matrix {
public:
    Matrix(int n, int m);
    Matrix(double val);
    Matrix(double* array, int m);
    Matrix(int n, double* array);
    Matrix(const char* str);

    static Matrix identity(int n);
    static Matrix diagonal(double* vals, int n);

    int rows() const;
    int columns() const;

    void set(int i, int j, double val);
    double get(int i, int j) const;

    Matrix operator[](int i) const;

    Matrix operator*(const Matrix& other) const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    friend Matrix operator*(double scalar, const Matrix& matrix);
    Matrix operator*=(double scalar) const;

    Matrix& operator=(const Matrix& other);
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(double scalar);
    Matrix& operator*=(const Matrix& other);

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;
    Matrix operator!() const;
    ~Matrix();

private:
    double** data;
    int n_rows;
    int n_columns;
};

class MatrixError {
public:
    MatrixError(std::string message, std::string file, int line);
    std::string what() ;
private:
    std::string message;
    std::string file;
    int line;
};

std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

