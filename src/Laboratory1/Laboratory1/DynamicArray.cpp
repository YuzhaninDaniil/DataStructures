#include "DynamicArray.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Конструктор по умолчанию.
DynamicArray::DynamicArray() : _size(0), _capacity(4), _array(new int[_capacity]) {}

// Конструктор с заданным начальным размером.
DynamicArray::DynamicArray(int initialCapacity) : _size(0), _capacity(initialCapacity), _array(new int[_capacity]) {}

// Деструктор.
DynamicArray::~DynamicArray()
{
    delete[] _array;
}

// Возвращает размер массива.
int DynamicArray::GetSize()
{
    return _size;
}

// Возвращает вместимость массива.
int DynamicArray::GetCapacity()
{
    return _capacity;
}

// Возвращает массив.
int* DynamicArray::GetArray()
{
    return _array;
}


