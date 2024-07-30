//
// Created by YoungZorn on 2024/6/13.
//
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Person {
public:
    Person(int v) {
        this->no = v;
        cout << "���캯�� \t no = " << this->no << endl;
    }

    ~Person() {
        cout << "�������� \t no = " << this->no << endl;
    }

private:
    int no;
};

// �º������ڴ�ɾ��
class DestructPerson {
public:
    void operator() (Person *pt) {
        cout << "DestructPerson..." << endl;
        delete pt;
    }
};


void shared_ptr_test(){
    shared_ptr<Person> sp1;

    shared_ptr<Person> sp2(new Person(2));

// ��ȡ����ָ��ܿصĹ���ָ�������	use_count()�����ü���
    cout << "sp1	use_count() = " << sp1.use_count() << endl;
    cout << "sp2	use_count() = " << sp2.use_count() << endl << endl;

// ����
    sp1 = sp2;

    cout << "sp1	use_count() = " << sp1.use_count() << endl;
    cout << "sp2	use_count() = " << sp2.use_count() << endl << endl;

    shared_ptr<Person> sp3(sp1);
    cout << "sp1	use_count() = " << sp1.use_count() << endl;
    cout << "sp2	use_count() = " << sp2.use_count() << endl;
    cout << "sp2	use_count() = " << sp3.use_count() << endl << endl;

}

int main(){
    shared_ptr_test();

    shared_ptr<int> sp1 = make_shared<int>(10);
    shared_ptr<string> sp2 = make_shared<string>("shared_ptr");



    return 0;
}