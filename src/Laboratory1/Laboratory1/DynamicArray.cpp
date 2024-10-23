#include "DynamicArray.h"
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

// ��������������� ������� ��� ���������� �������.
void DynamicArray::Resize(int newCapacity)
{
	int* newArray = new int[newCapacity];
	for (int i = 0; i < _size; i++)
	{
		newArray[i] = _array[i];
	}
	delete[] _array;
	_array = newArray;
	_capacity = newCapacity;
}

// ��������� ������� � ������.
void DynamicArray::AddElement(int index, int value)
{
	if (index < 0 || index > _size)
	{
		cerr << "Invalid index." << endl;
		return;
	}

	if (_size == _capacity) {
		Resize(_capacity * _growthFactor);
	}

	for (int i = _size; i > index; i--)
	{
		_array[i] = _array[i - 1];
	}
	_array[index] = value;
	_size++;
}

// ������� ������� ������� �� ������������� �������.
void DynamicArray::RemoveByIndex(int index)
{
	if (index < 0 || index >= _size)
	{
		cerr << "Invalid index." << endl;
		return;
	}

	for (int i = index; i < _size - 1; i++)
	{
		_array[i] = _array[i + 1];
	}
	_size--;

	// �������� ������� ��� ���������� ������� �������
	if (_capacity / _size >= _growthFactor)
	{
		Resize(_capacity / _growthFactor);
	}
}

// ������� �������� �������� �� ��� ������������� ��������.
void DynamicArray::RemoveByValue(int value)
{
	for (int i = 0; i < _size; i++)
	{
		if (_array[i] == value)
		{
			RemoveByIndex(i);
			return;
		}
	}
	cerr << "Value " << value << " Was not found in array." << endl;
}

// ���������� ������� �� �������.
int DynamicArray::GetElement(int index)
{
	if (index < 0 || index >= _size) {
		cerr << "Invalid index." << endl;
		return -1;
	}
	return _array[index];
}


void DynamicArray::SortArray()
{
	int index = 0;

	while (index < _size)
	{
		if (index == 0)
		{
			index++;
		}
		// ���� ������� ������� ������ ��� ����� ����������
		if (index < _size && _array[index] >= _array[index - 1])
		{
			index++;
		}
		else
		{
			// ���� ������� ������� ������, �� ������ �������
			int temp = _array[index];
			_array[index] = _array[index - 1];
			_array[index - 1] = temp;
			index--;
		}
	}
}

// �������� ����� ������� �������� �� ������������� ��������.
void DynamicArray::LinearSearch(int value)
{
	for (int i = 0; i < _size; i++)
	{
		if (_array[i] == value)
		{
			cout << "The index of element " << value << ": " << i << endl;
			return;
		}
	}
	cout << "The element " << value << " was not found in the array." << endl;
}

// �������� ����� ������� �������� �� ������������� ��������.
void DynamicArray::BinarySearch(int value)
{
	int left = 0;
	int right = _size - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (_array[middle] == value)
		{
			cout << "Element index: " << middle << endl;
			return;
		}
		else if (_array[middle] < value)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}
	cout << "The element " << value << " was not found in the array." << endl;
}


