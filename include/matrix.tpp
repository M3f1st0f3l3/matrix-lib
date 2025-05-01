#include "../include/matrix.hpp"

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, T init)
    : rows(rows), cols(cols), data(rows * cols, init) {}


template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, std::vector<T> init)
    : rows(rows), cols(cols), data(init) {}
    

template <typename T> T &Matrix<T>::operator()(size_t i, size_t j) {
  if (i >= rows || j >= cols)
    throw std::out_of_range("Matrix subscript out of boundss");
  return data[i * cols + j];
}

template <typename T> const T &Matrix<T>::operator()(size_t i, size_t j) const {
  if (i >= rows || j >= cols)
    throw std::out_of_range("Matrix subscript out of boundss");
  return data[i * cols + j];
}

// template <typename T>
// Matrix<T>&::operator+(Matrix<T> A, Matrix<T> B){
//     size_t A_rows, A_cols;
//     size_t B_rows, B_cols;
//     A_rows = A.Rows() ; B_rows = B.Rows() ;
//     A_cols = A.Cols() ; B_cols = B.Cols() ;
//     if ( A_rows != B_rows || A_cols != B_cols)
//         throw std::out_of_range("Cannot sum matrices of different sizes");

//     for( size_t i =0; i < A_rows; i++ ){
//         for( size_t j = 0; j < A_cols; j++){
//             (*this) = A(i,j)+B(i,j);
//         }
//     }
// }

template <typename T> void Matrix<T>::print() {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      std::cout << (*this)(i, j) << " ";
    }
    std::cout << "\n";
  }
}

template <typename T> void Matrix<T>::transpose() {
  size_t Rows = (*this).Rows();
  size_t Cols = (*this).Cols();
  if (Rows == Cols) {
    Matrix<T> m(Rows, Cols, 0);
    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < Cols; j++) {
        m(j, i) = (*this)(i, j);
      }
    }

    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < Cols; j++) {
        (*this)(i, j) = m(i, j);
      }
    }

  } else if (Rows != 0) {
    Matrix<T> m(Cols, Rows, 0);

    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < Cols; j++) {
        m(j, i) = (*this)(i, j);
      }
    }
    (*this) = Matrix<T>(Cols, Rows, 0);
    for (size_t i = 0; i < Cols; i++) {
      for (size_t j = 0; j < Rows; j++) {
        (*this)(i, j) = m(i, j);
      }
    }
  }
}

template <typename T> Matrix<T> Minor(const Matrix<T> &A, size_t i, size_t j) {
  size_t init_Cols = A.Cols();
  size_t init_Rows = A.Rows();
  if (init_Cols == 2 || init_Rows == 2) {
    return A;
  } else {
    Matrix<T> m(init_Cols - 1, init_Rows - 1, 0);
    size_t row_index = 0;
    size_t col_index = 0;
    for (size_t k = 0; k < init_Rows; k++) {
      if (i != k) {
        for (size_t l = 0; l < init_Cols; l++) {
          if (l != j) {
            m(row_index, col_index) = A(k, l);
            col_index++;
          }
        }
        col_index = 0;
        row_index++;
      }
    }
    return m;
  }
}

template <typename T> T Matrix<T>::determinant() {

  const size_t cols = (*this).Cols();
  const size_t rows = (*this).Rows();
  const Matrix<T> A = (*this);
  if (rows != cols) {
    throw std::out_of_range(
        "You can't evaluate the determinant of a non squared matrix");
  }

  T value = 0;
  size_t fixed_row = 0;
  if (cols == 2) {
    return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
  } else {
    for (size_t i = 0; i < cols; i++) {
      Matrix<T> m = ::Minor(A, fixed_row, i);
      value += pow(-1, fixed_row + i) * A(fixed_row, i) * m.determinant();
    }
  }

  return value;
}
