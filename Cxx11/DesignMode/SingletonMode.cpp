//
// Created by YoungZorn on 2024/7/26.
//
#include <iostream>
using namespace std;

class A {
public:
    static A* getInstace() {
        return a;
    }

private :
    A() {
        a = new A;
    }
    static A* a;
};
A* A::a = NULL;

//����ʽ   ����Ĵ����ڵ�һ�ε���getInstance����ʱ����
//����ʽ���̲߳���ȫ��
class SingletonLazy {
public:
    static SingletonLazy* getInstance() {
        if (pSingleton == NULL) {
            pSingleton = new SingletonLazy;
        }
        return pSingleton;
    }
private:
    SingletonLazy() {}
    static SingletonLazy* pSingleton;
};
//����������г�ʼ��
SingletonLazy* SingletonLazy::pSingleton=NULL;



//����ʽ    �����ڳ���ִ��ʱ���ȴ���
//����ʽ���̰߳�ȫ��
class SingletonHungry {
public:
    static SingletonHungry* getInstance() {
        return pSingleton;
    }

    static void freeSpace() {
        if (pSingleton != NULL) {
            delete pSingleton;
        }
    }
private:
    SingletonHungry() {}
    static SingletonHungry* pSingleton;
};
//������佫����main��������ǰִ��
SingletonHungry* SingletonHungry::pSingleton=new SingletonHungry;


void test01() {
    SingletonLazy* p1 = SingletonLazy::getInstance();
    SingletonLazy* p2 = SingletonLazy::getInstance();
    if (p1 == p2) {
        cout << "����ģʽ" << endl;
    }
    else {
        cout << "���ǵ���ģʽ" << endl;
    }
    SingletonHungry* p3 = SingletonHungry::getInstance();
    SingletonHungry* p4 = SingletonHungry::getInstance();
    if (p3 == p4) {
        cout << "����ģʽ" << endl;
    }
    else {
        cout << "���ǵ���ģʽ" << endl;
    }
}
int main()
{
    test01();
}
