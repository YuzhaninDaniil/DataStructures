#include "Stack.h"

/// <summary>
/// ����������� �� ���������.
/// </summary>
Stack::Stack() : _buffer(nullptr), _bufferSize(0), _top(-1) {}

/// <summary>
/// ����������� � �������� ��������.
/// </summary>
/// <param name="size"></param>
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

/// <summary>
/// ���������� �������� � ����/
/// </summary>
/// <param name="data"></param>
void Stack::Push(int data)
{
    if (_top >= _bufferSize - 1)
    {
        Resize(_bufferSize * _growthfactor);
    }
    _buffer[++_top] = data;
}

/// <summary>
/// ���������� �������� �� �����.
/// </summary>
/// <returns></returns>
int Stack::Pop()
{
    if (IsEmpty())
    {
        throw underflow_error("���� ����, ���������� ������� �������.");
    }

    if (_top < _bufferSize / 4 && _bufferSize > 1)
    {
        Resize(_bufferSize / _growthfactor); // ��������� ������ �����
    }

    return _buffer[_top--];
}

/// <summary>
/// ��������, ���� �� ����.
/// </summary>
/// <returns></returns>
bool Stack::IsEmpty()
{
    return _top == -1;
}

/// <summary>
/// ��������� ������� �����.
/// </summary>
/// <returns></returns>
int Stack::GetSize()
{
    return _top + 1;
}

/// <summary>
/// ��������� ����������� �����.
/// </summary>
/// <returns></returns>
int Stack::GetCapacity()
{
    return _bufferSize;
}

/// <summary>
/// ����� ���� ��������� �������.
/// </summary>
void Stack::Print()
{
    if (IsEmpty())
    {
        cout << "���� ����." << endl;
        return;
    }

    cout << "����� �����: " << endl;
    for (int i = 0; i <= _top; i++) // ������ �� 0 �� _top
    {
        cout << _buffer[i] << " "; // ������� �������� � ������� ����������
    }
    cout << endl;
}

/// <summary>
/// ������ ������ �����.
/// </summary>
/// <param name="newSize"></param>
void Stack::Resize(int newSize)
{
    int* newBuffer = new int[newSize];
    for (int i = 0; i <= _top; ++i)
    {
        newBuffer[i] = _buffer[i]; 
    }
    delete[] _buffer;
    _buffer = newBuffer;
    _bufferSize = newSize;
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
