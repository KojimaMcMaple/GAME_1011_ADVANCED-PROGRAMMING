#include "LE_TRUNG_ID101264698_LAB2_ENEMY.H"

Enemy::Enemy()
{
}

//[Q] How to inherit constructors for derived classes ?
Enemy::Enemy(string in_name, int in_health, string in_weapon, string in_armour, string in_taunt)
{
	SetName(in_name);
	SetHealth(in_health);
	SetWeapon(in_weapon);
	SetArmour(in_armour);
	SetTaunt(in_taunt);
}

Enemy::Enemy(const Enemy& enemy_ptr)
{
	SetName(enemy_ptr.name_);
	SetHealth(enemy_ptr.health_);
	SetWeapon(enemy_ptr.weapon_);
	SetArmour(enemy_ptr.armour_);
	SetTaunt(enemy_ptr.taunt_);
}

Enemy::~Enemy()
{
}

string Enemy::GetName()
{
	return name_;
}

int Enemy::GetHealth()
{
	return health_;
}

string Enemy::GetWeapon()
{
	return weapon_;
}

string Enemy::GetArmour()
{
	return armour_;
}

string Enemy::GetTaunt()
{
	return taunt_;
}

void Enemy::SetName(string in_str)
{
	name_ = in_str;
}

void Enemy::SetHealth(int in_int)
{
	health_ = in_int;
}

void Enemy::SetWeapon(string in_str)
{
	weapon_ = in_str;
}

void Enemy::SetArmour(string in_str)
{
	armour_ = in_str;
}

void Enemy::SetTaunt(string in_str)
{
	taunt_ = in_str;
}
