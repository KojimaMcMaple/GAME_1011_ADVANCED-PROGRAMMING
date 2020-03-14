#pragma once
#include <iostream>
#include <string>
#include "KH_Enemy.h"
using namespace std;

class Orc : public Enemy {
private:
    static string kSpecies_;
public:
    Orc();
    Orc(string in_name, int in_health, string in_weapon, string in_armour, string in_taunt);
    Orc(const Orc& enemy_ptr);
    //Orc(Orc* enemy_ptr);
    ~Orc();
    
    void Attack();
    void Defend();
    void Taunt();

    static string GetSpecies();
    string BattleCry();
    static string WarCry();
};
