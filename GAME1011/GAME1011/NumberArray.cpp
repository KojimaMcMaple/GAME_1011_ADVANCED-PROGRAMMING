#include <iostream>
#include "NumberArray.h"

NumberArray::NumberArray(const NumberArray& obj)
{
	arr_size = obj.arr_size;
	ptr = new double[arr_size];

	for (int i = 0; i < arr_size; ++i)
	{
		ptr[i] = obj.ptr[i];
	}
}

NumberArray::NumberArray(int size, double value)
{
	arr_size = size;
	ptr = new double[arr_size];
	SetValue(value);
}

NumberArray::~NumberArray()
{
	if (arr_size > 0)
	{
		delete[] ptr;
	}
}

void NumberArray::Print() const
{
	for (int i=0;i<arr_size;i++)
	{
		std::cout << ptr[i] << " ";
	}
	std::cout << std::endl;
}

void NumberArray::SetValue(double value)
{
	for (int i = 0; i < arr_size; i++)
	{
		ptr[i] = value;
	}
}

NumberArray& NumberArray::operator=(const NumberArray& right)
{
	// AVOID: x = x;
	if ( this != &right) //compare memory location of "this" to "right"
	{
		// REPLACE: DELETE ARR IF EXISTING
		if(arr_size>0)
		{
			delete[] ptr;
		}

		arr_size = right.arr_size;
		ptr = new double[arr_size];
		for (int i = 0; i < arr_size; i++)
		{
			ptr[i] = right.ptr[i];
		}
	}

	return *this;
}
