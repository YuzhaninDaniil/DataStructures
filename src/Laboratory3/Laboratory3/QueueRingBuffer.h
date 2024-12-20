#pragma once
#include "RingBuffer.h"

/// <summary>
/// ��������� ������� �� ������ ���������� ������.
/// </summary>
struct QueueRingBuffer
{
private:
	/// <summary>
	/// ��������� ����� ��� �������.
	/// </summary>
	RingBuffer _ringBuffer;

public:
	/// <summary>
	/// �����������.
	/// </summary>
	/// <param name="size">������ �������.</param>
	QueueRingBuffer(int size);

	/// <summary>
	/// ����������.
	/// </summary>
	~QueueRingBuffer();

	/// <summary>
	/// ���������� �������� � �������.
	/// </summary>
	/// <param name="data">�������� ������.</param>
	void Enqueue(int data);

	/// <summary>
	/// ���������� ������� �������� �� �������.
	/// </summary>
	/// <returns>������ ������� �������.</returns>
	int Dequeue();

	/// <summary>
	/// ��������, ����� �� �������.
	/// </summary>
	/// <returns>True, ���� ������� ������, ����� false.</returns>
	bool IsEmpty();

	/// <summary>
	/// ������������ ������ ��� �������.
	/// </summary>
	void Delete();

	/// <summary>
	/// ����� ���� ��������� �������.
	/// </summary>
	// TODO: �� ������ ���� ������ � �������������
	void Print();
};