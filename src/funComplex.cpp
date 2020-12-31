#include "funComplex.hpp"
uint64_t CompL::imag(){
    return this->data.pI - this->data.nI;
}
uint64_t CompL::real(){
    return this->data.pR - this->data.nR;
}
void CompL::imag(const uint64_t& num){
    this->data.pI = num;
}
void CompL::real(const uint64_t& num){
    this->data.pR = num;
}
CompL::CompL(){
    this->data.pR = 0;
    this->data.nR = 0;
    this->data.pI = 0;
    this->data.nI = 0;
}