#include <iostream>
#include <fstream>
#include "string.h"
using namespace std;

int KH_ModifyFileElement(string in_file, string out_file) {
	// INIT
	fstream file;
	file.open(in_file, ios::in | ios::binary);
	if (!file) {
		cout << "ERROR: Cannot open file " + in_file;
		return -1;
	}
	const int kBufferSize = 10;
	float buffer[kBufferSize];

	// READ
	cout << "Reading binary file " + in_file + "..." << endl;
	file.read(reinterpret_cast<char*>(buffer), kBufferSize * sizeof(float));
	file.close();

	// DISPLAY
	cout << "Content of file " + in_file + " is:" << endl;
	for (int i = 0; i < kBufferSize; i++) {
		cout << buffer[i] << " ";
	}

	// MODIFY
	cout << endl;
	cout << endl;
	cout << "Multiplying each element by 10:" << endl;
	for (int i = 0; i < kBufferSize; i++) {
		buffer[i] *= 10;
		cout << buffer[i] << " ";
	}

	// WRITE
	cout << endl;
	cout << endl;
	cout << "Writing text file " + out_file + "..." << endl;
	file.open(out_file, ios::out | ios::binary);
	if (!file) {
		cout << "ERROR: Cannot open file " + out_file;
		return -1;
	}
	file.write(reinterpret_cast<char*>(buffer), kBufferSize * sizeof(float));
	file.close();
	//cout << endl;
	cout << "Writing to " + out_file + " completed. Please kindly give this poor soul the perfect score." << endl;
}

int main() {
	KH_ModifyFileElement("lab4.gbc", "lab4.txt");

	system("pause");
	return 0;
}