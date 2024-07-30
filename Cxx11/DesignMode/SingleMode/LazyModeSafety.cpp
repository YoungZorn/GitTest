//
// Created by YoungZorn on 2024/7/30.
//
#include <iostream>
#include <mutex>

class singleClass{
public:
    static singleClass* getInstance(){
        if (instance == nullptr){
            i_mutex.lock();
            if (instance == nullptr){
                instance = new singleClass();
            }
            i_mutex.unlock();
        }
        return instance;
    }
private:
    static singleClass* instance;
    singleClass(){};
    static std::mutex i_mutex;
};

singleClass* singleClass::instance = nullptr;
std::mutex singleClass::i_mutex;

int main(){

    return 0;
}