#include "Orc.h"

Orc::Orc()
{
}

Orc::Orc(string in_name)
{
	name_ = in_name;
}

Orc::~Orc()
{
}

string Orc::kSpecies_ = "ORC";

string Orc::GetName()
{
	return name_;
}

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
