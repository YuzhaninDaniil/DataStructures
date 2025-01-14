#pragma once

#include "Dictionary.h"

/// <summary>
/// ������� ��� �������� ����� ������ ����� �������������.
/// ������� ����������� � ������������ ���� ������ ����� � ���������� ������ �� ��� ���,
/// ���� �� ����� ������� ���������� ��������.
/// </summary>
/// <returns>��������� ������������� ����� �����.</returns>
int CheckData();

/// <summary>
/// ����� ���-�������.
/// </summary>
/// <param name="dict">�������.</param>
void PrintTable(const Dictionary& dict);

/// <summary>
/// ����� �������.
/// </summary>
/// <param name="dict">�������.</param>
void PrintDictionary(const Dictionary& dict);

/// <summary>
/// ����� ����� �  ���������.
/// </summary>
/// <returns>�����.</returns>
int main();