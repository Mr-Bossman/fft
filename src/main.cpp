#include "common.h"
#include "dynamicArray.hpp"
#include "dynamicArray.cpp"

#define dyn dynamic_array<uint64_t>
int main(int argc,char **argv){
    while(1){
    dyn a(0,9);
    a.del();
    }



    return 0;
}