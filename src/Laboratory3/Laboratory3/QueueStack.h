#pragma once
#include "Stack.h"

/// <summary>
/// ��������� ������� �� ������ ���� ������.
/// </summary>
struct QueueStack
{
private:
    /// <summary>
    /// ������ ����.
    /// </summary>
    Stack _stack1;

    /// <summary>
    /// ������ ����.
    /// </summary>
    Stack _stack2;

public:
    /// <summary>
    /// ����������� � �������� ������.
    /// </summary>
    /// <param name="size"></param>
    QueueStack(int size);

    /// <summary>
    /// ����������.
    /// </summary>
    ~QueueStack();

    /// <summary>
    /// ���������� �������� � �������.
    /// </summary>
    /// <param name="data"></param>
    void Enqueue(int data);

    /// <summary>
    ///  ���������� �������� �� �������.
    /// </summary>
    /// <returns></returns>
    int Dequeue();

    /// <summary>
    /// ��������, ����� �� �������.
    /// </summary>
    /// <returns></returns>
    bool IsEmpty();

    /// <summary>
    /// ������������ ������ ��� �������.
    /// </summary>
    void Delete();

    /// <summary>
    /// ����� ���� ��������� �������.
    /// </summary>
    void Print();
};