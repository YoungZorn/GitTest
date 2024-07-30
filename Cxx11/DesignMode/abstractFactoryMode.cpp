//
// Created by YoungZorn on 2024/7/26.
//
//���󹤳�ģʽ
#include <iostream>
using namespace std;

//ƻ���ĳ���
class AbstractApple {
public:
    virtual void showName() = 0;
};

//�й�ƻ��
class ChinaApple :public AbstractApple {
public:
    virtual void showName() {
        cout << "�й�ƻ��" << endl;
    }
};

//����ƻ��
class USAApple :public AbstractApple {
public:
    virtual void showName() {
        cout << "����ƻ��" << endl;
    }
};

//�ձ�ƻ��
class JapanApple :public AbstractApple {
public:
    virtual void showName() {
        cout << "�ձ�ƻ��" << endl;
    }
};

//�㽶�ĳ���
class AbstractBanana {
public:
    virtual void showName() = 0;
};

//�й��㽶
class ChinaBanana :public AbstractBanana {
public:
    virtual void showName() {
        cout << "�й��㽶" << endl;
    }
};

//�����㽶
class USABanana :public AbstractBanana {
public:
    virtual void showName() {
        cout << "�����㽶" << endl;
    }
};

//�ձ��㽶
class JapanBanana :public AbstractBanana {
public:
    virtual void showName() {
        cout << "�ձ��㽶" << endl;
    }
};

//Ѽ��ĳ���
class AbstractPear {
public:
    virtual void showName() = 0;
};

//�й�Ѽ��
class ChinaPear :public AbstractPear {
public:
    virtual void showName() {
        cout << "�й�Ѽ��" << endl;
    }
};

//����Ѽ��
class USAPear :public AbstractPear {
public:
    virtual void showName() {
        cout << "����Ѽ��" << endl;
    }
};

//�ձ�Ѽ��
class JapanPear :public AbstractPear {
public:
    virtual void showName() {
        cout << "�ձ�Ѽ��" << endl;
    }
};

//���󹤳�  ��Բ�Ʒ��
class AbstractFactory {
public:
    virtual AbstractApple* CreateApple() = 0;
    virtual AbstractBanana* CreateBanana() = 0;
    virtual AbstractPear* CreatePear() = 0;
};

//�й�����
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

//��������
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

//�ձ�����
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

    //�й�����
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

