#include "../Header/Dictionary.h"

using namespace std;

Dictionary::Dictionary(size_t initialSize, double loadFactor)
	: _dictionary(initialSize, loadFactor) {}

void Dictionary::Insert(const string& key, const string& value)
{
	_dictionary.Insert(key, value);
}

void Dictionary::Remove(const string& key)
{
	_dictionary.Remove(key);
}

string Dictionary::Find(const string& key)
{
	return _dictionary.Find(key);
}

size_t Dictionary::GetSize() const
{
	return _dictionary.GetSize();
}

size_t Dictionary::GetCount() const
{
	return _dictionary.GetCount();
}

Node* Dictionary::GetBucket(size_t index) const
{
	return _dictionary.GetBucket(index);
}