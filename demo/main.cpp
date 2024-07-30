#include <iostream>
#include <ctime>
#include <typeinfo>

#include "reinterpret_cast_test.h"
#include "func_ptr.h"

enum Week
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

class MyClass {
public:
    void methodA() {
        std::cout << "Method A called." << std::endl;
        // 使用 this 关键字调用方法 B
        this->methodB();
        // 也可以直接调用，不需要 this 关键字
        //methodB();
    }

    void methodB() {
        std::cout << "Method B called." << std::endl;
    }
};

int main() {
    MyClass obj;
    obj.methodA();

    std::time_t eventEndTime = std::time(nullptr);

    std::tm now_tm = *std::localtime(&eventEndTime);
    char buffer[128];
    std::strftime(buffer, sizeof(buffer),"%Y-%m-%d %H:%M:%S",&now_tm);

    std::cout<<"local time:"<<buffer<<std::endl;

    Week noday = static_cast<Week>(7);
    std::cout<<"noday type:"<< typeid(noday).name()<<std::endl;
    std::cout<<"eventEndTime type:"<< typeid(eventEndTime).name()<<std::endl;

    int a = 10;
    const int const_a = static_cast<const int>(a);
    std::cout<<"const_a type:"<< typeid(const_a).name()<<std::endl;

    int &non_const_a = const_cast<int &>(const_a);
    non_const_a = 20;
    std::cout<<non_const_a<<std::endl;

    Data::getInstance().reinterpret_cast_test();

    std::cout<<"---------------------------------------"<<std::endl;

    int value = 5;  // 正确设置 value 的值
    void* context = static_cast<void*>(&value);  // 将 value 的地址转换为 void*

    fun funcPtr = func_ptr::MyFunc;  // 将函数指针设置为 MyFunc
    int value_trans = funcPtr(context);  // 调用函数并传递上下文

    std::cout<<"value = "<<value<<"   value_trans = "<<value_trans<<std::endl;

    return 0;
}
