#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

/// <summary>
/// �������� �����.
/// </summary>
struct Stack
{
private:
    /// <summary>
    /// ��������� �� ������ (�����).
    /// </summary>
    int* _buffer;

    /// <summary>
    /// ������ ������.
    /// </summary>
    int _bufferSize;

    /// <summary>
    /// ������ ������� �����.
    /// </summary>
    int _top;

public:
    /// <summary>
    /// ����������� �� ���������.
    /// </summary>
    Stack();

    /// <summary>
    /// ����������� � �������� ��������.
    /// </summary>
    /// <param name="size"></param>
    Stack(int size);

    /// <summary>
    /// ����������.
    /// </summary>
    ~Stack();

    /// <summary>
    /// ��������� �������� � ����.
    /// </summary>
    /// <param name="data"></param>
    void Push(int data);

    /// <summary>
    /// ���������� �������� �� �����.
    /// </summary>
    /// <returns></returns>
    int Pop();

    /// <summary>
    /// �������� �� ������� �����.
    /// </summary>
    /// <returns></returns>
    bool IsEmpty();

    /// <summary>
    /// ��������� ������� �����.
    /// </summary>
    /// <returns></returns>
    int GetSize();

    /// <summary>
    /// ��������� ����������� �����.
    /// </summary>
    /// <returns></returns>
    int GetCapacity();

    /// <summary>
    /// ����� ���� ��������� �������.
    /// </summary>
    void Print();

    /// <summary>
    /// ������������ ������ �����.
    /// </summary>
    void Delete();
};