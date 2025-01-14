#pragma once

#include "ListItem.h"
#include <chrono>
#include <iostream>
#include <algorithm>

/// <summary>
/// ����� List ��������� ���������� ������.
/// ������������ ����������, ��������, �������, ���������� � ����� ���������.
/// </summary>
/// <typeparam name="T">��� ������, ���������� � ������.</typeparam>
template <typename T>
struct List
{
private:
    /// <summary>
    /// ��������� �� ������ ������� ������.
    /// </summary>
    ListItem<T>* head;

    /// <summary>
    /// ��������� �� ��������� ������� ������.
    /// </summary>
    ListItem<T>* tail;

    /// <summary>
    /// ������ ������.
    /// </summary>
    size_t size;

public:
    /// <summary>
    /// ����������� ������.
    /// </summary>
    List() : head(nullptr), tail(nullptr), size(0) {}

    /// <summary>
    /// ���������� ������.
    /// </summary>
    ~List()
    {
        Clear();
    }

    /// <summary>
    /// ���������� ������ ������.
    /// </summary>
    /// <returns>������ ������.</returns>
    size_t GetSize() const
    {
        return size;
    }

    /// <summary>
    /// ���������� ��������� �� �������� ������� ������.
    /// </summary>
    /// <returns>��������� �� �������� ������� ������.</returns>
    ListItem<T>* GetHead() const
    {
        return head;
    }

    /// <summary>
    /// ��������� ������� � ������.
    /// </summary>
    /// <param name="value">��������, ����������� � ������.</param>
    /// <param name="atStart">����, �����������, ��������� �� ������� � ������ (true) ��� � ����� (false).</param>
    void Add(const T& value, bool atStart = true)
    {
        ListItem<T>* newNode = new ListItem<T>(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else if (atStart)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }


    /// <summary>
    /// ��������� ������� � ������.
    /// </summary>
    /// <param name="node">����, �����/����� ������� ����� �������� ����� �������.</param>
    /// <param name="value">��������, ����������� � ������.</param>
    /// <param name="after">����, �����������, ��������� �� ������� ����� (true) ��� ����� (false) �������� �����.</param>
    void Insert(ListItem<T>* node, const T& value, bool after = true)
    {
        if (node == nullptr)
        {
            Add(value, !after);
            return;
        }

        if (node == (after ? tail : head))
        {
            Add(value, !after);
            return;
        }

        ListItem<T>* newNode = new ListItem<T>(value);
        if (after)
        {
            newNode->next = node->next;
            newNode->prev = node;
            node->next->prev = newNode;
            node->next = newNode;
        }
        else
        {
            newNode->prev = node->prev;
            newNode->next = node;
            node->prev->next = newNode;
            node->prev = newNode;
        }
        size++;
    }

    /// <summary>
    /// ������� �������� ���� �� ������.
    /// </summary>
    /// <param name="node">���� ��� ��������.</param>
    void Remove(ListItem<T>* node)
    {
        if (node == nullptr) return;

        if (node == head)
        {
            head = node->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
        }
        else if (node == tail)
        {
            tail = node->prev;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
 {
                head = nullptr;
            }
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
        size--;
    }

    /// <summary>
    /// ��������� ������ �� ����������� �������� ������.
    /// </summary>
    void Sort()
    {
        if (size <= 1) return;

        bool swapped;
        ListItem<T>* ptr1;
        ListItem<T>* lptr = nullptr;

        do
        {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr)
            {
                if (ptr1->data > ptr1->next->data)
                {
                    std::swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }


    /// <summary>
    /// ��������� �������� ����� �������� � ������.
    /// </summary>
    /// <param name="value">�������� ��� ������.</param>
    /// <returns>��������� �� ��������� �������, ��� nullptr, ���� ������� �� ������.</returns>
    ListItem<T>* LinearSearch(const T& value)
    {
        ListItem<T>* current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }


    /// <summary>
    /// ������� ������.
    /// </summary>
    void Clear()
    {
        ListItem<T>* current = head;
        while (current != nullptr)
        {
            ListItem<T>* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    /// <summary>
    /// ��������� ������ ���������� ��� ���������.
    /// </summary>
    /// <param name="size">���������� ��������� ��� ����������.</param>
    void FillBenchmark(int size)
    {
        for (int i = 0; i < size; i++)
        {
            Add(i, false);
        }
    }



    /// <summary>
    /// �������� ����� ���������� ��������.
    /// </summary>
    /// <param name="operation">�������, �������������� �������� ��� ���������.</param>
    /// <param name="size">������ ������ ��� �������� (���������� � operation).</param>
    /// <param name="operationName">�������� �������� ��� ������.</param>
    /// <returns>����� ���������� �������� � ��������.</returns>
    template<typename F>
    double Benchmark(F operation, int size, const string& operationName)
    {
        auto start = chrono::steady_clock::now();
        operation(size);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed = end - start;
        return elapsed.count();
    }


    /// <summary>
    /// �������� ��� ���������� ���������.
    /// </summary>
    /// <param name="size">���������� ��������� ��� ����������.</param>
    /// <param name="atStart">����, �����������, ��������� �� �������� � ������ (true) ��� � ����� (false).</param>
    auto AddBenchmark(int size, bool atStart)
    {
        return [this, atStart](int size)
            {
                for (int i = 0; i < size; ++i)
                {
                    Add(i, atStart);
                }
            };
    }

    /// <summary>
    /// �������� ��� �������� ���������.
    /// </summary>
    /// <param name="size">���������� ��������� ��� ��������.</param>
    auto RemoveBenchmark(int size)
    {
        return [this](int size)
            {
                for (int i = 0; i < size; i++)
                {
                    Remove(LinearSearch(i));
                }
            };
    }

    /// <summary>
    /// �������� ��� ������� ���������.
    /// </summary>
    /// <param name="node">����, �����/����� ������� ����� �������� ����� �������. ���� nullptr, ������� � ������/�����.</param>
    /// <param name="size">���������� ��������� ��� �������.</param>
    /// <param name="after">����, �����������, ��������� �� ������� ����� (true) ��� ����� (false) �������� �����.</param>
    auto InsertBenchmark(ListItem<T>* node, int size, bool after)
    {
        return[this, node, after](int size)
            {
                for (int i = 0; i < size; i++)
                {
                    Insert(node, i, after);
                }
            };
    }
};