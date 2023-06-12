#include <iostream>
#include <stdexcept>
#include "matrix.h"


int main() {
    try{
    double val[] = {1,1,1};
    Matrix A = Matrix::diagonal(val,3); 
    std::cout<<"тест функции diagonal(val={1,1,1} -> A:\n"<<A<<std::endl;
    Matrix B("{{10, 20, 30},{40,50,60}}, {70,80,90}");  
    std::cout<<"тест функции Matrix(char* = {{10, 20, 30},{40,50,60}}, {70,80,90}) -> B:\n"<<B<<std::endl;
    Matrix C = Matrix::identity(2); 
    std::cout<<"тест функции identity(n=2) -> C:\n"<<C<<std::endl;
    std::cout<<"тест функции A+B -> \n)"<<A+B<<std::endl;
    // std::cout<<"тест функции A+C -> \n)"<<A+C<<std::endl;
    // std::cout<<"тест функции A.get(5,5) -> \n)"<<A.get(5,5)<<std::endl;
    Matrix D("{{10, 20, 30},{40,50,60}}");  
    Matrix F = Matrix::identity(5);
    Matrix T = Matrix::identity(5);
    Matrix G = Matrix::identity(5);
    std::cout<<F<<std::endl;
    std::cout<<!F<<std::endl;
    std::cout<<D<<std::endl;
    T = G;
    std::cout<<(T!=G)<<std::endl;
    std::cout<<(T==G)<<std::endl;
    std::cout<<D[3];}
    catch(MatrixError e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }


    return 0;
}