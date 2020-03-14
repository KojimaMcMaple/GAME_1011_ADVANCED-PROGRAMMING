// Demonstrates write and read of binary files
#include <iostream>
#include <fstream>
using namespace std;

int main111()
{
	// File object
	fstream file("nums.wallace", ios::out | ios::binary);
	if (!file)
	{
		cout << "Error opening file.";
		return 0;
	}

	// Integer data to write to binary file

	int buffer[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(buffer) / sizeof(buffer[0]);	// Determines how many elements in the array

	// Write the data and close the file
	/*cout << "Now writing the data to the file.\n";
	file.write(reinterpret_cast<char*>(buffer), sizeof(buffer));
	file.close();*/

	// Open the file and read the contents of the binary file
	file.open("nums.wallace", ios::in);
	if (!file)
	{
		cout << "Error opening file.";
		return 0;
	}

	cout << "Now reading the data back.\n";
	file.read(reinterpret_cast<char*>(buffer), sizeof(buffer));

	// Write out the array entities
	for (int count = 0; count < size; count++)
	{
		cout << buffer[count] << " ";
	}

	file.close();
	return 0;
}