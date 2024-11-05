#include "RingBuffer.h"

/// <summary>
/// �����������.
/// </summary>
/// <param name="size"></param>
RingBuffer::RingBuffer(int size) : _bufferSize(size), _head(0), _tail(0), _currentSize(0)
{
    _buffer = new int[size];
}

/// <summary>
/// ����������.
/// </summary>
RingBuffer::~RingBuffer()
{
    Delete();
}

/// <summary>
/// ���������� �������� � ��������� �����.
/// </summary>
/// <param name="data"></param>
void RingBuffer::Add(int data)
{
    if (IsFull())
    {
        throw overflow_error("��������� ����� ����������, ���������� �������� �������.");
    }
    _buffer[_head] = data;
    _head = (_head + 1) % _bufferSize;
    _currentSize++;
}

/// <summary>
/// ���������� �������� �� ���������� ������.
/// </summary>
/// <returns></returns>
int RingBuffer::Remove()
{
    if (IsEmpty())
    {
        throw underflow_error("��������� ����� ����, ���������� ������� �������.");
    }
    int data = _buffer[_tail];
    _tail = (_tail + 1) % _bufferSize;
    _currentSize--;
    return data;
}

/// <summary>
/// ��������, ������ �� ��������� �����.
/// </summary>
/// <returns></returns>
bool RingBuffer::IsFull()
{
    return _currentSize == _bufferSize;
}

/// <summary>
/// ��������, ���� �� ��������� �����.
/// </summary>
/// <returns></returns>
bool RingBuffer::IsEmpty()
{
    return _currentSize == 0;
}

/// <summary>
/// ��������� �������� ������� ���������� ������.
/// </summary>
/// <returns></returns>
int RingBuffer::Size()
{
    return _currentSize;
}

/// <summary>
/// ����� ���� ��������� ���������� ������.
/// </summary>
void RingBuffer::Print()
{
    if (IsEmpty())
    {
        cout << "��������� ����� ����." << endl;
        return;
    }

    cout << "����� ���������� ������: ";
    for (int i = 0; i < _currentSize; ++i)
    {
        cout << _buffer[(_tail + i) % _bufferSize] << " ";
    }
    cout << endl;
}

/// <summary>
/// ������������ ������ ���������� ������.
/// </summary>
void RingBuffer::Delete() {
    delete[] _buffer;
    _buffer = nullptr;
    _bufferSize = 0;
    _head = 0;
    _tail = 0;
    _currentSize = 0;
}