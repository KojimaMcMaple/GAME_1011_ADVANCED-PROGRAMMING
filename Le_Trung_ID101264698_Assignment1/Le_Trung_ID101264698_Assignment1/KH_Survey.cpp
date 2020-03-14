#include "KH_Survey.h"

int KH_Survey::num_of_class_objs = 0;

KH_Survey::KH_Survey()
{
	num_of_class_objs++;
}

KH_Survey::~KH_Survey()
{
}

string KH_Survey::GetName() const
{
	return name;
}

void KH_Survey::SetName(string in_name)
{
	name = in_name;
}

double KH_Survey::GetHours() const
{
	return hours;
}

void KH_Survey::SetHours(double in_hours)
{
	hours = in_hours;
}