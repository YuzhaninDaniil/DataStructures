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
/// Проверяет корректность вводимого числа.
/// </summary>
/// <returns>Число.</returns>
static int CheckData();

/// <summary>
/// Выводит бинарное дерево.
/// </summary>
void PrintBinaryTree(
	BinaryTreeNode const* node, bool high, vector<string> const& lpref,
	vector<string> const& cpref,
	vector<string> const& rpref, bool root, bool left,
	shared_ptr<vector<vector<string>>> lines
);

/// <summary>
/// Выводит декартово дерево.
/// </summary>
void PrintTreap(
	TreapNode const* node, bool high, vector<string> const& lpref,
	vector<string> const& cpref, vector<string> const& rpref, bool root,
	bool left, shared_ptr<vector<vector<string>>> lines
);

/// <summary>
/// Выбирает вид структуры.
/// </summary>
/// <param name="action">Операция.</param>
/// <param name="flag">Флаг.</param>
void SelectAction(int& action, bool& flag);

/// <summary>
/// Точка входа в программу.
/// </summary>
/// <returns>Число.</returns>
int main();

