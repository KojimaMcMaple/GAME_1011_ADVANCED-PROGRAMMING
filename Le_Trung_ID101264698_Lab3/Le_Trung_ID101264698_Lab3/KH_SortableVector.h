#pragma once
#include <iostream>

template <class T>
class KH_SortableVector
{
private:
    T* vect_ptr;
    int vect_size;
    void SubscriptErr() const; // Handles subscripts out of range
public:
    KH_SortableVector(int);
    KH_SortableVector(const KH_SortableVector&);
    ~KH_SortableVector();
    int Size() const;
    void Print() const;
    void Sort();
    T& operator[](int);
};

template<class T>
void KH_SortableVector<T>::SubscriptErr() const
{
    std::cout << "ERROR: Subscript out of range.\n";
    exit(0);
}

template<class T>
KH_SortableVector<T>::KH_SortableVector(int size)
{
    vect_size = size;
    vect_ptr = new T[vect_size];
    for (int i = 0; i < vect_size; i++) {
        vect_ptr[i] = T();
    }
}

template<class T>
KH_SortableVector<T>::KH_SortableVector(const KH_SortableVector& in_vect)
{
    vect_size = in_vect.vect_size;
    vect_ptr = new T[vect_size];
    for (int i = 0; i < vect_size; i++) {
        vect_ptr[i] = in_vect[i];
    }
}

template<class T>
KH_SortableVector<T>::~KH_SortableVector()
{
    if (vect_size > 0) {
        delete[] vect_ptr;
    }
}

template<class T>
int KH_SortableVector<T>::Size() const
{
    return vect_size;
}

template<class T>
void KH_SortableVector<T>::Print() const
{
    for (int i = 0; i < vect_size; i++) {
        std::cout << vect_ptr[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
void KH_SortableVector<T>::Sort()
{
    int i, j, min;
    T temp;
    for (i = 0; i < vect_size - 1; i++) {
        min = i;
        for (j = i + 1; j < vect_size; j++) {
            if (vect_ptr[j] < vect_ptr[min]) {
                min = j;
            }
        }
        temp = vect_ptr[i];
        vect_ptr[i] = vect_ptr[min];
        vect_ptr[min] = temp;
    }
}

template<class T>
T& KH_SortableVector<T>::operator[](int index)
{
    // TODO: insert return statement here
    if (index < 0 || index >= vect_size) {
        SubscriptErr();
    }
    return vect_ptr[index];
}

//#ifndef SIMPLEVECTOR_H
//#define SIMPLEVECTOR_H
//
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//template <class T>
//class SimpleVector
//{
//private:
//    T* aptr;
//    int arraySize;
//    void subError() const;       // Handles subscripts out of range
//public:
//    SimpleVector(int);                   // Constructor
//    SimpleVector(const SimpleVector&);  // Copy constructor
//    ~SimpleVector(); 	                // Destructor
//    int size() const
//    {
//        return arraySize;
//    }
//    T& operator[](int);    // Overloaded [] operator
//    void print() const;          // outputs the array elements
//};
//
////*******************************************************
//// Constructor for SimpleVector class. Sets the size    *
//// of the array and allocates memory for it.            *
////*******************************************************
//template <class T>
//SimpleVector<T>::SimpleVector(int s)
//{
//    arraySize = s;
//    aptr = new T[s];
//    for (int count = 0; count < arraySize; count++)
//        aptr[count] = T();
//}
////******************************************************
//// Copy Constructor for SimpleVector class.            *
////******************************************************
//template <class T>
//SimpleVector<T>::SimpleVector(const SimpleVector& obj)
//{
//    arraySize = obj.arraySize;
//    aptr = new T[arraySize];
//    for (int count = 0; count < arraySize; count++)
//        aptr[count] = obj[count];
//}
////*****************************************************
//// Destructor for SimpleVector class.                 *
////*****************************************************
//template <class T>
//SimpleVector<T>::~SimpleVector()
//{
//    if (arraySize > 0)
//        delete[] aptr;
//}
//
////******************************************************
//// subError function. Displays an error message and    *
//// terminates the program when a subscript is out of   *
//// range.                                              *
////******************************************************
//template <class T>
//void SimpleVector<T>::subError() const
//{
//    cout << "ERROR: Subscript out of range.\n";
//    exit(0);
//}
////*******************************************************
//// Overloaded [] operator. The argument is a subscript. *
//// This function returns a reference to the element     *
//// in the array indexed by the subscript.               *
////*******************************************************
//template <class T>
//T& SimpleVector<T>::operator[](int sub)
//{
//    if (sub < 0 || sub >= arraySize)
//        subError();
//    return aptr[sub];
//}
////********************************************************
//// prints all the entries is the array.                  *
////********************************************************
//template <class T>
//void SimpleVector<T>::print() const
//{
//    for (int k = 0; k < arraySize; k++)
//        cout << aptr[k] << "  ";
//    cout << endl;
//}
//#endif

