#include "QueueStack.h"

/// <summary>
/// �����������.
/// </summary>
/// <param name="size"></param>
QueueStack::QueueStack(int size) : _stack1(size), _stack2(size) {}

/// <summary>
/// ����������.
/// </summary>
QueueStack::~QueueStack()
{
    Delete();
}

/// <summary>
/// ���������� �������� � �������.
/// </summary>
/// <param name="data"></param>
void QueueStack::Enqueue(int data)
{
    _stack1.Push(data); // ��������� ������� � ������ ����
}

/// <summary>
/// ���������� �������� �� �������.
/// </summary>
/// <returns></returns>
int QueueStack::Dequeue()
{
    if (_stack2.IsEmpty())
    {
        while (!_stack1.IsEmpty())
        {
            _stack2.Push(_stack1.Pop());
        }
    }
    if (_stack2.IsEmpty())
    {
        throw underflow_error("������� �����, ���������� ������� �������.");
    }
    return _stack2.Pop();
}

/// <summary>
/// ��������, ����� �� �������.
/// </summary>
/// <returns></returns>
bool QueueStack::IsEmpty()
{
    return _stack1.IsEmpty() && _stack2.IsEmpty();
}

/// <summary>
/// ������������ ������ ��� �������.
/// </summary>
void QueueStack::Delete()
{
    _stack1.Delete();
    _stack2.Delete();
}

/// <summary>
/// ����� ���� ��������� �������.
/// </summary>
void QueueStack::Print()
{
    std::cout << "����� �������: ";

    // ������� ��������� ���� ��� �������� ���������.
    Stack tempStack(_stack1.GetSize() + _stack2.GetSize());

    // ��������� ��� �������� �� _stack2 �� ��������� ���� ��� �����������.
    while (!_stack2.IsEmpty()) {
        int value = _stack2.Pop();
        std::cout << value << " "; // �������� �������� � ������� FIFO.
        tempStack.Push(value);      // ��������� �������� �������.
    }

    // ������ �������� �������� �� _stack1 � ������� ����������.
    while (!_stack1.IsEmpty()) {
        int value = _stack1.Pop();
        std::cout << value << " "; // ���������� �������� �������� � ������� ����������.
        tempStack.Push(value);      // ��������� �������� �������.
    }

    // ���������� ��� �������� ������� � _stack2 (��� ��� ��� ������ ���� ��������� �������).
    while (!tempStack.IsEmpty()) {
        _stack2.Push(tempStack.Pop());
    }

    std::cout << std::endl;
}
