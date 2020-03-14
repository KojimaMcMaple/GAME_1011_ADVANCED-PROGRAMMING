#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Discipline {
	ART, 
	TECH,
	ARCHEOLOGY,
	BIOLOGY,
	COMPUTER_SCIENCE
};

class Person
{
protected:
	string name;
public:
	Person() {
		SetName(" ");
	}
	Person(string name) {
		SetName(name);
	}
	virtual string GetName() const { //IF NOT VIRTUAL, DERIVED CLASSES WILL USE THIS METHOD INSTEAD OF THEIR METHODS
		return name;
	}
	void SetName(string name) {
		this->name = name;
	}
};

class Student :public Person {
private:
	Discipline major;
	Person* advisor;
public:
	//prototype
	Student(string name, Discipline major, Person* advisor) : Person(name) { //PASS name USING PARENT CLASS Person
		//this->name = name; //must use PROTECTED
		//SetName(name); //works everytime but be careful when using this in constructor

		this->major = major;
		this->advisor = advisor;
	}

	Discipline GetMajor() const {
		return major;
	}

	void SetMajor(Discipline major) {
		this->major = major;
	}

	Person* GetAdvisor() const {
		return advisor;
	}

	void SetAdvisor(Person* advisor) {
		this->advisor = advisor;
	}
};

class Faculty :public Person {
private:
	Discipline department;
public:
	//prototype
	Faculty(string name, Discipline department) {
		this->name = name; //must use PROTECTED

		this->department = department;
	}

	Discipline GetDepartment() const {
		return department;
	}

	void SetDepartment(Discipline department) {
		this->department = department;
	}
};

class TFaculty :public Faculty {
private:
	string title;
public:
	//prototype
	TFaculty(string name, Discipline department, string title) : Faculty(name, department) {
		SetTitle(title);
	}

	string GetTitle() const {
		return title;
	}

	void SetTitle(string title) {
		this->title = title;
	}

	string GetName() const {
		return title + " " + Person::GetName();
	}
};




class Shape {
protected:
	int pos_x, pos_y;
public:
	void SetPos(int x, int y) {
		pos_x = x;
		pos_y = y;
	}

	virtual void draw() const = 0; //pure virtual method will make Shape an abstract class
};

class Rect :public Shape {
public:
	virtual void draw() const {
		cout << "Drawing rect at " << pos_x << " " << pos_y << endl;
	}
};
class Hex :public Shape {
public:
	virtual void draw() const {
		cout << "Drawing hex at " << pos_x << " " << pos_y << endl;
	}
};