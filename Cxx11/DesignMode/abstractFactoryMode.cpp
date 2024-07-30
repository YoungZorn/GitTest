//
// Created by YoungZorn on 2024/7/26.
//
//抽象工厂模式
#include <iostream>
using namespace std;

//苹果的抽象
class AbstractApple {
public:
    virtual void showName() = 0;
};

//中国苹果
class ChinaApple :public AbstractApple {
public:
    virtual void showName() {
        cout << "中国苹果" << endl;
    }
};

//美国苹果
class USAApple :public AbstractApple {
public:
    virtual void showName() {
        cout << "美国苹果" << endl;
    }
};

//日本苹果
class JapanApple :public AbstractApple {
public:
    virtual void showName() {
        cout << "日本苹果" << endl;
    }
};

//香蕉的抽象
class AbstractBanana {
public:
    virtual void showName() = 0;
};

//中国香蕉
class ChinaBanana :public AbstractBanana {
public:
    virtual void showName() {
        cout << "中国香蕉" << endl;
    }
};

//美国香蕉
class USABanana :public AbstractBanana {
public:
    virtual void showName() {
        cout << "美国香蕉" << endl;
    }
};

//日本香蕉
class JapanBanana :public AbstractBanana {
public:
    virtual void showName() {
        cout << "日本香蕉" << endl;
    }
};

//鸭梨的抽象
class AbstractPear {
public:
    virtual void showName() = 0;
};

//中国鸭梨
class ChinaPear :public AbstractPear {
public:
    virtual void showName() {
        cout << "中国鸭梨" << endl;
    }
};

//美国鸭梨
class USAPear :public AbstractPear {
public:
    virtual void showName() {
        cout << "美国鸭梨" << endl;
    }
};

//日本鸭梨
class JapanPear :public AbstractPear {
public:
    virtual void showName() {
        cout << "日本鸭梨" << endl;
    }
};

//抽象工厂  针对产品族
class AbstractFactory {
public:
    virtual AbstractApple* CreateApple() = 0;
    virtual AbstractBanana* CreateBanana() = 0;
    virtual AbstractPear* CreatePear() = 0;
};

//中国工厂
class ChinaFactory :public AbstractFactory {
    virtual AbstractApple* CreateApple() {
        return new ChinaApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new ChinaBanana;
    }
    virtual AbstractPear* CreatePear() {
        return new ChinaPear;
    }
};

//美国工厂
class USAFactory :public AbstractFactory {
    virtual AbstractApple* CreateApple() {
        return new USAApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new USABanana;
    }
    virtual AbstractPear* CreatePear() {
        return new USAPear;
    }
};

//日本工厂
class JapanFactory :public AbstractFactory {
    virtual AbstractApple* CreateApple() {
        return new JapanApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new JapanBanana;
    }
    virtual AbstractPear* CreatePear() {
        return new JapanPear;
    }
};

void test01() {
    AbstractFactory* factory = NULL;
    AbstractApple* apple = NULL;
    AbstractBanana* Banana = NULL;
    AbstractPear* Pear = NULL;

    //中国工厂
    factory = new ChinaFactory;
    apple = factory->CreateApple();
    Banana = factory->CreateBanana();
    Pear = factory->CreatePear();

    apple->showName();
    Banana->showName();
    Pear->showName();

    delete Pear;
    delete apple;
    delete Banana;
    delete factory;
}

int main()
{
    test01();
}

