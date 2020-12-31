#include "funComplex.hpp"
uint64_t CompL::imag(){
    return this->data.pI - this->data.nI;
}
CompL::CompL(){
    this->data.pR = 0;
    this->data.nR = 0;
    this->data.pI = 0;
    this->data.nI = 0;
}