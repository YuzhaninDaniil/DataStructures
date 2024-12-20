#include "Stack.h"

/// <summary>
/// Конструктор по умолчанию.
/// </summary>
Stack::Stack() : _buffer(nullptr), _bufferSize(0), _top(-1) {}

/// <summary>
/// Конструктор с заданным размером.
/// </summary>
/// <param name="size">Размер, с которым будет создан стек.</param>
Stack::Stack(int size) : _bufferSize(size), _top(-1)
{
	_buffer = new int[size];
}

/// <summary>
/// Деструктор.
/// </summary>
Stack::~Stack()
{
	Delete();
}

void Stack::Push(int data)
{
	_buffer[++_top] = data;
	_bufferSize++;
}

/// <summary>
/// Извлечение элемента из стека.
/// </summary>
/// <returns>Указатель на стек.</returns>
int Stack::Pop()
{
	if (IsEmpty())
	{
		throw underflow_error("Стек пуст, невозможно извлечь элемент.");
	}

	_bufferSize--;

	return _buffer[_top--];
}

/// <summary>
/// Проверка, пуст ли стек.
/// </summary>
/// <returns>True, если индекс последнего элемента = -1, иначе false.</returns>
bool Stack::IsEmpty()
{
	return _top == -1;
}

/// <summary>
/// Получение размера стека.
/// </summary>
/// <returns>Возвращает индекс последнего элемента.</returns>
int Stack::GetSize()
{
	return _top + 1;
}

/// <summary>
/// Получение вместимости стека.
/// </summary>
/// <returns>Вместимость буфера.</returns>
int Stack::GetCapacity()
{
	return _bufferSize;
}

/// <summary>
/// Выводит на консоль стек.
/// </summary>
void Stack::Print()
{
	if (IsEmpty())
	{
		cout << "???? ????." << endl;
		return;
	}

	cout << "????? ?????: " << endl;
	for (int i = 0; i <= _top; i++)
	{
		cout << _buffer[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// Освобождение памяти стека.
/// </summary>
void Stack::Delete()
{
	delete[] _buffer;
	_buffer = nullptr;
	_bufferSize = 0;
	_top = -1;
}
