#pragma once
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <stdexcept>
#include <iostream>
#include "operations.hpp"

template <typename T>
// Declaring a template here adds more generality to the definition. In this way I can work with each type I want
class Matrix {
private:
    std::vector<T> data;
    size_t rows, cols;

public:
    Matrix(size_t rows, size_t cols, T init = T{}) ;
    Matrix(size_t rows, size_t cols, std::vector<T> init) ;

    T& operator()(size_t i, size_t j) ;
    const T& operator()(size_t i, size_t j) const;
    // Matrix& operator+(Matrix<T> A, Matrix<T> B) ;
    // const Matrix& operator+(Matrix<T> A, Matrix<T> B) const;

    size_t Rows() const {return rows;};
    size_t Cols() const {return cols;};


    void print(); 
    void transpose();
    Matrix<T> Minor( const Matrix<T>& A, size_t i, size_t j ) ;
    T determinant() ;
};

template <typename T>
Matrix<T> operator + (const Matrix<T>& A, const Matrix<T>& B){
    size_t A_rows, A_cols;
    size_t B_rows, B_cols;
    A_rows = A.Rows() ; B_rows = B.Rows() ;
    A_cols = A.Cols() ; B_cols = B.Cols() ;
    if ( A_rows != B_rows || A_cols != B_cols){
        throw std::out_of_range("Cannot sum matrices of different sizes");
    }
    Matrix<T> SUM(A_rows, A_cols, T{}) ;
    for( size_t i =0; i < A_rows; i++ ){
        for( size_t j = 0; j < A_cols; j++){
            SUM(i,j) = A(i,j)+B(i,j);
        }
    }

    return SUM ;

}

template <typename T>
Matrix<T> operator - (const Matrix<T>& A, const Matrix<T>& B){
    size_t A_rows, A_cols;
    size_t B_rows, B_cols;
    A_rows = A.Rows() ; B_rows = B.Rows() ;
    A_cols = A.Cols() ; B_cols = B.Cols() ;
    if ( A_rows != B_rows || A_cols != B_cols){
        throw std::out_of_range("Cannot sum matrices of different sizes");
    }
    Matrix<T> SUM(A_rows, A_cols, T{}) ;
    for( size_t i =0; i < A_rows; i++ ){
        for( size_t j = 0; j < A_cols; j++){
            SUM(i,j) = A(i,j)-B(i,j);
        }
    }

    return SUM ;

}

template <typename T>
Matrix<T> operator * (const Matrix<T>& A, const Matrix<T>& B){
    size_t A_rows, A_cols;
    size_t B_rows, B_cols;
    A_rows = A.Rows() ; B_rows = B.Rows() ;
    A_cols = A.Cols() ; B_cols = B.Cols() ;
    if ( A_cols != B_rows ){
        throw std::out_of_range("Cannot multiply matrices with a number of rows different than the one of columns");
    }

    std::vector<std::vector<T>> Rows(A_rows) ;
    std::vector<std::vector<T>> Cols(B_cols) ;

    for( size_t i = 0; i < A_rows; i++ ){
        for( size_t j = 0; j < A_cols; j++ ){
            Rows[i].emplace_back(A(i, j)) ;
        }
    }

    for( size_t i = 0; i < B_cols; i++ ){
        for( size_t j = 0; j < B_rows; j++ ){
            Cols[i].emplace_back(B(j, i)) ;
        }
    }

    Matrix<T> PROD(A_rows, B_cols, T{}) ;

    for( size_t i = 0; i < A_rows ; i++ ){
        for( size_t j = 0; j < B_cols ; j++ ){
            PROD(i, j) = Rows[i]*Cols[j] ;
        }
    }

    return PROD ;

}




#include "matrix.tpp"


#endif
