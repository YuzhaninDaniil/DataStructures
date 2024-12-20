#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

/// <summary>
/// ��������� ���������� ������.
/// </summary>
struct RingBuffer
{
private:
	/// <summary>
	/// ��������� �� �����.
	/// </summary>
	int* _buffer;

	/// <summary>
	/// ������������ ������ ������.
	/// </summary>
	int _bufferSize;

	/// <summary>
	/// ������ ��� ���������� ��������.
	/// </summary>
	int _head;

	/// <summary>
	/// ������ ��� ���������� ��������.
	/// </summary>
	int _tail;

	/// <summary>
	/// ������� ������ ������������ ������.
	/// </summary>
	int _currentSize;

	/// <summary>
	/// ������ �����.
	/// </summary>
	int _growthFactor = 2;

public:
	/// <summary>
	/// �����������.
	/// </summary>
	/// <param name="size">������ ���������� ������.</param>
	RingBuffer(int size);

	/// <summary>
	/// ����������.
	/// </summary>
	~RingBuffer();

	/// <summary>
	/// ���������� �������� � ��������� �����.
	/// </summary>
	/// <param name="data">�������, ����������� � ��������� �����.</param>
	void Add(int data);

	/// <summary>
	/// ���������� �������� �� ���������� ������.
	/// </summary>
	/// <returns>������� ��������� ������� ���������� ������.</returns>
	int Remove();

	/// <summary>
	/// ����������� ������ ���������� ������.
	/// </summary>
	void Resize();

	/// <summary>
	/// ��������, ������ �� ��������� �����.
	/// </summary>
	/// <returns>True, ���� ��������� ����� �����, ����� false.</returns>
	bool IsFull();

	/// <summary>
	/// ��������, ���� �� ��������� �����.
	/// </summary>
	/// <returns>True, ���� ��������� ����� ����, ����� false.</returns>
	bool IsEmpty();

	/// <summary>
	/// ��������� �������� ������� ������.
	/// </summary>
	/// <returns>���������� ������� ������ ������.</returns>
	int Size();

	/// <summary>
	/// ����� ���� ��������� ���������� ������.
	/// </summary>
	void Print();

	/// <summary>
	/// ������������ ������ ���������� ������.
	/// </summary>
	void Delete();

	/// <summary>
	/// ���������� ���������� ���������� ����� � ��������� ������.
	/// </summary>
	int FreeSpace();

	/// <summary>
	/// ���������� ����������� ������.
	/// </summary>
	/// <returns>���������� ����� ����������� ���������� ������.</returns>
	int GetBufferSize();
};