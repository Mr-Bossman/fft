#include "common.h"
#pragma once 

#ifndef blockSize
#define blockSize 1024
#endif
template <typename Type>
class dynamic_array {
    public:
    Type defaultVal;
    //pointer to the array
    Type *pointer = nullptr ;
    //sizeof the array
    size_t size;
    size_t realSize;
    //unused bytes b4 the start of the array
    size_t offset = 0;

    //defualt value , size
    dynamic_array(Type defaultVal,size_t size = 1);
    dynamic_array (const dynamic_array& rvalue);
    //frees the alloc memory
    ~dynamic_array();
    //frees the alloc memory
    void del();
    //copies the array
    dynamic_array& operator= (const dynamic_array& rvalue);
    //size of alloc 
    size_t allocSize() const ;
    //size of the cuurent array
    size_t Size() const ;
    //swaps the constants of the arrays
    void swap(dynamic_array& rvalue);
    Type &operator[]  (const size_t &index);
    const Type operator[]  (const size_t &index) const ;
    //expands the array
    Type* expand(const size_t size);
    //pop one off the bottom of the array and return value
    Type pop();
    //pop many off the bottom
    void pop(const size_t& shift);
    //TODO adds elements to the bottom of the array
    Type* Lshift(size_t shift);
    template <class T>
    friend std::ostream& operator<<(std::ostream& os, const dynamic_array<T>& dy);
};