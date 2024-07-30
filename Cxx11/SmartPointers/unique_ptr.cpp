//
// Created by YoungZorn on 2024/6/13.
//
#include <iostream>
#include <string>
#include <memory>
#include <vector>

void unique_ptr_test(){
    std::unique_ptr<std::string> p1(new std::string("Name:LiHua"));
    std::unique_ptr<std::string> p2(new std::string("Age: 22"));

    std::cout << "p1：" << p1.get() << std::endl;
    std::cout << "p2：" << p2.get() << std::endl;

    //p1 = p2;  禁止左值赋值
    //std::unique_ptr<std::string> p3(p2);  禁用拷贝构造
    std::unique_ptr<std::string> p3(std::move(p1));

    p1 = std::move(p2);

    std::cout << "p1 = p2 赋值后：" << std::endl;
    std::cout << "p1：" << p1.get() << std::endl;
    std::cout << "p2：" << p2.get() << std::endl;
    std::cout << "p3：" << p3.get() << std::endl;
}

void unique_ptr_STL(){
    std::vector<std::unique_ptr<std::string>> vec;
    std::unique_ptr<std::string> p3(new std::string("I am p3"));
    std::unique_ptr<std::string> p4(new std::string("I am p4"));

    vec.push_back(std::move(p3));
    vec.push_back(std::move(p4));

    std::cout << "vec.at(0)：" << *vec.at(0) << std::endl;
    std::cout << "vec[1]：" << *vec[1] << std::endl;

    //vec[0] = vec[1];	/* 不允许直接赋值 */
    vec[0] = std::move(vec[1]);		// 需要使用move修饰，使得程序员知道后果

    std::cout << "vec.at(0)：" << *vec.at(0) << std::endl;
    //std::cout << "vec[1]：" << *vec[1] << std::endl;
}

int main(){
    unique_ptr_STL();

    return 0;
}