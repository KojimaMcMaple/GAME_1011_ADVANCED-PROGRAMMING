#include <iostream>

#include "Le_Trung_ID101264698_Lab2_Orc.h"

int main() {
	Orc* orc_ptr = nullptr;

	const int kOrcSize = 2;
	orc_ptr = new Orc[kOrcSize];

	orc_ptr[0] = Orc("Sam Bridges", 80, "Tactical Nuke", "Force Field", "The Floss");
	cout << "Initiating cloning sequence..." << endl;
	orc_ptr[1] = orc_ptr[0];
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
	system("pause");
	return 0;
}