#include "../include/matrix.hpp"

int main(){
    Matrix<double> A(3, 3, 1) ;
    Matrix<double> B(3, 3, -2) ;
    Matrix<double> C(6, 3, 1.5) ;
    Matrix<double> D(3, 6, 1.6) ;
    
    for( size_t i = 0; i < 6; i++ ){
        for( size_t j = 0; j < 3; j++){
            if( i == j ){
                C(i,j)=1 ;
            }
        }
    }

    Matrix<double> SUM = A+B ;
    Matrix<double> Difference_1 = A-B ;
    Matrix<double> Difference_2 = B-A ;
    Matrix<double> PROD = C*D ;

    SUM.print() ;
    std::cout << "\n" << "\n";
    Difference_1.print() ;
    std::cout << "\n" << "\n" ;
    Difference_2.print() ;
    std::cout << "\n" << "\n" ;
    C.print() ;
    std::cout << "\n" << "\n" ;
    D.print() ;
    std::cout << "\n" << "\n" ;
    PROD.print() ;
    std::cout << "\n" << "\n" ;

}