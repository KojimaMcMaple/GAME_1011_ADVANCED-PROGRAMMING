#include "Le_Trung_ID101264698_Lab2_Orc.h"

Orc::Orc()
{
}

Orc::Orc(string in_name, int in_health, string in_weapon, string in_armour, string in_taunt)
{
	SetName(in_name);
	SetHealth(in_health);
	SetWeapon(in_weapon);
	SetArmour(in_armour);
	SetTaunt(in_taunt);
}

Orc::Orc(const Orc& enemy_ptr)
{
	SetName(enemy_ptr.name_);
	SetHealth(enemy_ptr.health_);
	SetWeapon(enemy_ptr.weapon_);
	SetArmour(enemy_ptr.armour_);
	SetTaunt(enemy_ptr.taunt_);
}

Orc::~Orc()
{
}

void Orc::Attack()
{
	std::cout << GetSpecies() + " " + GetName() + " is attacking with " + GetWeapon() + "!" << std::endl;
}

void Orc::Defend()
{
	std::cout << GetSpecies() + " " + GetName() + " is defending with " + GetArmour() + "!" << std::endl;
}

void Orc::Taunt()
{
	std::cout << GetSpecies() + " " + GetName() + " is taunting with " + GetTaunt() + "!" << std::endl;
}

string Orc::kSpecies_ = "ORC";

string Orc::GetSpecies()
{
	return kSpecies_;
}

string Orc::BattleCry()
{
	return ("I am " + GetName() + ", and I am a proud " + GetSpecies() + "!");
}

string Orc::WarCry()
{
	return "*A grunt sound*";
}
