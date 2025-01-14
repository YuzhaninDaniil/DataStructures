#pragma once

#include <iostream>
#include "Node.h"

/// <summary>
/// Начальный размер таблицы для инициализации.
/// </summary>
const size_t InitialTableSize = 10;

/// <summary>
/// Максимальный коэффициент заполнения таблицы (load factor) для инициализации.
/// </summary>
const double MaxLoadFactor = 0.75;

/// <summary>
/// Первая константа, используемая в хеш-функции (прямой метод Пирсена).
/// </summary>
const size_t HashConstant1 = 1664525;

/// <summary>
/// Вторая константа, используемая в хеш-функции (прямой метод Пирсена).
/// </summary>
const size_t HashConstant2 = 1013904223;

/// <summary>
/// Класс HashTable реализует хэш-таблицу.
/// </summary>
class HashTable
{
private:
	/// <summary>
	/// Хэш-таблица (массив указателей на списки).
	/// </summary>
	Node** _table;

	/// <summary>
	/// Размер таблицы.
	/// </summary>
	size_t _size;

	/// <summary>
	/// Максимальный коэфициент заполнения.
	/// </summary>
	double _maxLoadFactor;

	/// <summary>
	/// Текущее количество элементов.
	/// </summary>
	size_t _count;

	/// <summary>
	/// Хэш-функция (Прямой метод Пирсена).
	/// </summary>
	/// <param name="key">Ключ.</param>
	/// <returns>Хэш в виде числа.</returns>
	size_t static GetHash(std::string key);

	/// <summary>
	/// Преобразование в индекс массива.
	/// </summary>
	/// <param name="hash">Хэш в виде числа.</param>
	/// <returns>Индекс массива.</returns>
	size_t GetIndex(std::string key) const;

	/// <summary>
	/// Перехеширование.
	/// </summary>
	void Rehash();
public:
	/// <summary>
	/// Конструктор хэш-таблицы.
	/// </summary>
	/// <param name="initialSize">Размер таблицы.</param>
	/// <param name="loadFactor">Максимальный коэфициент заполнения.</param>
	HashTable(size_t initialSize = InitialTableSize, double loadFactor = MaxLoadFactor);

	/// <summary>
	/// Деконстркутор хэш-таблицы.
	/// </summary>
	~HashTable();

	/// <summary>
	/// Добавляет элемент в хэш-таблицу.
	/// </summary>
	/// <param name="key">Ключ.</param>
	/// <param name="value">Значение элемента.</param>
	void Insert(const string& key, const std::string& value);

	/// <summary>
	/// Удаление элементе по ключу.
	/// </summary>
	/// <param name="key">Ключ.</param>
	void Remove(const string& key);

	/// <summary>
	/// Поиск значения по ключу.
	/// </summary>
	/// <param name="key">Ключ.</param>
	/// <returns>Искомое значение.</returns>
	 string Find(const string& key);

	/// <summary>
	/// Возвращает размер таблицы.
	/// </summary>
	/// <returns>Размер таблицы.</returns>
	size_t GetSize() const;

	/// <summary>
	/// Возвращает количество элементов.
	/// </summary>
	/// <returns>Количество элементов.</returns>
	size_t GetCount() const;

	/// <summary>
	/// Возвращает бакет по индексу.
	/// </summary>
	/// <param name="index">Получаемый индекс.</param>
	/// <returns>Искомый бакет.</returns>
	Node* GetBucket(size_t index) const;
};
