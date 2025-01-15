#pragma once
/// <summary>
/// Узел бинарного дерева.
/// </summary>
struct BinaryTreeNode
{
	/// <summary>
	/// Указатель на левый  дочерний узел.
	/// </summary>
	BinaryTreeNode* Left = nullptr;

	/// <summary>
	/// Указатель на правый  дочерний узел.
	/// </summary>
	BinaryTreeNode* Right = nullptr;

	/// <summary>
	/// Данные, которые содержит узел.
	/// </summary>
	int Data;

	/// <summary>
	/// Конструктор.
	/// </summary>
	/// <param name="value">Знаачение элемента.</param>
	BinaryTreeNode(int value) : Left(nullptr), Right(nullptr), Data(value) {}
};
