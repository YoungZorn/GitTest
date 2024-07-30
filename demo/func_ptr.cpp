//
// Created by CN_YoungZorn on 2024/6/3.
//

#include "func_ptr.h"

int func_ptr::MyFunc(void* value) {
    int* result = static_cast<int*>(value);
    std::cout<<__FUNCTION__ <<" &result = "<<result<<std::endl;
    return *result * 10;
}
