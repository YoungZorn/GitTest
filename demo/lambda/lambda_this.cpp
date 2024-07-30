//
// Created by YoungZorn on 2024/6/13.
//
#include <iostream>

class Lambda{
public:
    void SayHello(){
        std::cout<<"Hello World"<<std::endl;
    }

    void lambda(){
        auto func = ([this]{
            this->SayHello();
        });
        func();
    }
};

int main(){

    Lambda demo;
    demo.lambda();

    int arr[5] = {1,2,3,4,5};

    for (auto &ele: arr) {
        std::cout<<ele<<" ";
    }

    return 0;
}