#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include "Stack.h"
#include "QueueStack.h"
#include "QueueRingBuffer.h"
#include "RingBuffer.h"
#include "Main.h"

using namespace std;

/// <summary>
/// Проверяет валидность введенного числа пользователем.
/// </summary>
int CheckData()
{
	cout << "Ваш ввод: ";

	string input;

	while (true)
	{
		try
		{
			cin >> input;
			size_t pos;
			// попытка преобразовать строку в число
			int value = stoi(input, &pos);
			// проверка на то, все ли символы строки преобразованы.
			if (pos == input.length())
			{
				return value;
			}
			else
			{
				cout << "Введено неверное значение (нечисловые символы). Повторите ввод: ";
			}
		}
		catch (invalid_argument& e)
		{
			cout << "Введено неверное значение (не число). Повторите ввод: ";
		}
	}
}

/// <summary>
/// Отображает в консоли меню стека.
/// </summary>
void DisplayStackMenu(Stack& stack)
{
	while (true)
	{
		cout << endl << "------------------------------------" << endl;
		cout << "Лабораторная работа #2 - стек" << endl;
		cout << endl << "Текущий стек: ";
		stack.Print();
		cout << endl;
		cout << "Выберите команду:" << endl;
		cout << "1. Добавить (Push) элемент в стек" << endl;
		cout << "2. Достать (Pop) элемент из стека" << endl;
		cout << "0. Выйти в меню" << endl;

		int userChoice = CheckData();

		switch (userChoice)
		{
		case 1:
		{
			cout << "Введите значение для элемента: " << endl;
			int value = CheckData();
			try
			{
				stack.Push(value);
				cout << "Введенное значение: " << value << endl;
			}
			catch (const overflow_error& e)
			{
				cout << e.what() << endl;
			}
			break;
		}
		case 2:
		{
			try
			{
				cout << "Взятый элемент: " << stack.Pop() << endl;
			}
			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
			break;
		}
		case 0:
			return;
		default:
			cout << "Неизвестная комманда. Попробуйте еще раз." << endl;
		}
	}
}

/// <summary>
/// Отображает в консоли меню Кольцевого буфера.
/// </summary>
void DisplayRingBufferMenu(RingBuffer& ringBuffer)
{
	while (true)
	{
		cout << endl << "------------------------------------" << endl;
		cout << "Лабораторная работа #2 - кольцевой буфер" << endl;
		cout << endl << "Текущий кольцевой буфер: ";
		ringBuffer.Print();
		cout << "Выберите команду:" << endl;
		cout << "1. Добавить элемент в кольцевой буфер" << endl;
		cout << "2. Удалить элемент из кольцевого буфера" << endl;
		cout << "0. Выйти в меню" << endl;

		int userChoice = CheckData();

		switch (userChoice)
		{
		case 1:
		{
			cout << "Введите значение для элемента: " << endl;
			int value = CheckData();
			try
			{
				ringBuffer.Add(value);
				cout << "Введенное значение: " << value << endl;
			}
			catch (const overflow_error& e)
			{
				cout << e.what() << endl;
			}
			break;
		}
		case 2:
		{
			try
			{
				cout << "Удаленный элемент " << ringBuffer.Remove() << endl;
			}
			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
			break;
		}
		case 0:
			return;
		default:
			cout << "Неизвестная комманда. Попробуйте еще раз." << endl;
			return;
		}
	}
}

/// <summary>
/// Отображает в консоли меню очереди на основе 2 стеков.
/// </summary>
void DisplayQueueStackMenu(QueueStack& queueStack)
{
	while (true)
	{
		cout << endl << "------------------------------------" << endl;
		cout << "Лабораторная работа #2 - очередь на основе стеков" << endl;
		cout << endl << "Current queueStack: ";
		queueStack.Print();
		cout << "Выберите команду:" << endl;
		cout << "1. Добавить (Enqueue) элемент" << endl;
		cout << "2. Удалить (Dequeue) элемент" << endl;
		cout << "0. Выйти в меню" << endl;

		int userChoice = CheckData();

		switch (userChoice)
		{
		case 1:
		{
			cout << "Введите значение для добавления: " << endl;
			int value = CheckData();
			queueStack.Enqueue(value);
			cout << "Введенное значение: " << value << endl;
			break;
		}
		case 2:
		{
			try
			{
				cout << "Удаленный элемент: " << queueStack.Dequeue() << endl;
			}
			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
			break;
		}
		case 0:
			return;
		default:
			cout << "Неизвестная комманда. Попробуйте еще раз." << endl;
		}
	}
}

/// <summary>
/// Отображает в консоли меню очереди на основе кольцевого буфера.
/// </summary>
void DisplayQueueRingBufferMenu(QueueRingBuffer& queueRingBuffer)
{
	while (true)
	{
		cout << endl << "------------------------------------" << endl;
		cout << "Лабораторная работа #2 - очередь на основе кольцевого буфера" << endl;
		cout << endl << "Текущий кольцевой буфер: ";
		queueRingBuffer.Print();
		cout << "Выберите команду:" << endl;
		cout << "1. Добавить (Enqueue) элемент" << endl;
		cout << "2. Удалить (Dequeue) элемент" << endl;
		cout << "0. Выйти в меню" << endl;

		int userChoice = CheckData();

		switch (userChoice)
		{
		case 1:
		{
			cout << "Введите значение для добавления: " << endl;
			int value = CheckData();
			queueRingBuffer.Enqueue(value);
			cout << "Введенное значение: " << value << endl;
			break;
		}
		case 2:
		{
			try
			{
				cout << "Удаленный элемент: " << queueRingBuffer.Dequeue() << endl;
			}
			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
			break;
		}
		case 0:
			return;
		default:
			cout << "Неизвестная комманда. Попробуйте еще раз." << endl;
		}
	}
}

/// <summary>
/// Точка входа программы.
/// </summary>
int main()
{
	setlocale(LC_ALL, "");

	Stack myStack(5);
	RingBuffer myRingBuffer(5);
	QueueStack myQueueStack(5);
	QueueRingBuffer myQueueRingBuffer(5);

	while (true)
	{
		cout << endl << "------------------------------------" << endl;
		cout << "Меню" << endl;
		cout << "1. Стек" << endl;
		cout << "2. Кольцевой буфер" << endl;
		cout << "3. Очередь на основе стеков" << endl;
		cout << "4. Очередь на основе кольцевого буфера" << endl;
		cout << "0. Выход" << endl;

		int menuChoice = CheckData();

		switch (menuChoice)
		{
		case 1:
			DisplayStackMenu(myStack);
			break;
		case 2:
			DisplayRingBufferMenu(myRingBuffer);
			break;
		case 3:
			DisplayQueueStackMenu(myQueueStack);
			break;
		case 4:
			DisplayQueueRingBufferMenu(myQueueRingBuffer);
			break;
		case 0:
			return 0;
		default:
			cout << "Неизвестная комманда. Попробуйте еще раз." << endl;
		}
	}
	return 0;
}