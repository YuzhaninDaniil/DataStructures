#pragma once

#include "ListItem.h"
#include <chrono>
#include <iostream>
#include <algorithm>

/// <summary>
/// Êëàññ List ðåàëèçóåò äâóñâÿçíûé ñïèñîê.
/// Ïîääåðæèâàåò äîáàâëåíèå, óäàëåíèå, âñòàâêó, ñîðòèðîâêó è ïîèñê ýëåìåíòîâ.
/// </summary>
/// <typeparam name="T">Òèï äàííûõ, õðàíÿùèõñÿ â ñïèñêå.</typeparam>
template <typename T>
struct List
{
private:
    /// <summary>
    /// Óêàçàòåëü íà ïåðâûé ýëåìåíò ñïèñêà тест тест тест.
    /// </summary>
    ListItem<T>* head;

    /// <summary>
    /// Óêàçàòåëü íà ïîñëåäíèé ýëåìåíò ñïèñêà.
    /// </summary>
    ListItem<T>* tail;

    /// <summary>
    /// Ðàçìåð ñïèñêà.
    /// </summary>
    size_t size;

public:
    /// <summary>
    /// Êîíñòðóêòîð ñïèñêà.
    /// </summary>
    List() : head(nullptr), tail(nullptr), size(0) {}

    /// <summary>
    /// Äåñòðóêòîð ñïèñêà.
    /// </summary>
    ~List()
    {
        Clear();
    }

    /// <summary>
    /// Âîçâðàùàåò ðàçìåð ñïèñêà.
    /// </summary>
    /// <returns>Ðàçìåð ñïèñêà.</returns>
    size_t GetSize() const
    {
        return size;
    }

    /// <summary>
    /// Âîçâðàùàåò óêàçàòåëü íà ãîëîâíîé ýëåìåíò ñïèñêà.
    /// </summary>
    /// <returns>Óêàçàòåëü íà ãîëîâíîé ýëåìåíò ñïèñêà.</returns>
    ListItem<T>* GetHead() const
    {
        return head;
    }

    /// <summary>
    /// Äîáàâëÿåò ýëåìåíò â ñïèñîê.
    /// </summary>
    /// <param name="value">Çíà÷åíèå, äîáàâëÿåìîå â ñïèñîê.</param>
    /// <param name="atStart">Ôëàã, óêàçûâàþùèé, äîáàâëÿòü ëè ýëåìåíò â íà÷àëî (true) èëè â êîíåö (false).</param>
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
    /// Âñòàâëÿåò ýëåìåíò â ñïèñîê.
    /// </summary>
    /// <param name="node">Óçåë, ïîñëå/ïåðåä êîòîðûì íóæíî âñòàâèòü íîâûé ýëåìåíò.</param>
    /// <param name="value">Çíà÷åíèå, äîáàâëÿåìîå â ñïèñîê.</param>
    /// <param name="after">Ôëàã, óêàçûâàþùèé, âñòàâëÿòü ëè ýëåìåíò ïîñëå (true) èëè ïåðåä (false) çàäàííûì óçëîì.</param>
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
    /// Óäàëÿåò çàäàííûé óçåë èç ñïèñêà.
    /// </summary>
    /// <param name="node">Óçåë äëÿ óäàëåíèÿ.</param>
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
    /// Ñîðòèðóåò ñïèñîê ïî âîçðàñòàíèþ çíà÷åíèé äàííûõ.
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
    /// Âûïîëíÿåò ëèíåéíûé ïîèñê ýëåìåíòà â ñïèñêå.
    /// </summary>
    /// <param name="value">Çíà÷åíèå äëÿ ïîèñêà.</param>
    /// <returns>Óêàçàòåëü íà íàéäåííûé ýëåìåíò, èëè nullptr, åñëè ýëåìåíò íå íàéäåí.</returns>
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
    /// Î÷èùàåò ñïèñîê.
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
    /// Çàïîëíÿåò ñïèñîê çíà÷åíèÿìè äëÿ áåí÷ìàðêà.
    /// </summary>
    /// <param name="size">Êîëè÷åñòâî ýëåìåíòîâ äëÿ äîáàâëåíèÿ.</param>
    void FillBenchmark(int size)
    {
        for (int i = 0; i < size; i++)
        {
            Add(i, false);
        }
    }



    /// <summary>
    /// Èçìåðÿåò âðåìÿ âûïîëíåíèÿ îïåðàöèè.
    /// </summary>
    /// <param name="operation">Ôóíêòîð, ïðåäñòàâëÿþùèé îïåðàöèþ äëÿ èçìåðåíèÿ.</param>
    /// <param name="size">Ðàçìåð äàííûõ äëÿ îïåðàöèè (ïåðåäàåòñÿ â operation).</param>
    /// <param name="operationName">Íàçâàíèå îïåðàöèè äëÿ âûâîäà.</param>
    /// <returns>Âðåìÿ âûïîëíåíèÿ îïåðàöèè â ñåêóíäàõ.</returns>
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
    /// Áåí÷ìàðê äëÿ äîáàâëåíèÿ ýëåìåíòîâ.
    /// </summary>
    /// <param name="size">Êîëè÷åñòâî ýëåìåíòîâ äëÿ äîáàâëåíèÿ.</param>
    /// <param name="atStart">Ôëàã, óêàçûâàþùèé, äîáàâëÿòü ëè ýëåìåíòû â íà÷àëî (true) èëè â êîíåö (false).</param>
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
    /// Áåí÷ìàðê äëÿ óäàëåíèÿ ýëåìåíòîâ.
    /// </summary>
    /// <param name="size">Êîëè÷åñòâî ýëåìåíòîâ äëÿ óäàëåíèÿ.</param>
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
    /// Áåí÷ìàðê äëÿ âñòàâêè ýëåìåíòîâ.
    /// </summary>
    /// <param name="node">Óçåë, ïîñëå/ïåðåä êîòîðûì íóæíî âñòàâèòü íîâûé ýëåìåíò. Åñëè nullptr, âñòàâêà â íà÷àëî/êîíåö.</param>
    /// <param name="size">Êîëè÷åñòâî ýëåìåíòîâ äëÿ âñòàâêè.</param>
    /// <param name="after">Ôëàã, óêàçûâàþùèé, âñòàâëÿòü ëè ýëåìåíò ïîñëå (true) èëè ïåðåä (false) çàäàííûì óçëîì.</param>
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
