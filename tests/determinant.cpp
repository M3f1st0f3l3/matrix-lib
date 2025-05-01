#include "../include/matrix.hpp"
#include <iostream>

int main(){
    Matrix<int> A(3, 3, 2) ;
    A(1,1)=1 ;
    A(2,2)=-3;
    size_t i = 1;
    size_t j = 1;
    Matrix<int> M = Minor(A, i, j) ;

    A.print() ;
    M.print() ;

   std::cout << "\nThe determinant of the matrix A is " << A.determinant() << "\n" ;

   Matrix<double> C(4, 4, {0, 2, 3, -1, 2, 7.3, 4, 5, 6, 1, 0, 0, 2, 0, 5, 0});

   C.print() ;
   std::cout << "\nThe determinant of the matrix C is " << C.determinant() << "\n" ;
    return 0;
}

