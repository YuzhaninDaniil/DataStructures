#pragma once

#include <iostream>

using namespace std;

/// <summary>
/// Структура для хранения пары ключ-значение.
/// </summary>
struct Node
{
	/// <summary>
	/// Ключ.
	/// </summary>
	string key;

	/// <summary>
	/// Значение.
	/// </summary>
	string value;

	/// <summary>
	/// Указатель на следующую пару.
	/// </summary>
	Node* next;

	/// <summary>
	/// Конструктор элемента словаря (ключ-значение).
	/// </summary>
	/// <param name="k">Ключ.</param>
	/// <param name="v">Значение.</param>
	Node(const string& k, const string v) : key(k), value(v), next(nullptr) {}
};
