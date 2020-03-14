#pragma once

#include <string>
using namespace std;

class KH_Survey
{
private:
	string name;
	double hours;
	static int num_of_class_objs;
public:
	KH_Survey();
	~KH_Survey();

	string GetName() const;
	void SetName(string in_name);
	double GetHours() const;
	void SetHours(double in_hours);

};

