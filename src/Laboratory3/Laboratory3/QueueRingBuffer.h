#pragma once
#include "RingBuffer.h"

/// <summary>
/// Структура очереди на основе кольцевого буфера.
/// </summary>
struct QueueRingBuffer
{
private:
	/// <summary>
	/// Кольцевой буфер для очереди.
	/// </summary>
	RingBuffer _ringBuffer;

public:
	/// <summary>
	/// Конструктор.
	/// </summary>
	/// <param name="size">Размер очереди.</param>
	QueueRingBuffer(int size);

	/// <summary>
	/// Деструктор.
	/// </summary>
	~QueueRingBuffer();

	/// <summary>
	/// Добавление элемента в очередь.
	/// </summary>
	/// <param name="data">Вводимые данные.</param>
	void Enqueue(int data);

	/// <summary>
	/// Извлечение первого элемента из очереди.
	/// </summary>
	/// <returns>Первый элемент очереди.</returns>
	int Dequeue();

	/// <summary>
	/// Проверка, пуста ли очередь.
	/// </summary>
	/// <returns>True, если очередь пустая, иначе false.</returns>
	bool IsEmpty();

	/// <summary>
	/// Освобождение памяти для очереди.
	/// </summary>
	void Delete();

	/// <summary>
	/// Вывод всех элементов очереди.
	/// </summary>
	// TODO: не должно быть работы с пользователем
	void Print();
};