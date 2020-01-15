#pragma once
#include <iostream>
#include <string>
using namespace std;

class Orc {
private:
    string name_;
    static string kSpecies_;
public:
    Orc();
    Orc(string in_name);
    ~Orc();
    
    string GetName();
    static string GetSpecies();
    string BattleCry();
    static string WarCry();
};
