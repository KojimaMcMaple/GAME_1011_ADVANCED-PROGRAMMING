#include <iostream>

#include "Orc.h"

int main() {
	Orc* orc_ptr = nullptr;

	const int kOrcSize = 3;
	orc_ptr = new Orc[kOrcSize];

	orc_ptr[0] = Orc("Sam Porter Bridges");
	orc_ptr[1] = Orc("Fragile");
	orc_ptr[2] = Orc("Higgs");

	for (int i = 0; i < kOrcSize; i++) {
		cout << orc_ptr[i].BattleCry() << endl;
	}

	cout << orc_ptr[0].WarCry() << endl;

	delete[] orc_ptr;
	system("pause");
	return 0;
}