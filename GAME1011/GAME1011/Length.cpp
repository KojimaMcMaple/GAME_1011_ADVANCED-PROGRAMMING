#include "Length.h"

Length::Length(int feet, int inches)
{
	SetLength(feet, inches);
}

Length::Length(int inches)
{
	len_inches = inches;
}

int Length::GetFeet() const
{
	return len_inches/12;
}

int Length::GetInches() const
{
	return len_inches%12;
}

void Length::SetLength(int feet, int inches)
{
	len_inches = 12 * feet + inches;
}

Length Length::operator++()
{
	len_inches++;
	return *this;
}

Length Length::operator++(int)
{
	Length temp = *this;
	len_inches++;
	return temp;
}

//std::ostream& operator<<(std::ostream& out, Length a) {
//
//}
//
//std::istream& operator>>(std::istream& in, Length& a) {
//
//}

Length operator+(Length a, Length b)
{
	return Length(a.len_inches + b.len_inches);
}

Length operator-(Length a, Length b)
{
	return Length(a.len_inches - b.len_inches);
}

bool operator<(Length a, Length b)
{
	return a.len_inches < b.len_inches;
}

bool operator==(Length a, Length b)
{
	return a.len_inches == b.len_inches;
}
