//
// Created by YoungZorn on 2024/6/13.
//
#include <iostream>
#include <memory>

class Test{
public:
    Test() { std::cout << "Test�Ĺ��캯��..." << std::endl; }
    ~Test() { std::cout << "Test����������..." << std::endl; }

    int GetDebug(){
        return this->debug;
    }
private:
    int debug = 10;
};

int main(){
    //Test *demo = new Test();  -->  �ڴ�й©
    std::auto_ptr<Test> test(new Test);

    std::cout << "test->debug��" << test->GetDebug() << std::endl;
    std::cout << "(*test).debug��" << (*test).GetDebug() << std::endl;

    Test *test1 = test.release();     //�ͷ�����ָ����й�

    delete test1;  //�ֶ�delete����


    return 0;
}