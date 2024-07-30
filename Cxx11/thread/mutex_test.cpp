//
// Created by CN_YoungZorn on 2024/6/3.
//

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1;
std::mutex mtx2;

void print_block1(int n,char c){
    mtx1.lock();
    for (int i = 0; i < n; ++i) {
        std::chrono::seconds(1);
        std::cout << c << "    ";
    }
    std::cout<<'\n';
    mtx1.unlock();
}

void print_block2(int n,char c){
    mtx2.lock();
    for (int i = 0; i < n; ++i) {
        std::chrono::seconds(1);
        std::cout << c << "    ";
    }
    std::cout<<'\n';
    mtx2.unlock();
}

int main(){
    std::thread th1(print_block1,50,'*');
    std::thread th2(print_block2,50,'#');

    th1.join();
    th2.join();

    return 0;
}