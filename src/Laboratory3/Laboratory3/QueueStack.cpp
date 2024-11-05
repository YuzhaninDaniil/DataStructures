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
void QueueStack::Print() {
    std::cout << "����� �������: ";
    // ������� ��������� ����� ��� ������.
    Stack tempStack1(_stack1.GetSize());
    Stack tempStack2(_stack2.GetSize());

    while (!_stack2.IsEmpty())
    {
        int value = _stack2.Pop();
        cout << value << " ";
        tempStack2.Push(value); // ��������� �������� �������.
    }

    // ������ ���������� �������� �� ������� �����, �������� �� � ���������.
    while (!_stack1.IsEmpty())
    {
        int value = _stack1.Pop();
        cout << value << " ";
        tempStack1.Push(value);
    }

    // ���������� ��� �������� �������.
    while (!tempStack2.IsEmpty())
    {
        _stack2.Push(tempStack2.Pop());
    }
    while (!tempStack1.IsEmpty())
    {
        _stack1.Push(tempStack1.Pop());
    }

    cout << std::endl;
}
