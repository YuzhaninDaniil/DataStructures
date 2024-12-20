#pragma once

/// <summary>
/// ��������� ���������� ���������� ����� �������������.
/// </summary>
int CheckData();

/// <summary>
/// ���������� � ������� ���� �����.
/// </summary>
void DisplayStackMenu(Stack& stack);

/// <summary>
/// ���������� � ������� ���� ���������� ������.
/// </summary>
void DisplayRingBufferMenu(RingBuffer& ringBuffer);

/// <summary>
/// ���������� � ������� ���� ������� �� ������ 2 ������.
/// </summary>
void DisplayQueueStackMenu(QueueStack& queueStack);

/// <summary>
/// ���������� � ������� ���� ������� �� ������ ���������� ������.
/// </summary>
void DisplayQueueRingBufferMenu(QueueRingBuffer& queueRingBuffer);

/// <summary>
/// ����� ����� ���������.
/// </summary>
int main();