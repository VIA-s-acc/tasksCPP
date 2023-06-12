#include "matrix.h"

#include <cstring>

MatrixError::MatrixError(std::string message, std::string file, int line) : message(message), file(file), line(line) {}
std::string MatrixError::what()  {
        return message + "\nФайл : " + file +  "\nСтрока : " + std::to_string(line);
    }


Matrix::Matrix(int n, int m) : n_rows(n), n_columns(m) {
    data = new double*[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        data[i] = new double[n_columns];
        for (int j = 0; j < n_columns; ++j) {
            data[i][j] = 0.0;
        }
    }
}
int get_row_count(const char* str)
{
    int n_rows = 0;
    int len = strlen(str);
    int i = 1;
    while (i < len) {
            if (str[i] == '{') {
                n_rows++;
            }
            i++;
    }
    return n_rows;
}
int get_col_count(const char* str)
{
    int len = strlen(str);
    int j = 0;
    int n_columns = 0;
    while(j < len)
    {
        if (str[j] == ',') {
            n_columns++;
        } 
        if (str[j] == '}') {
            break;
        }
        j++;
    }
    n_columns++;
    return n_columns;
}
Matrix::Matrix(const char* str): Matrix(get_row_count(str),get_col_count(str)) {
    int i=1;
    int j=0;
    int len = strlen(str);
    while (i < len && j < n_rows) {
        if (str[i] == '{') {
            j++;
            int k = 0;
            i++;
            while (k < n_columns && i < len) {
                char* end;
                data[j - 1][k] = strtod(str + i, &end);
                k++;
                i = end - str + 1 ;
            }
        } else {
            i++;
        }
    }
}
    
Matrix::Matrix(double val) : Matrix(1, 1) {
    data[0][0] = val;
}

Matrix::Matrix(double* array, int m) : Matrix(1, m) {
    for (int j = 0; j < n_columns; ++j) {
        data[0][j] = array[j];
    }
}

Matrix::Matrix(int n, double* array) : Matrix(n, 1) {
    for (int i = 0; i < n_rows; ++i) {
        data[i][0] = array[i];
    }
}




Matrix Matrix::identity(int n) {
    Matrix result(n, n);
    for (int i = 0; i < n; ++i) {
        result.data[i][i] = 1.0;
    }
    return result;
}


Matrix Matrix::diagonal(double* vals, int n) {
    Matrix result(n, n);
    for (int i = 0; i < n; ++i) {
        result.data[i][i] = vals[i];
    }
    return result;
}


int Matrix::rows() const {
    return n_rows;
}

int Matrix::columns() const {
    return n_columns;
}

void Matrix::set(int i, int j, double val) {
    if (i < 0 || i >= n_rows || j < 0 || j >= n_columns) {
        throw MatrixError("Индекс выходит за пределы", __FILE__, __LINE__);
    }
    data[i][j] = val;
}

double Matrix::get(int i, int j) const {
    if (i < 0 || i >= n_rows || j < 0 || j >= n_columns) {
        throw MatrixError("Индекс выходит за пределы", __FILE__, __LINE__);
    }
    return data[i][j];
}

bool Matrix::operator==(const Matrix& other) const
{
    if(n_rows == other.n_rows && n_columns == other.n_columns)
    {
        for(int i = 0; i < n_rows; i++)
        {
            for(int j = 0; j < n_columns; j++)
            {
                if(data[i][j] == other.data[i][j])
                {
                    ;
                }
                else {return false;}
            }
        }
        return true;
    }
    else return false;
    
}



bool Matrix::operator!=(const Matrix& other) const
{
    int sum = 0;
    if(n_rows != other.n_rows || n_columns != other.n_columns)
    {
        return true;
    }
    else{
        for(int i = 0; i < n_rows; i++)
        {
            for(int j = 0; j < n_columns; j++)
            {
                if(data[i][j] == other.data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    return true;
}




Matrix Matrix::operator!() const{
    Matrix result(n_rows,n_columns);
    for(int i = 0; i < n_rows; i++)
    {
        for(int j = 0; j < n_columns; j++)
        {
            if(data[i][j] == 0)
            {
                result.data[i][j] = 1;
            }
            else result.data[i][j] = 0;
        }
    }
    return result;
}


Matrix Matrix::operator[](int i) const {
    Matrix result(1);
    bool row;
    if (i <= 0 || (i > n_rows && i > n_columns)) {
        throw MatrixError("Индекс выходит за пределы", __FILE__, __LINE__);
    }
    if(i <= n_rows){
        row = true;
    }
    else if(i > n_rows && i <= n_columns){
        row = false;
    }
    if(row == true){
        Matrix A(1,n_columns);
        result = A;
        for (int j = 0; j < n_columns; j++){
                result.data[0][j] = data[i-1][j];    
        }
    }
    else{
        Matrix A(n_rows,1);
        result = A;
        for (int j = 0; j < n_rows; j++){
                result.data[j][0] = data[j][i-1];    
        }
    }
    return result;
}



Matrix Matrix::operator*(const Matrix& other) const {
    if (n_columns != other.n_rows) {
        throw MatrixError("Несовпадающие размерности", __FILE__, __LINE__);
    }
    Matrix result(n_rows, other.n_columns);
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < other.n_columns; j++) {
            double sum = 0;
            for (int k = 0; k < n_columns; k++) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}



Matrix Matrix::operator+(const Matrix& other) const {
    if (n_rows != other.n_rows || n_columns != other.n_columns) {
        throw MatrixError("Несовпадающие размерности", __FILE__, __LINE__);
    }
    Matrix result(n_rows, n_columns);
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}



Matrix Matrix::operator-(const Matrix& other) const {
    if (n_rows != other.n_rows || n_columns != other.n_columns) {
        throw MatrixError("Несовпадающие размерности", __FILE__, __LINE__);
    }
    Matrix result(n_rows, n_columns);
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(n_rows, n_columns);
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            result.data[i][j] = scalar * data[i][j];
        }
    }
    return result;
}

Matrix operator*(double scalar, const Matrix& matrix) {
    return matrix * scalar;
}

Matrix& Matrix::operator*=(double scalar) {
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_columns; ++j) {
            data[i][j] *= scalar;
        }
    }
    return *this;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }
    if (n_rows != other.n_rows || n_columns != other.n_columns) {
        for (int i = 0; i < n_rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = new double*[other.n_rows];
        for (int i = 0; i < other.n_rows; ++i) {
            data[i] = new double[other.n_columns];
        }
        n_rows = other.n_rows;
        n_columns = other.n_columns;
    }
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_columns; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    if (n_rows != other.n_rows || n_columns != other.n_columns) {
        throw MatrixError("Несовпадающие размерности", __FILE__, __LINE__);
    }
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_columns; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    if (n_columns != other.n_rows) {
        throw MatrixError("Несовпадающие размерности", __FILE__, __LINE__);
    }
    Matrix result(n_rows, other.n_columns);
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < other.n_columns; ++j) {
            for (int k = 0; k < n_columns; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    *this = result;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (n_rows != other.n_rows || n_columns != other.n_columns) {
        throw MatrixError("Несовпадающие размерности", __FILE__, __LINE__);
    }
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_columns; ++j) {
            data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}   


std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows(); i++) {
        for (int j = 0; j < matrix.columns(); j++) {
            out << matrix.get(i, j) << " ";
        }
        out << std::endl;
    }
    return out;
}
Matrix::~Matrix() {
    for (int i = 0; i < n_rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}
