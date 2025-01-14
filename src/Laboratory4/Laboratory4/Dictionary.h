#pragma once

#include "HashTable.h"
#include <iostream>

// TODO: Полетела кодировка. Посмотреть везде
/// <summary>
/// ����� ��� ������ �� �������.
/// </summary>
class Dictionary
{
private:
	/// <summary>
	/// ���-������� ��� �������� ������.
	/// </summary>
	HashTable _dictionary;

public:
	/// <summary>
	/// ����������� �������.
	/// </summary>
	/// <param name="initialSize">������ �������.</param>
	/// <param name="loadFactor">������������ ���������� ����������.</param>
	Dictionary(size_t initialSize = InitialTableSize, double loadFactor = MaxLoadFactor);

	/// <summary>
	/// ��������� ������� � �������.
	/// </summary>
	/// <param name="key">����.</param>
	/// <param name="value">�������� ��������.</param>
	void Insert(const std::string& key, const std::string& value);

	/// <summary>
	/// �������� �������� �� �����.
	/// </summary>
	/// <param name="key">����.</param>
	void Remove(const std::string& key);

	/// <summary>
	/// ����� �������� �� �����.
	/// </summary>
	/// <param name="key">����.</param>
	/// <returns>������� ��������.</returns>
	string Find(const std::string& key);

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
	/// ���������� ����� �� ������� � �������.
	/// </summary>
	/// <param name="index">���������� ������.</param>
	/// <returns>������� �����.</returns>
	Node* GetBucket(size_t index) const;
};