#pragma once
class NumberArray
{
private:
	double* ptr;
	int arr_size;
public:
	NumberArray(const NumberArray&);
	NumberArray(int size, double value);
	~NumberArray();
	
	void Print() const;
	void SetValue(double value);

	NumberArray& operator=(const NumberArray& right); //NumberArray& is the return type, can be used for a=b=c=d
	//void operator=(const NumberArray& right); //void is the return type, can be used for a=b
};

