//
// Created by YoungZorn on 2024/7/30.
//
#include <iostream>

class singleClass{
public:
    static singleClass* getInstance(){
        if (instance == nullptr){
            instance = new singleClass();
        }
        return instance;
    }
private:
    static singleClass *instance;
    singleClass (){};
};

singleClass* singleClass::instance = nullptr;

int main(){

    return 0;
}