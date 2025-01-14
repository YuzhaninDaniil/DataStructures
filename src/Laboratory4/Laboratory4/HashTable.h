#pragma once

#include <iostream>
#include "Node.h"

/// <summary>
/// ��������� ������ ������� ��� �������������.
/// </summary>
const size_t InitialTableSize = 10;

/// <summary>
/// ������������ ����������� ���������� ������� (load factor) ��� �������������.
/// </summary>
const double MaxLoadFactor = 0.75;

/// <summary>
/// ������ ���������, ������������ � ���-������� (������ ����� �������).
/// </summary>
const size_t HashConstant1 = 1664525;

/// <summary>
/// ������ ���������, ������������ � ���-������� (������ ����� �������).
/// </summary>
const size_t HashConstant2 = 1013904223;

/// <summary>
/// ����� HashTable ��������� ���-�������.
/// </summary>
class HashTable
{
private:
	/// <summary>
	/// ���-������� (������ ���������� �� ������).
	/// </summary>
	Node** _table;

	/// <summary>
	/// ������ �������.
	/// </summary>
	size_t _size;

	/// <summary>
	/// ������������ ���������� ����������.
	/// </summary>
	double _maxLoadFactor;

	/// <summary>
	/// ������� ���������� ���������.
	/// </summary>
	size_t _count;

	/// <summary>
	/// ���-������� (������ ����� �������).
	/// </summary>
	/// <param name="key">����.</param>
	/// <returns>��� � ���� �����.</returns>
	size_t static GetHash(std::string key);

	/// <summary>
	/// �������������� � ������ �������.
	/// </summary>
	/// <param name="hash">��� � ���� �����.</param>
	/// <returns>������ �������.</returns>
	size_t GetIndex(std::string key) const;

	/// <summary>
	/// ���������������
	/// </summary>
	void Rehash();
public:
	/// <summary>
	/// ����������� ���-�������.
	/// </summary>
	/// <param name="initialSize">������ �������.</param>
	/// <param name="loadFactor">������������ ���������� ����������.</param>
	HashTable(size_t initialSize = InitialTableSize, double loadFactor = MaxLoadFactor);

	/// <summary>
	/// ������������� ���-�������.
	/// </summary>
	~HashTable();

	/// <summary>
	/// ��������� ������� � ���-�������.
	/// </summary>
	/// <param name="key">����.</param>
	/// <param name="value">�������� ��������.</param>
	void Insert(const string& key, const std::string& value);

	/// <summary>
	/// �������� �������� �� �����.
	/// </summary>
	/// <param name="key">����.</param>
	void Remove(const string& key);

	/// <summary>
	/// ����� �������� �� �����.
	/// </summary>
	/// <param name="key">����.</param>
	/// <returns>������� ��������.</returns>
	 string Find(const string& key);

	/// <summary>
	/// ���������� ������ �������.
	/// </summary>
	/// <returns>������ �������.</returns>
	size_t GetSize() const;

	/// <summary>
	/// ���������� ���������� ���������.
	/// </summary>
	/// <returns>���������� ���������.</returns>
	size_t GetCount() const;

	/// <summary>
	/// ���������� ����� �� �������.
	/// </summary>
	/// <param name="index">���������� ������.</param>
	/// <returns>������� �����.</returns>
	Node* GetBucket(size_t index) const;
};