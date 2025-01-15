#include "../Header/HashTable.h"

using namespace std;

HashTable::HashTable(size_t initialSize, double loadFactor)
	: _size(initialSize), _maxLoadFactor(loadFactor), _count(0)
{
	_table = new Node * [_size];
	memset(_table, 0, _size * sizeof(Node*));
}

HashTable::~HashTable()
{
	for (size_t i = 0; i < _size; ++i)
	{
		Node* currentNode = _table[i];
		while (currentNode != nullptr)
		{
			Node* nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
	}

	delete[] _table;
}

size_t HashTable::GetHash(std::string key)
{
	size_t hashValue = 0;
	for (char c : key)
	{
		hashValue = (hashValue * HashConstant1) + static_cast<unsigned char>(c) + HashConstant2;
	}

	return hashValue;
}

size_t HashTable::GetIndex(std::string key) const
{
	return GetHash(key) % _size;
}

void HashTable::Rehash()
{
	size_t oldSize = _size;
	_size *= 2;
	Node** newTable = new Node * [_size];

	for (size_t i = 0; i < _size; ++i)
	{
		newTable[i] = nullptr;
	}

	for (size_t i = 0; i < oldSize; ++i)
	{
		Node* current = _table[i];
		while (current)
		{
			size_t newIndex = GetIndex(current->key);
			Node* next = current->next;

			current->next = newTable[newIndex];
			newTable[newIndex] = current;

			current = next;
		}
	}

	delete[] _table;
	_table = newTable;
}

void HashTable::Insert(const std::string& key, const std::string& value)
{
	size_t index = GetIndex(key);

	for (Node* current = _table[index]; current != nullptr; current = current->next)
	{
		if (current->key == key)
		{
			return;
		}
	}

	Node* newNode = new Node(key, value);
	newNode->next = _table[index];
	_table[index] = newNode;
	_count++;

	//Если количество элементов хеш-таблицы >= вместимости -> расширяемся.
	if (static_cast<double>(_count) / _size >= _maxLoadFactor)
	{
		Rehash();
	}
}

void HashTable::Remove(const std::string& key)
{
	size_t index = GetIndex(key);
	Node* current = _table[index];
	Node* prev = nullptr;

	while (current != nullptr)
	{
		if (current->key == key)
		{
			if (prev != nullptr)
			{
				prev->next = current->next;
			}
			else
			{
				_table[index] = current->next;
			}

			delete current;
			_count--;
			return;
		}
		prev = current;
		current = current->next;
	}
}

string HashTable::Find(const string& key)
{
	size_t index = GetIndex(key);

	for (Node* current = _table[index]; current != nullptr; current = current->next)
	{
		if (current->key == key)
		{
			return current->value;
		}
	}

	return "";
}

size_t HashTable::GetSize() const
{
	return _size;
}

size_t HashTable::GetCount() const
{
	return _count;
}

Node* HashTable::GetBucket(size_t index) const
{
	return _table[index];
}
