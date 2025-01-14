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
/// Валидация ввода числа.
/// </summary>
/// <returns>Число, введённое пользователем.</returns>
static int CheckData();

/// <summary>
/// Печать бинарного дерева.
/// </summary>
void PrintBinaryTree(
	BinaryTreeNode const* node, bool high, vector<string> const& lpref,
	vector<string> const& cpref,
	vector<string> const& rpref, bool root, bool left,
	shared_ptr<vector<vector<string>>> lines
);

/// <summary>
/// Печать декартова дерева с учетом приоритета.
/// </summary>
void PrintTreap(
	TreapNode const* node, bool high, vector<string> const& lpref,
	vector<string> const& cpref, vector<string> const& rpref, bool root,
	bool left, shared_ptr<vector<vector<string>>> lines
);

/// <summary>
/// Выбирает тип дерева.
/// </summary>
/// <param name="action">Номер действия.</param>
/// <param name="flag">Флаг.</param>
void SelectAction(int& action, bool& flag);

/// <summary>
/// Точка входа в программу.
/// </summary>
/// <returns>Число.</returns>
int main();

