#pragma once

#include <iostream>

using namespace std;

/// <summary>
/// ��������� ��� �������� ���� ����-��������.
/// </summary>
struct Node
{
	/// <summary>
	/// ����.
	/// </summary>
	string key;

	/// <summary>
	/// ��������.
	/// </summary>
	string value;

	/// <summary>
	/// ��������� �� ��������� ����.
	/// </summary>
	Node* next;

	/// <summary>
	/// ����������� �������� ������� (����-��������).
	/// </summary>
	/// <param name="k">����.</param>
	/// <param name="v">��������.</param>
	Node(const string& k, const string v) : key(k), value(v), next(nullptr) {}
};