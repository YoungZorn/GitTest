//
// Created by YoungZorn on 2024/7/29.
//
//����ģʽ
#include <iostream>
using namespace std;

//��������  ���Ի��ࣨ����Ĳ��ԣ�
class WeaponStrategy {
public:
    virtual void UseWeapon() = 0;
};

//����Ĳ���ʹ��ذ����Ϊ����
class Knife :public WeaponStrategy {
public:
    virtual void UseWeapon() {
        cout << "ʹ��ذ��" << endl;
    }
};

//����Ĳ���ʹ��AK47��Ϊ����
class AK47 :public WeaponStrategy {
public:
    virtual void UseWeapon() {
        cout << "ʹ��AK47" << endl;
    }
};

//����ʹ�ò��ԵĽ�ɫ
class Character {
public:
    WeaponStrategy* pWeapon;
    void setWeapon(WeaponStrategy* pWeapon) {
        this->pWeapon = pWeapon;
    }

    void ThrowWeapon() {
        this->pWeapon->UseWeapon();
    }
};

void test01() {
    Character* character = new Character;
    WeaponStrategy* knife = new Knife;
    WeaponStrategy* ak47 = new AK47;

    //��ذ�׵�������
    character->setWeapon(knife);
    character->ThrowWeapon();

    character->setWeapon(ak47);
    character->ThrowWeapon();

    delete ak47;
    delete knife;
    delete character;
}

int main()
{
    test01();
}
