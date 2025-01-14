#include "List.h"
#include "iostream"
#include <iomanip> 

using namespace std;

/// <summary>
/// Функция для проведения бенчмарк-тестов различных операций со списком.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в списке.</typeparam>
/// <param name="myList">Список для тестирования.</param>
/// <param name="size">Количество элементов для использования в тестах.</param>
// Шаблонная функция для тестирования производительности различных операций списка
template<typename T>
void BenchmarkTest(List<T>& myList, int size)
{
	// Заполнение списка данными для бенчмарка
	myList.FillBenchmark(size);

	// Измерение времени, необходимого для удаления 'size' элементов из списка
	double removeTime = myList.Benchmark(myList.RemoveBenchmark(size), size, "Remove");
	cout << "Время удаления " << size << " элементов(Remove): " << fixed << setprecision(6) << removeTime << " секунд." << endl;
	myList.Clear();

	double addStartTime = myList.Benchmark(myList.AddBenchmark(size, true), size, "AddStart");
	cout << "Время добавления " << size << " элементов(AddStart): " << fixed << setprecision(6) << addStartTime << " секунд" << endl;
	myList.Clear();

	// Измерение времени, необходимого для добавления 'size' элементов в конец списка
	double addEndTime = myList.Benchmark(myList.AddBenchmark(size, false), size, "AddEnd");
	cout << "Время добавления " << size << " элементов(AddEnd): " << fixed << setprecision(6) << addEndTime << " секунд" << endl;
	myList.Clear();

	myList.Add(5, false);
	// Поиск добавленного элемента для последующей операции
	ListItem<T>* nodeInsertAfter = myList.LinearSearch(5);
	// Измерение времени, необходимого для вставки 'size' элементов после найденного узла
	double insertAfterTime = myList.Benchmark(myList.InsertBenchmark(nodeInsertAfter, size, true), size, "InsertAfter");
	cout << "Время добавления " << size << " элементов(InsertAfter): " << fixed << setprecision(6) << insertAfterTime << " секунд" << endl;
	myList.Clear();

	myList.Add(5, true);
	ListItem<T>* nodeInsertBefore = myList.LinearSearch(5);
	double insertBeforeTime = myList.Benchmark(myList.InsertBenchmark(nodeInsertBefore, size, false), size, "InsertBefore");
	cout << "Время добавления " << size << " элементов(InsertBefore): " << fixed << setprecision(6) << insertBeforeTime << " секунд" << endl;
	myList.Clear();
}
/// <summary>
/// Выводит элементы списка в консоль.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в списке.</typeparam>
/// <param name="myList">Список для вывода.</param>
template<typename T>
void PrintList(const List<T>& myList)
{
	ListItem<T>* current = myList.GetHead();
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}


int main()
{
	List<int> myList;

	setlocale(LC_ALL, "Russian");

	cout << "Выберите действие:" << endl;
	cout << "0. Вывести инструкции." << endl;
	cout << "1. Добавить в начало." << endl;
	cout << "2. Добавить в конец." << endl;
	cout << "3. Вставить после элемента." << endl;
	cout << "4. Вставить перед элементом." << endl;
	cout << "5. Удалить элемент." << endl;
	cout << "6. Сортировать." << endl;
	cout << "7. Линейный поиск." << endl;
	cout << "8. Вывести список." << endl;
	cout << "9. Вывод времени." << endl;

	int choice;
	while (true)
	{
		cout << endl << "Введите номер действия: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
		{
			cout << "0. Вывести инструкции." << endl;
			cout << "1. Добавить в начало." << endl;
			cout << "2. Добавить в конец." << endl;
			cout << "3. Вставить после элемента." << endl;
			cout << "4. Вставить перед элементом." << endl;
			cout << "5. Удалить элемент." << endl;
			cout << "6. Сортировать." << endl;
			cout << "7. Линейный поиск." << endl;
			cout << "8. Вывести список." << endl;
			cout << "9. Вывод времени." << endl;
			break;
		}
		case 1:
		{
			int value;
			cout << "Введите значение для добавления в начало: ";
			cin >> value;
			myList.Add(value, true);
			break;
		}
		case 2:
		{
			int value;
			cout << "Введите значение для добавления в конец: ";
			cin >> value;
			myList.Add(value, false);
			break;
		}
		case 3:
		{
			int value, node;
			cout << "Введите значение для добавления после элемента: ";
			cin >> value;
			cout << "Введите значение элемента, после которого вставлять: ";
			cin >> node;
			ListItem<int>* nodeInsertAfter = myList.LinearSearch(node);
			if (nodeInsertAfter)
			{
				myList.Insert(nodeInsertAfter, value, true);
			}
			else
			{
				cout << "Элемент не найден." << endl;
			}
			break;
		}
		case 4:
		{
			int value, node;
			cout << "Введите значение для добавления перед элементом: ";
			cin >> value;
			cout << "Введите значение элемента, перед которым вставлять: ";
			cin >> node;
			ListItem<int>* nodeInsertBefore = myList.LinearSearch(node);
			if (nodeInsertBefore)
			{
				myList.Insert(nodeInsertBefore, value, false);
			}
			else
			{
				cout << "Элемент не найден." << endl;
			}
			break;
		}
		case 5:
		{
			int node;
			cout << "Введите значение элемента для удаления: ";
			cin >> node;
			ListItem<int>* nodeFind = myList.LinearSearch(node);
			if (nodeFind)
			{
				myList.Remove(nodeFind);
			}
			else
			{
				cout << "Элемент не найден." << endl;
			}
			break;
		}
		case 6:
		{
			myList.Sort();
			cout << "Список отсортирован." << endl;
			PrintList(myList);
			break;
		}
		case 7:
		{
			int node;
			cout << "Введите значение для поиска: ";
			cin >> node;
			ListItem<int>* target = myList.LinearSearch(node);
			if (target)
			{
				cout << "Элемент найден." << endl;
			}
			else
			{
				cout << "Элемент не найден." << endl;
			}
			break;
		}
		case 8:
		{
			cout << endl << "Список:" << endl;
			PrintList(myList);
			break;
		}
		case 9:
		{
			BenchmarkTest<int>(myList, 10);
			BenchmarkTest<int>(myList, 100);
			BenchmarkTest<int>(myList, 1000);
			BenchmarkTest<int>(myList, 10000);
			BenchmarkTest<int>(myList, 100000);
			break;
		}
		default:
			cout << "Неверный выбор." << endl;
		}
	}
}