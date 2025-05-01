#include "../include/matrix.hpp"
#include <cassert>
#include <iostream>

int main() {
    Matrix<int> m(3, 3, 3) ;
    m(0, 1) = 5;
    m(2,1) = 7;
    m.print();
    std::cout << "\n" ;
    m.transpose();
    m.print() ;
    std::cout << "\n" ;

    Matrix<int> L(3,3, 1) ;
    for( int i = 0; i < 3; i++ ){
        for( int j = 0; j < 3; j++){
            L(i,j) = std::pow(i,j) + std::pow(-1, j)*2;
        }
    }

    L.print() ;
    
    Matrix<int> C(3, 3, 0) ;
    C.print() ;

    C = m + L ;
    C.print();


    return 0;
}
