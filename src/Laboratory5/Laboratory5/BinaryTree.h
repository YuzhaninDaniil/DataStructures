#pragma once
#include "BinaryTreeNode.h"

// TODO: Полетела кодировка. Посмотреть везде
/// <summary>
/// ��������� �������� ������.
/// </summary>
struct BinaryTree
{
    /// <summary>
    /// ��������� �� �������� ���� ������.
    /// </summary>
    BinaryTreeNode* Root;

    /// <summary>
    /// �����������.
    /// </summary>
    BinaryTree() : Root(nullptr) {}
};


/// <summary>
/// ��������� ����� �������� � �������� ������.
/// </summary>
/// <param name="node">��������� �� ���� ������, � �������� ���������� �����.</param>
/// <param name="value">��������, ������� ��������� �����.</param>
/// <returns>��������� �� ����, ���������� ������� ��������, ��� nullptr, ���� ������� �� ������.</returns>
BinaryTreeNode* Find(BinaryTreeNode* node, const int value);

/// <summary>
/// ��������� ����� ������������ �������� � ������.
/// </summary>
/// <param name="node">��������� �� ���� ������, � �������� ���������� �����.</param>
/// <returns>��������� �� ����, ���������� ����������� ��������, ��� nullptr, ���� ������ �����.</returns>
BinaryTreeNode* FindMin(BinaryTreeNode* node);

/// <summary>
/// ��������� ����� ������������� �������� � ������.
/// </summary>
/// <param name="node">��������� �� ���� ������, � �������� ���������� �����.</param>
/// <returns>��������� �� ����, ���������� ������������ ��������, ��� nullptr, ���� ������ �����.</returns>
BinaryTreeNode* FindMax(BinaryTreeNode* node);

/// <summary>
/// ��������� ����� �������� � �������� ������.
/// </summary>
/// <param name="node">������ �� ��������� ����, ���� ����������� ��������.</param>
/// <param name="value">��������, ������� ��������� ��������.</param>
void Insert(BinaryTreeNode*& node, int value);

/// <summary>
/// ������� ������� � �������� ��������� �� ��������� ������.
/// </summary>
/// <param name="node">������ �� ��������� ����, �� �������� ��������� ��������.</param>
/// <param name="value">��������, ������� ��������� �������.</param>
void Remove(BinaryTreeNode*& node, const int value);

