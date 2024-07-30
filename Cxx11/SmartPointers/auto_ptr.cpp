//
// Created by YoungZorn on 2024/6/13.
//
#include <iostream>
#include <memory>

class Test{
public:
    Test() { std::cout << "Test的构造函数..." << std::endl; }
    ~Test() { std::cout << "Test的析构函数..." << std::endl; }

    int GetDebug(){
        return this->debug;
    }
private:
    int debug = 10;
};

int main(){
    //Test *demo = new Test();  -->  内存泄漏
    std::auto_ptr<Test> test(new Test);

    std::cout << "test->debug：" << test->GetDebug() << std::endl;
    std::cout << "(*test).debug：" << (*test).GetDebug() << std::endl;

    Test *test1 = test.release();     //释放智能指针的托管

    delete test1;  //手动delete析构


    return 0;
}