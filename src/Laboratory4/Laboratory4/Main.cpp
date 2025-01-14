#include "Main.h"
#include <iostream>
#include <string>

using namespace std;

// TODO: Иерархия путей в решении не совпадает с проводником

int main()
{
	setlocale(LC_ALL, "ru");

	Dictionary dictionary;

	int userChoice;

	do
	{
		cout << endl << "Меню" << endl;
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Найти элемент" << endl;
		cout << "4. Вывести хеш-таблицу" << endl;
		cout << "5. Вывести словарь" << endl;
		cout << "0. Выход" << endl;

		userChoice = CheckData();
		switch (userChoice)
		{
		case 1:
		{
			string key;
			string value;
			cout << "Введите ключ: ";
			cin >> key;
			cout << "Введите значение: ";
			cin >> value;
			dictionary.Insert(key, value);
			cout << "Элемент добавлен."<< endl;
			break;
		}
		case 2:
		{
			string key;
			cout << "Введите ключ для удаления: ";
			cin >> key;
			dictionary.Remove(key);
			break;
		}
		case 3:
		{
			string key;
			string value;
			cout << "Введите ключ для поиска: ";
			cin >> key;
			value = dictionary.Find(key);
			if (value != "")
			{
				cout << "Значение: " << value << endl;
			}
			else
			{
				cout << "Элемент не найден."<< endl;
			}
			break;
		}
		case 4:
		{
			PrintTable(dictionary);
			break;
		}
		case 5:
		{
			PrintDictionary(dictionary);
			break;
		}
		case 0:
		{
			cout << "Выход."<< endl;
			break;
		}
		default:
		{
			cout << "Неверный выбор."<< endl;
		}
		}
	} while (userChoice != 0);

	return 0;
}

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

void PrintTable(const Dictionary& dict)
{
	cout << "Хэш-таблица:" << endl;
	for (size_t i = 0; i < dict.GetSize(); ++i)
	{
		cout << i << ": ";
		Node* current = dict.GetBucket(i);

		if (current == nullptr)
		{
			cout << "Пусто";
		}
		else
		{
			for (; current != nullptr; current = current->next)
			{
				cout << "{" << current->key << "} ---> " << current->value;
				if (current->next != nullptr)
				{
					cout << "; ";
				}
			}
		}

		cout << endl;
	}
}

void PrintDictionary(const Dictionary& dict)
{
	cout << "Словарь:" << endl;
	for (size_t i = 0; i < dict.GetSize(); ++i)
	{
		Node* current = dict.GetBucket(i);

		for (; current != nullptr; current = current->next)
		{
			cout << current->key << ": " << current->value << endl;
		}
	}
}

