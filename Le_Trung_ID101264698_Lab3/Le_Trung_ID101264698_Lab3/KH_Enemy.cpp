#include "KH_ENEMY.H"

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

//Enemy::Enemy(Enemy* enemy_ptr)
//{
//	SetName(enemy_ptr->name_);
//	SetHealth(enemy_ptr->health_);
//	SetWeapon(enemy_ptr->weapon_);
//	SetArmour(enemy_ptr->armour_);
//	SetTaunt(enemy_ptr->taunt_);
//}

Enemy::~Enemy()
{
}

string Enemy::GetName() const
{
	return name_;
}

int Enemy::GetHealth() const
{
	return health_;
}

string Enemy::GetWeapon() const
{
	return weapon_;
}

string Enemy::GetArmour() const
{
	return armour_;
}

string Enemy::GetTaunt() const
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

Enemy& Enemy::operator=(const Enemy& obj)
{
	SetName(obj.GetName());
	SetHealth(obj.GetHealth());
	SetWeapon(obj.GetWeapon());
	SetArmour(obj.GetArmour());
	SetTaunt(obj.GetTaunt());
	
	return *this;
}

//Enemy* Enemy::operator=(Enemy* obj)
//{
//	SetName(obj->GetName());
//	SetHealth(obj->GetHealth());
//	SetWeapon(obj->GetWeapon());
//	SetArmour(obj->GetArmour());
//	SetTaunt(obj->GetTaunt());
//	
//	return this;
//}

bool Enemy::operator<(const Enemy& obj) const
{
	if (GetHealth() < obj.GetHealth()) {
		return true;
	}
	return false;
}

// [Q] Why use "Enemy* obj" instead of "const Enemy& obj" ???
std::ostream& operator<<(std::ostream& stream, const Enemy& obj) 
{
	stream << obj.GetName() << ":" << obj.GetHealth();
	return stream;
}

//std::ostream& operator<<(std::ostream& stream, Enemy* obj) 
//{
//	stream << obj->GetName() << ":" << obj->GetHealth();
//	return stream;
//}