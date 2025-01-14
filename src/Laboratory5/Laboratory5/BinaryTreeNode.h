#pragma once
/// <summary>
/// ���� ��������� ������.
/// </summary>
struct BinaryTreeNode
{
	/// <summary>
	/// ��������� �� ����� ����.
	/// </summary>
	BinaryTreeNode* Left = nullptr;

	/// <summary>
	/// ��������� �� ������ ����.
	/// </summary>
	BinaryTreeNode* Right = nullptr;

	/// <summary>
	/// ������, ������� �������� ����.
	/// </summary>
	int Data;

	/// <summary>
	/// �����������.
	/// </summary>
	/// <param name="value">������� ����.</param>
	BinaryTreeNode(int value) : Left(nullptr), Right(nullptr), Data(value) {}
};
