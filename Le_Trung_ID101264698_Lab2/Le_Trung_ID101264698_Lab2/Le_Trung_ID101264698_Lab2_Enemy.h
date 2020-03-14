#pragma once
#include <iostream>
#include <string>
using namespace std;

class Enemy {
protected:
    string name_;
    int health_;
    string weapon_;
    string armour_;
    string taunt_;
public:
    Enemy();
    //[Q] How to inherit constructors for derived classes ?
    Enemy(string in_name, int in_health, string in_weapon, string in_armour, string in_taunt);
    Enemy(const Enemy &enemy_ptr);
    ~Enemy();

    string GetName();
    int GetHealth();
    string GetWeapon();
    string GetArmour();
    string GetTaunt();

    void SetName(string in_str);
    void SetHealth(int in_int);
    void SetWeapon(string in_str);
    void SetArmour(string in_str);
    void SetTaunt(string in_str);

    virtual void Attack() = 0;
    virtual void Defend() = 0;
    virtual void Taunt() = 0;
};
