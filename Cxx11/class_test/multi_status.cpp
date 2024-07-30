//
// Created by YoungZorn on 2024/6/4.
//
#include <iostream>

class A
{
public:
    virtual void func(int val = 2){
        std::cout<<"A->"<<val<<std::endl;
    }
    virtual void test(){
        func();
    }
};

class B:public A
{
public:
    void func(int val = 1){
        std::cout<<"B->"<<val<<std::endl;
    }
};

class C:public B
{
public:
    void func(int val = 0){
        std::cout<<"C->"<<val<<std::endl;
    }
};

int main(){
    B *p = new B;
    p->test();

    return 0;
}