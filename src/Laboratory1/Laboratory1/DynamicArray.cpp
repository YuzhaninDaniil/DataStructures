#include "DynamicArray.h"
#include <algorithm>
#include <iostream>

using namespace std;

// ����������� �� ���������.
DynamicArray::DynamicArray() : _size(0), _capacity(4), _array(new int[_capacity]) {}

// ����������� � �������� ��������� ��������.
DynamicArray::DynamicArray(int initialCapacity) : _size(0), _capacity(initialCapacity), _array(new int[_capacity]) {}

// ����������.
DynamicArray::~DynamicArray()
{
    delete[] _array;
}

// ���������� ������ �������.
int DynamicArray::GetSize()
{
    return _size;
}

// ���������� ����������� �������.
int DynamicArray::GetCapacity()
{
    return _capacity;
}

// ���������� ������.
int* DynamicArray::GetArray()
{
    return _array;
}


