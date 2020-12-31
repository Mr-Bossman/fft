#include "dynamicArray.hpp"
    template <class Type>
    dynamic_array<Type>::dynamic_array(Type defaultVal,size_t size){
        this->size = size;
        size = this->realSize = ((size/blockSize)+1) * blockSize;
        this->defaultVal = defaultVal;
        this->pointer = new Type[size];
        while(size--){
            this->pointer[size] = defaultVal;
        }
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
        size_t size = this->size = rvalue.Size();
        size = this->realSize = ((size/blockSize)+1) * blockSize;
        this->pointer = new Type[size];
        while(size--){
            this->pointer[size] = rvalue.pointer[size+rvalue.offset];
        }
    }
    template <class Type>
    dynamic_array<Type>&dynamic_array<Type>::operator= (const dynamic_array& rvalue){
        delete[] this->pointer;
        this->size = rvalue.Size();
        size_t size = this->realSize = ((this->size/blockSize)+1) * blockSize;
        this->pointer = new Type[this->realSize];
        while(size--){
            pointer[size] = rvalue.pointer[this->size+rvalue.offset];
        }
        return *this;
    }
    template <class Type>
    size_t dynamic_array<Type>::allocSize() const {
        return this->realSize;
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
        Type tdefaultVal = this->defaultVal;
        this->pointer = rvalue.pointer;
        this->size = rvalue.size;
        this->offset = rvalue.offset;
        this->defaultVal = rvalue.defaultVal;
        rvalue.offset = toffset;
        rvalue.size = tsize;
        rvalue.pointer = tpointer;
        rvalue.defaultVal = tdefaultVal;
    }
    template <class Type>

    Type &dynamic_array<Type>::operator[]  (const size_t &index) {
        if(index+this->offset >= this->realSize){
             expand(index);
        }
        if(index+this->offset >= this->size)pointer[index+this->offset] = defaultVal,this->size = index+this->offset+1;
        return pointer[index+this->offset];
    }
    template <class Type>
    const Type dynamic_array<Type>::operator[]  (const size_t &index) const {
        if(index+this->offset >= this->size ){
            return this->defaultVal;
        }
        return pointer[index+this->offset];
    }
    template <class Type>
    Type* dynamic_array<Type>::expand(const size_t size) {
        size_t loop  = this->realSize = ((size/blockSize)+1) * blockSize;
        Type *new_ptr = new Type[loop];
        while(loop-- >= this->size){// >= or > idk
            new_ptr[loop] = this->defaultVal;
        }
        while(this->size--){
            new_ptr[this->size] = pointer[this->size+this->offset];
        }
        delete[] pointer; 
        this->size = size+1;
        return this->pointer = new_ptr;
    } 
    template <class Type>
    Type dynamic_array<Type>::pop(){
        Type ret = ((const dynamic_array<Type>) *this)[0]; // this calles the index overide
        this->offset++;
        return ret;
    }
    template <class Type>
    void dynamic_array<Type>::pop(const size_t& shift){
        this->offset += shift;
    }
    template <class Type>
    Type* dynamic_array<Type>::Lshift(size_t shift){
        Type *new_ptr = new Type[this->size+shift];
        size_t size = this->size;
        this->size += shift;
        while(size--){
            new_ptr[size+shift] = pointer[size+this->offset];
        }
        while(shift--){
            new_ptr[shift] = this->defaultVal;
        }
        delete[] pointer; 
        return this->pointer = new_ptr;
    }
    template <class T>
    std::ostream& operator<<(std::ostream& os, const dynamic_array<T>& dy){
        os << " [";
        for(size_t i = 0; i < dy.Size()-1;i++)
            os << dy[i] << ',';
        os << dy[dy.Size()-1];
        os << "] ";
        return os;
    }


