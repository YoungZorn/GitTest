//
// Created by YoungZorn on 2024/7/29.
//
//策略模式
#include <iostream>
using namespace std;

//抽象武器  策略基类（抽象的策略）
class WeaponStrategy {
public:
    virtual void UseWeapon() = 0;
};

//具体的策略使用匕首作为武器
class Knife :public WeaponStrategy {
public:
    virtual void UseWeapon() {
        cout << "使用匕首" << endl;
    }
};

//具体的策略使用AK47作为武器
class AK47 :public WeaponStrategy {
public:
    virtual void UseWeapon() {
        cout << "使用AK47" << endl;
    }
};

//具体使用策略的角色
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

    //用匕首当作武器
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
