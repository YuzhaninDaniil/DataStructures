#include "QueueStack.h"

/// <summary>
/// Конструктор.
/// </summary>
/// <param name="size">Размер очереди.</param>
QueueStack::QueueStack(int size) : _stack1(size), _stack2(size) {}

/// <summary>
/// Деструктор.
/// </summary>
QueueStack::~QueueStack()
{
	Delete();
}

/// <summary>
/// Добавление элемента в очередь.
/// </summary>
/// <param name="data">Вводимые данные.</param>
void QueueStack::Enqueue(int data)
{
	_stack1.Push(data); // Добавляем элемент в первый стек
}

/// <summary>
/// Извлечение элемента из очереди.
/// </summary>
/// <returns>Возвращает первый элемент очереди.</returns>
int QueueStack::Dequeue()
{
	if (_stack2.IsEmpty())
	{
		while (!_stack1.IsEmpty())
		{
			_stack2.Push(_stack1.Pop());
		}
	}

	if (_stack2.IsEmpty())
	{
		throw underflow_error("Очередь пуста, невозможно извлечь элемент.");
	}
	return _stack2.Pop();
}

/// <summary>
/// Проверка, пуста ли очередь.
/// </summary>
/// <returns>True, если очередь пуста, иначе false.</returns>
bool QueueStack::IsEmpty()
{
	return _stack1.IsEmpty() && _stack2.IsEmpty();
}

/// <summary>
/// Освобождение памяти для очереди.
/// </summary>
void QueueStack::Delete()
{
	_stack1.Delete();
	_stack2.Delete();
}

/// <summary>
/// Вывод всех элементов очереди.
/// </summary>
void QueueStack::Print()
{
	std::cout << "Вывод очереди: ";

	Stack tempStack(_stack1.GetSize() + _stack2.GetSize());

	while (!_stack2.IsEmpty())
	{
		int value = _stack2.Pop();
		std::cout << value << " ";
		tempStack.Push(value);
	}

	while (!_stack1.IsEmpty())
	{
		int value = _stack1.Pop();
		std::cout << value << " ";
		tempStack.Push(value);
	}

	while (!tempStack.IsEmpty())
	{
		_stack2.Push(tempStack.Pop());
	}

	std::cout << std::endl;
}
