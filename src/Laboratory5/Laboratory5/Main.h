#pragma once

#include <iostream>
#include <tuple>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include "BinaryTree.h"
#include <sstream>
#include "Treap.h"

using namespace std;

/// <summary>
/// ��������� ����� �����.
/// </summary>
/// <returns>�����, �������� �������������.</returns>
static int CheckData();

/// <summary>
/// ������ ��������� ������.
/// </summary>
void PrintBinaryTree(
	BinaryTreeNode const* node, bool high, vector<string> const& lpref,
	vector<string> const& cpref,
	vector<string> const& rpref, bool root, bool left,
	shared_ptr<vector<vector<string>>> lines
);

/// <summary>
/// ������ ��������� ������ � ������ ����������.
/// </summary>
void PrintTreap(
	TreapNode const* node, bool high, vector<string> const& lpref,
	vector<string> const& cpref, vector<string> const& rpref, bool root,
	bool left, shared_ptr<vector<vector<string>>> lines
);

/// <summary>
/// �������� ��� ������.
/// </summary>
/// <param name="action">����� ��������.</param>
/// <param name="flag">����.</param>
void SelectAction(int& action, bool& flag);

/// <summary>
/// ����� ����� � ���������.
/// </summary>
/// <returns>�����.</returns>
int main();

