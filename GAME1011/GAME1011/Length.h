#pragma once
#include <iostream>

class Length
{
private:
	int len_inches;
public:
	Length(int feet, int inches);
	Length(int inches);

	int GetFeet() const;
	int GetInches() const;
	void SetLength(int feet, int inches);
	friend Length operator+(Length a, Length b); //friend because [X]operator+(Len a, Len b), NOT a.operator+(b)
	friend Length operator-(Length a, Length b);
	friend bool operator<(Length a, Length b);
	friend bool operator==(Length a, Length b);

	Length operator++();
	Length operator++(int); //POSTFIX

	// ALWAYS FRIENDS
	friend std::ostream& operator<<(std::ostream& out, Length a);
	friend std::istream& operator>>(std::istream& in, Length &a);

};

