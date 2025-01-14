#pragma once

#include "Dictionary.h"

/// <summary>
/// Функция для проверки ввода целого числа пользователем.
/// Функция запрашивает у пользователя ввод целого числа и продолжает запрос до тех пор,
/// пока не будет введено корректное значение.
/// </summary>
/// <returns>Введенное пользователем целое число.</returns>
int CheckData();

/// <summary>
/// Вывод хэш-таблицы.
/// </summary>
/// <param name="dict">Словарь.</param>
void PrintTable(const Dictionary& dict);

/// <summary>
/// Вывод словаря.
/// </summary>
/// <param name="dict">Словарь.</param>
void PrintDictionary(const Dictionary& dict);

/// <summary>
/// Точка входа в программу.
/// </summary>
/// <returns>Число.</returns>
int main();