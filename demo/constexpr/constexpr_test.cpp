//
// Created by YoungZorn on 2024/6/13.
//
#include <iostream>

constexpr int factorial(int n){
    int ret  = 0;
    for (int i = 0; i < n; ++i) {
        ret += i;
    }
    return ret;
}

int main(){
    int sum = factorial(10);
    std::cout<<"sum(0-10) = "<<sum<<std::endl;

    return 0;
}