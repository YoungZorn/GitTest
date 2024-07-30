//
// Created by YoungZorn on 2024/6/4.
//
#include <iostream>
#include <string>

class People{
public:
    virtual void Walk();
private:
    int age;
    std::string name;
};

void People::Walk() {
    std::cout<<"I can walk"<<std::endl;
}

class Man:public People{
public:
    void MakeMoney();
private:
    int shortHairLen;
};

void Man::MakeMoney() {
    std::cout<<"I can make money"<<std::endl;
}

int main(){

    People p1;
    std::cout<<"&(People p1) = "<<&p1<<std::endl;

    Man m1;
    std::cout<<"&(Man m1) = "<<&m1<<std::endl;

    wchar_t name[] = L"Jack";
    std::wcout<<"wchar_t name[] = "<<name<<std::endl;

    return 0;
}