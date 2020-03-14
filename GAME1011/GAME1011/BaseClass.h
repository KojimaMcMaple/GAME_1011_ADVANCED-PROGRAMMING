#pragma once
#include<iostream>
#include<string>
using namespace std;

class BaseClass
{
public:
	BaseClass() {
		cout << "BaseClass constructor" << endl;
	}
	~BaseClass() {
		cout << "BaseClass destructor" << endl;
	}
};

class DerivedClass : public BaseClass
{
public:
	DerivedClass() {
		cout << "DerivedClass constructor" << endl;
	}
	~DerivedClass() {
		cout << "DerivedClass destructor" << endl;
	}
};

class DerivedClass2 : public DerivedClass
{
public:
	DerivedClass2() {
		cout << "DerivedClass2 constructor" << endl;
	}
	~DerivedClass2() {
		cout << "DerivedClass2 destructor" << endl;
	}
};

