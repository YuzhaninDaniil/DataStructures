#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

/// <summary>
/// Структура кольцевого буфера.
/// </summary>
struct RingBuffer
{
private:
	/// <summary>
	/// Указатель на буфер.
	/// </summary>
	int* _buffer;

	/// <summary>
	/// Максимальный размер буфера.
	/// </summary>
	int _bufferSize;

	/// <summary>
	/// Индекс для добавления элемента.
	/// </summary>
	int _head;

	/// <summary>
	/// Индекс для извлечения элемента.
	/// </summary>
	int _tail;

	/// <summary>
	/// Текущий размер заполненного буфера.
	/// </summary>
	int _currentSize;

	/// <summary>
	/// Фактор роста.
	/// </summary>
	int _growthFactor = 2;

public:
	/// <summary>
	/// Конструктор.
	/// </summary>
	/// <param name="size">Размер кольцевого буфера.</param>
	RingBuffer(int size);

	/// <summary>
	/// Деструктор.
	/// </summary>
	~RingBuffer();

	/// <summary>
	/// Добавление элемента в кольцевой буфер.
	/// </summary>
	/// <param name="data">Элемент, добавляемый в кольцевой буфер.</param>
	void Add(int data);

	/// <summary>
	/// Извлечение элемента из кольцевого буфера.
	/// </summary>
	/// <returns>Удаляет последний элемент кольцевого буфера.</returns>
	int Remove();

	/// <summary>
	/// Увеличивает размер кольцевого буфера.
	/// </summary>
	void Resize();

	/// <summary>
	/// Проверка, полный ли кольцевой буфер.
	/// </summary>
	/// <returns>True, если кольцевой буфер полон, иначе false.</returns>
	bool IsFull();

	/// <summary>
	/// Проверка, пуст ли кольцевой буфер.
	/// </summary>
	/// <returns>True, если кольцевой буфер пуст, иначе false.</returns>
	bool IsEmpty();

	/// <summary>
	/// Получение текущего размера буфера.
	/// </summary>
	/// <returns>Возвращает текущий размер буфера.</returns>
	int Size();

	/// <summary>
	/// Вывод всех элементов кольцевого буфера.
	/// </summary>
	void Print();

	/// <summary>
	/// Освобождение памяти кольцевого буфера.
	/// </summary>
	void Delete();

	/// <summary>
	/// Возвращает количества свободного места в кольцевом буфере.
	/// </summary>
	int FreeSpace();

	/// <summary>
	/// Возвращает вместимость буфера.
	/// </summary>
	/// <returns>Возвращает общую вместимость кольцевого буфера.</returns>
	int GetBufferSize();
};