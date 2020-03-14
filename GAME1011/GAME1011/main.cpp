#include <iostream>
#include <iomanip>
#include "NUMBERARRAY.H"
#include "Length.h"
#include "Inheritance.h"
#include "BaseClass.h"
using namespace std;

const string kDptName[] = { 
	"ARCHEOLOGY",
	"BIOLOGY",
	"COMPUTER_SCIENCE" };

int main()
{
	//// W03
	//NumberArray first(3, 1.5);

	////NumberArray second = first;
	//NumberArray second(4,3.33);

	//first = second; // copy constructor IS NOT CALLED! MUST USE OPERATOR OVERLOAD!
	//
	//first.Print();
	//second.Print();

	//first.SetValue(69.42);

	//first.Print();
	//second.Print();

	//Length first(0), second(0), third(0);
	//int f, i;

	//cout << "Feet & Inches ? ";
	//cin >> f >> i;
	//first.SetLength(f, i);
	//
	//cout << "Feet & Inches #2 ? ";
	//cin >> f >> i;
	//second.SetLength(f, i);

	//third = first + second;
	//cout << third.GetFeet() << " " << third.GetInches();

	//first = ++second;
	//first = second++;
	
	// W04
	Faculty prof("Death", ARCHEOLOGY);
	Student stu("Despair", ARCHEOLOGY, &prof);

	cout << "Prof. " << prof.GetName() << " does " << kDptName[prof.GetDepartment()]  << endl;
	cout << stu.GetName() << "\'s advisor is " << stu.GetAdvisor()->GetName() << endl;

	DerivedClass2 obj;

	const int kNumPeople = 5;
	Person* arr[kNumPeople] = {
		new TFaculty("Death", ART, "Dr."),
		new Student("Despair", ART, NULL),
		new Faculty("Destruction", ART),
		new TFaculty("Sam", TECH, "Prof."),
		new TFaculty("Higgs", TECH, "Sir")
	};

	for (int i = 0; i < kNumPeople; i++)
	{
		cout << arr[i]->GetName() << endl; //WILL USE PERSON METHOD IF NOT VIRTUAL
	}

	const int kNumShape = 2;
	Shape* shape_arr[kNumShape] = {
		new Rect(),
		new Hex()
	};

	int pos_x = 5, pos_y = 15;
	for (int i = 0; i < kNumShape; i++)
	{
		shape_arr[i]->SetPos(pos_x, pos_y);
		pos_x += 10;
		pos_y += 10;
	}

	for (int i = 0; i < kNumShape; i++)
	{
		shape_arr[i]->draw();
	}

	return 0;
}