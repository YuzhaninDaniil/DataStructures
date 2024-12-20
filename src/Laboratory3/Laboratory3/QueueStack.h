#pragma once
#include "Stack.h"

/// <summary>
/// Структура очереди на основе двух стеков.
/// </summary>
struct QueueStack
{
private:
	/// <summary>
	/// Первый стек.
	/// </summary>
	Stack _stack1;

	/// <summary>
	/// Второй стек.
	/// </summary>
	Stack _stack2;

public:
	/// <summary>
	/// Конструктор с размером стеков.
	/// </summary>
	/// <param name="size">Размер очереди.</param>
	QueueStack(int size);

	/// <summary>
	/// Деструктор.
	/// </summary>
	~QueueStack();

	/// <summary>
	/// Добавление элемента в очередь.
	/// </summary>
	/// <param name="data">Значение вводимых данных.</param>
	void Enqueue(int data);

	/// <summary>
	///  Извлечение элемента из очереди.
	/// </summary>
	/// <returns>Возвращает первый элемент очереди.</returns>
	int Dequeue();

	/// <summary>
	/// Проверка, пуста ли очередь.
	/// </summary>
	/// <returns>True, если очредь пуста, иначе false.</returns>
	bool IsEmpty();

	/// <summary>
	/// Освобождение памяти для очереди.
	/// </summary>
	void Delete();

	/// <summary>
	/// Вывод всех элементов очереди.
	/// </summary>
	void Print();
};