#include "Stack.h"

/// <summary>
/// ����������� �� ���������.
/// </summary>
Stack::Stack() : _buffer(nullptr), _bufferSize(0), _top(-1) {}

/// <summary>
/// ����������� � �������� ��������.
/// </summary>
/// <param name="size">������, � ������� ����� ������ ����.</param>
Stack::Stack(int size) : _bufferSize(size), _top(-1)
{
	_buffer = new int[size];
}

/// <summary>
/// ����������.
/// </summary>
Stack::~Stack()
{
	Delete();
}

void Stack::Push(int data)
{
	_buffer[++_top] = data;
	_bufferSize++;
}

/// <summary>
/// ���������� �������� �� �����.
/// </summary>
/// <returns>��������� �� ����.</returns>
int Stack::Pop()
{
	if (IsEmpty())
	{
		throw underflow_error("���� ����, ���������� ������� �������.");
	}

	_bufferSize--;

	return _buffer[_top--];
}

/// <summary>
/// ��������, ���� �� ����.
/// </summary>
/// <returns>True, ���� ������ ���������� �������� = -1, ����� false.</returns>
bool Stack::IsEmpty()
{
	return _top == -1;
}

/// <summary>
/// ��������� ������� �����.
/// </summary>
/// <returns>���������� ������ ���������� ��������.</returns>
int Stack::GetSize()
{
	return _top + 1;
}

/// <summary>
/// ��������� ����������� �����.
/// </summary>
/// <returns>����������� ������.</returns>
int Stack::GetCapacity()
{
	return _bufferSize;
}

/// <summary>
/// ������� �� ������� ����.
/// </summary>
void Stack::Print()
{
	if (IsEmpty())
	{
		cout << "???? ????." << endl;
		return;
	}

	cout << "????? ?????: " << endl;
	for (int i = 0; i <= _top; i++)
	{
		cout << _buffer[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// ������������ ������ �����.
/// </summary>
void Stack::Delete()
{
	delete[] _buffer;
	_buffer = nullptr;
	_bufferSize = 0;
	_top = -1;
}
