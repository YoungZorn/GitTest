//
// Created by YoungZorn on 2024/7/26.
//
#include <iostream>

template<typename T>
void func(T &t){
    std::cout<<"lvalue:"<<&t<<std::endl;
}

template<typename T>
void func(T &&t){
    std::cout<<"rvalue:"<<&t<<std::endl;
}

template<typename T>
void revoke(T &&t){
    func(std::forward<T>(t));
}

int main(){
    int a = 10;
    int &m = a;
    int &&n = 10;
    int k = std::move(n);

    //static_cast控制模板参数的类型推导
    func(a);                       // 调用 func<int&>(int&) -> lvalue
    func(static_cast<int &>(m));   // 调用 func<int&>(int&) -> lvalue
    func(static_cast<int &&>(n));  // 调用 func<int&&>(int&&) -> rvalue
    func(k);                       // 调用 func<int&>(int&) -> lvalue
    func(10);                      // 调用 func<int&&>(int&&) -> rvalue

    return 0;
}