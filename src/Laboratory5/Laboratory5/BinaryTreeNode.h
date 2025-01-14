#pragma once
/// <summary>
/// Узел бинарного дерева.
/// </summary>
struct BinaryTreeNode
{
	/// <summary>
	/// Указатель на левый узел.
	/// </summary>
	BinaryTreeNode* Left = nullptr;

	/// <summary>
	/// Указатель на правый узел.
	/// </summary>
	BinaryTreeNode* Right = nullptr;

	/// <summary>
	/// Данные, которые содержит узел.
	/// </summary>
	int Data;

	/// <summary>
	/// Конструктор.
	/// </summary>
	/// <param name="value">Даныные узла.</param>
	BinaryTreeNode(int value) : Left(nullptr), Right(nullptr), Data(value) {}
};
