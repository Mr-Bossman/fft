#include "dynamicArray.hpp"
    template <class Type>
    dynamic_array<Type>::dynamic_array(Type initVal,size_t size){
        this->size = size;
        this->pointer = new Type[size];
        while(this->size--){
            this->pointer[this->size] = 0;
        }
        this->pointer[0] = initVal;
        this->size = size;
    }
    template <class Type>
    dynamic_array<Type>::~dynamic_array(){
        delete[] this->pointer;
        this->offset = this->size = 0;
        this->pointer = nullptr;
    }
    template <class Type>
    void dynamic_array<Type>::del(){
        delete[] this->pointer;
        this->offset = this->size = 0;
        this->pointer = nullptr;
    }
    template <class Type>
    dynamic_array<Type>::dynamic_array (const dynamic_array& rvalue) {
        delete[] this->pointer;
        this->size = rvalue.Size();
        this->pointer = new Type[this->size];
        while(this->size--){
            this->pointer[this->size] = rvalue.pointer[this->size+rvalue.offset];
        }
        this->size = rvalue.Size();
    }
    template <class Type>
    dynamic_array<Type>&    dynamic_array<Type>::operator= (const dynamic_array& rvalue){
        delete[] this->pointer;
        this->size = rvalue.Size();
        this->pointer = new Type[this->size];
        while(this->size--){
            this->pointer[this->size] = rvalue.pointer[this->size+rvalue.offset];
        }
        this->size = rvalue.Size();
        return *this;
    }
    template <class Type>
    size_t dynamic_array<Type>::realSize() const {
        size_t i = this->size-1;
        while(this->pointer[i]==0 && i > 0)i--;
        return i;
    }
    template <class Type>
    size_t dynamic_array<Type>::Size() const {
        return this->size-this->offset;
    }
    template <class Type>
    void dynamic_array<Type>::swap(dynamic_array& rvalue){
        Type* tpointer = this->pointer;
        size_t tsize = this->size;
        size_t toffset = this->offset;
        this->pointer = rvalue.pointer;
        this->size = rvalue.size;
        this->offset = rvalue.offset;
        rvalue.offset = toffset;
        rvalue.size = tsize;
        rvalue.pointer = tpointer;
    }
    template <class Type>

    Type &dynamic_array<Type>::operator[]  (const size_t &index) {
        if(index+this->offset >= this->size){
             expand(index+1);
        }
        if(index > this->size-this->offset)pointer[index+this->offset] = 0;
        return pointer[index+this->offset];
    }
    template <class Type>
    const Type dynamic_array<Type>::operator[]  (const size_t &index) const {
        if(index+this->offset >= this->size ){
            return 0;
        }
        return pointer[index+this->offset];
    }
    template <class Type>
    Type* dynamic_array<Type>::expand(const size_t size) {
        Type *new_ptr = new Type[size];
        register size_t loop = size;
        while(loop-- > this->size){
            new_ptr[loop] = 0;
        }
        while(this->size--){
            new_ptr[this->size] = pointer[this->size+this->offset];
        }
        delete[] pointer; 
        this->size = size;
        return this->pointer = new_ptr;
    } 
    template <class Type>
    Type dynamic_array<Type>::pop(){
        register Type ret = (*this)[0];
        this->offset++;
        return ret;
    }
    template <class Type>
    void dynamic_array<Type>::pop(const size_t& shift){
        this->offset += shift;
    }
    template <class Type>
    Type* dynamic_array<Type>::Lshift(size_t& shift){
        register Type *new_ptr = new Type[this->size+shift];
        register size_t size = this->size;
        this->size += shift;
        while(size--){
            new_ptr[size+shift] = pointer[size+this->offset];
        }
        while(shift--){
            new_ptr[shift] = 0;
        }
        delete[] pointer; 
        return this->pointer = new_ptr;
    }
    template <class Type>
    Type* dynamic_array<Type>::Lshift(const size_t&& shiftA){
        register size_t shift = shiftA;
        Type *new_ptr = new Type[this->size+shift];
        register size_t size = this->size;
        this->size += shift;
        while(size--){
            new_ptr[size+shift] = pointer[size+this->offset];
        }
        while(shift--){
            new_ptr[shift] = 0;
        }
        delete[] pointer; 
        return this->pointer = new_ptr;
    }
