#pragma once
#include <random>

/// <summary>
/// ���� ����������� ������.
/// </summary>
struct TreapNode
{
	/// <summary>
	/// �������� ����.
	/// </summary>
	int Key;

	/// <summary>
	/// ���������  ����.
	/// </summary>
	int Priority;

	/// <summary>
	/// ��������� �� ����� ����.
	/// </summary>
	TreapNode* LeftNode = nullptr;

	/// <summary>
	/// ��������� �� ������ ����.
	/// </summary>
	TreapNode* RightNode = nullptr;

	/// <summary>
	/// ����������� ���� � �������������� Key � ��������� �����������.
	/// </summary>
	/// <param name="key">���� ����</param>
	TreapNode(int key)
	{
		Key = key;
		//������������ ��������� � ������� �������.
		static std::mt19937 random(std::random_device{}());
		Priority = std::uniform_int_distribution<int>(1, 1000)(random);
		LeftNode = nullptr;
		RightNode = nullptr;
	}
};