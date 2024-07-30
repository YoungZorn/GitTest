//
// Created by YoungZorn on 2024/6/13.
//
#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void f() {

    // expired：判断当前智能指针是否还有托管的对象，有则返回false，无则返回true
    if (!gw.expired()) {
        std::cout << "gw is valid\n";	// 有效的，还有托管的指针
    } else {
        std::cout << "gw is expired\n";	// 过期的，没有托管的指针
    }
}

int main() {
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;

        f();
    }

    // 当{ }体中的指针生命周期结束后，再来判断其是否还有托管的指针
    f();

    return 0;
}
