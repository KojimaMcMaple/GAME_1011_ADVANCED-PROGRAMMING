#include <iostream>

#include "KH_Orc.h"
#include "KH_SortableVector.h"

void KH_Lab2() {
	Orc* orc_ptr = nullptr;

	const int kOrcSize = 3;
	orc_ptr = new Orc[kOrcSize];

	orc_ptr[0] = Orc("Sam Bridges", 80, "Tactical Nuke", "Force Field", "The Floss");
	orc_ptr[1] = Orc("Fragile", 10, "Leviathan Axe", "Spartan Shield", "The F Bomb");
	cout << "Initiating cloning sequence..." << endl;
	orc_ptr[2] = orc_ptr[0];
	cout << "Cloning successful. Testing result: " << endl;
	cout << endl;

	for (int i = 0; i < kOrcSize; i++) {
		cout << "#" << i << endl;
		cout << "Name: " << orc_ptr[i].GetName() << endl;
		cout << "Health: " << orc_ptr[i].GetHealth() << endl;
		cout << "Weapon: " << orc_ptr[i].GetWeapon() << endl;
		cout << "Armour: " << orc_ptr[i].GetArmour() << endl;
		cout << "Taunt: " << orc_ptr[i].GetTaunt() << endl;
		cout << "Attack: ";
		orc_ptr[i].Attack();
		cout << "Defend: ";
		orc_ptr[i].Defend();
		cout << "Taunt: ";
		orc_ptr[i].Taunt();
	}

	cout << endl;
	cout << "Now using nanomachines to change original subject. Testing result: " << endl;
	orc_ptr[0].SetName("Higgs");
	orc_ptr[0].SetHealth(50);
	orc_ptr[0].SetWeapon("AK-47");
	orc_ptr[0].SetArmour("Gundanium Alloy");
	orc_ptr[0].SetTaunt("The FLOP");

	for (int i = 0; i < kOrcSize; i++) {
		cout << "#" << i << endl;
		cout << "Name: " << orc_ptr[i].GetName() << endl;
		cout << "Health: " << orc_ptr[i].GetHealth() << endl;
		cout << "Weapon: " << orc_ptr[i].GetWeapon() << endl;
		cout << "Armour: " << orc_ptr[i].GetArmour() << endl;
		cout << "Taunt: " << orc_ptr[i].GetTaunt() << endl;
		cout << "Attack: ";
		orc_ptr[i].Attack();
		cout << "Defend: ";
		orc_ptr[i].Defend();
		cout << "Taunt: ";
		orc_ptr[i].Taunt();
	}

	delete[] orc_ptr;
}

int main() {
	const int kVectSize = 5;
	KH_SortableVector<int> int_sort_vect(kVectSize);
	int_sort_vect[0] = 10;
	int_sort_vect[1] = 1200;
	int_sort_vect[2] = 644;
	int_sort_vect[3] = 69;
	int_sort_vect[4] = 8;
	std::cout << "- int_sort_vect before sort: ";
	int_sort_vect.Print();
	int_sort_vect.Sort();
	std::cout << "- int_sort_vect AFTER sort:  ";
	int_sort_vect.Print();

	KH_SortableVector<string> str_sort_vect(kVectSize);
	str_sort_vect[0] = "bbb";
	str_sort_vect[1] = "AAA";
	str_sort_vect[2] = "aaa";
	str_sort_vect[3] = "metal gear";
	str_sort_vect[4] = "101264698";
	std::cout << "- str_sort_vect before sort: ";
	str_sort_vect.Print();
	str_sort_vect.Sort();
	std::cout << "- str_sort_vect AFTER sort:  ";
	str_sort_vect.Print();

	KH_SortableVector<Orc> orc_ptr(kVectSize);
	orc_ptr[0] = Orc("Sam Bridges", 80, "Tactical Nuke", "Force Field", "The Floss");
	orc_ptr[1] = Orc("Kratos", 10, "Leviathan Axe", "Spartan Shield", "Roar");
	orc_ptr[2] = Orc("Nero", 15, "Red Queen", "Punchline", "The F Bomb");
	orc_ptr[3] = Orc("The Hunter", 88, "Rakuyo", "Loch Shield", "Make Contact");
	orc_ptr[4] = Orc("Higgs", 50, "AK-47", "Gundanium Alloy", "The FLOP");
	//[Q] How to do COPY CONSTRUCTOR here ?
	//orc_ptr[4] = orc_ptr[0];
	//orc_ptr[0]->SetName("Higgs");
	//orc_ptr[0]->SetHealth(50);
	//orc_ptr[0]->SetWeapon("AK-47");
	//orc_ptr[0]->SetArmour("Gundanium Alloy");
	//orc_ptr[0]->SetTaunt("The FLOP");
	std::cout << "- orc_ptr before sort: ";
	orc_ptr.Print();
	orc_ptr.Sort();
	std::cout << "- orc_ptr AFTER sort:  ";
	orc_ptr.Print();

	system("pause");
	return 0;
}