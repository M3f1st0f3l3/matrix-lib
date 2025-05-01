#pragma once
#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include <vector> 
template <typename T>
T operator* (std::vector<T> u, std::vector<T> v){
    size_t u_length = u.size();
    size_t v_length = v.size();

    if( u_length != v_length ){
        throw std::out_of_range("Cannot multiply vectors of different sizes");
    }

    T sum = 0;
    for( size_t i = 0; i < u_length; i++ ){
        sum += u[i]*v[i];
    }

    return sum;
}


#include "operations.tpp"

#endif