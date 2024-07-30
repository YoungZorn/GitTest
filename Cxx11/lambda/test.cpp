//
// Created by YoungZorn on 2024/6/13.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    auto f = [] (auto a){return a;};
    std::cout<<f(1)<<std::endl;
    std::cout<<f(2.3f)<<std::endl;

    auto func1 = ([]{
        std::cout<<"No Capture"<<std::endl;
    });
    func1();

    int num = 100;
    auto func2 = ([num]{
        std::cout<<"[num] = "<<num<<std::endl;
    });
    func2();

    int a = 10,b=20;
    auto func3 = ([=]{
        std::cout<<"[] :  a = "<<a<<",b = "<<b<<std::endl;
    });
    func3();

    int count = 50;
    auto func4 = ([&count]{
        count = 60;
        std::cout<<"&count: count = "<<count<<std::endl;
    });
    func4();

    int index1 = 1;
    int index2 = 2;
    auto function = [&]{
        index1 = 2;
        index2 = 1;
        std::cout << "index1: "<< index1 << ", "
                  << "index2: "<< index2 << std::endl;
    };

    function();

    auto func5 = [](int first,int second){
        return first + second;
    };
    std::cout<<"func5: "<<func5(10,20)<<std::endl;

    int m = 0,n = 0;
    [&,n] (int a) mutable {m = ++n + a;} (4);
    std::cout<<"mutable: m = "<<m<<",n = "<<n<<std::endl;

    std::vector<int> v = {1,2,3,4,5};
    auto value = std::find_if(v.begin(),v.end(),[](int &num){return num > 2;});
    if (value != v.end())
        std::cout<<"value = "<<*value<<std::endl;

    return 0;
}