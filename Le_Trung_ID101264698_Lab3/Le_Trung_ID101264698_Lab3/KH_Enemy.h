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
    Enemy(const Enemy& enemy_ptr);
    //Enemy(Enemy* enemy_ptr);
    ~Enemy();

    string GetName() const;
    int GetHealth() const;
    string GetWeapon() const;
    string GetArmour() const;
    string GetTaunt() const;

    void SetName(string in_str);
    void SetHealth(int in_int);
    void SetWeapon(string in_str);
    void SetArmour(string in_str);
    void SetTaunt(string in_str);

    virtual void Attack() = 0;
    virtual void Defend() = 0;
    virtual void Taunt() = 0;

    Enemy& operator=(const Enemy& obj);
    //Enemy* operator=(Enemy* obj);
    bool operator<(const Enemy& obj) const;
    friend std::ostream& operator<<(std::ostream& stream, const Enemy& obj);
    //friend std::ostream& operator<<(std::ostream& stream, Enemy* obj);
};
