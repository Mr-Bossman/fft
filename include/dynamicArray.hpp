#include "common.h"
#pragma once 


template <class Type>
class dynamic_array {
    public:
    Type *pointer = nullptr ;
    size_t size;
    size_t offset = 0;
    dynamic_array(Type initVal = 0 ,size_t size = 1);
    ~dynamic_array();
    void del();
    dynamic_array (const dynamic_array& rvalue);
    dynamic_array& operator= (const dynamic_array& rvalue);
    size_t realSize() const ;
    size_t Size() const ;
    void swap(dynamic_array& rvalue);
    Type &operator[]  (const size_t &index);
    const Type operator[]  (const size_t &index) const ;
    Type* expand(const size_t size);
    Type pop();
    void pop(const size_t& shift);
    Type* Lshift(size_t& shift);
    Type* Lshift(const size_t&& shiftA);
};