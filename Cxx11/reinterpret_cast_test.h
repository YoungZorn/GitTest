//
// Created by YoungZorn on 2024/5/27.
//
#include <iostream>
#include <memory> // 包含智能指针

class Data {
public:
    short a;
    short b;

    // 删除拷贝构造函数和赋值操作符
    Data(const Data&) = delete;
    Data& operator=(const Data&) = delete;

    static Data& getInstance() {
        static Data instance; // 唯一实例
        return instance;
    }

    int reinterpret_cast_test() {
        long value = 0xAAAABBBB;
        Data* data = reinterpret_cast<Data*>(&value);

        // 为了确保输出的正确性，我们使用按位与运算来提取特定位
        std::cout << "Hex output:" << std::endl;
        std::cout << std::hex << data->a << std::endl;
        std::cout << std::hex << data->b << std::endl;

        // 打印字节序信息
        union {
            uint32_t i;
            char c[4];
        } e = { 0x01020304 };

        std::cout << "Byte order: ";
        if (e.c[0] == 1) {
            std::cout << "Big Endian" << std::endl;
        } else {
            std::cout << "Little Endian" << std::endl;
        }

        return 0;
    }

private:
    Data() = default; // 私有化构造函数，防止直接实例化
};
