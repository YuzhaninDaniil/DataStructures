#include "RingBuffer.h"

/// <summary>
/// Конструктор.
/// </summary>
/// <param name="size"></param>
RingBuffer::RingBuffer(int size) : _bufferSize(size), _head(0), _tail(0), _currentSize(0)
{
    _buffer = new int[size];
}

/// <summary>
/// Деструктор.
/// </summary>
RingBuffer::~RingBuffer()
{
    Delete();
}

/// <summary>
/// Добавление элемента в кольцевой буфер.
/// </summary>
/// <param name="data"></param>
void RingBuffer::Add(int data)
{
    _buffer[_head] = data; // Записываем данные в текущую позицию головы
    _head = (_head + 1) % _bufferSize; // Сдвигаем голову

    // Если буфер был полон, сдвигаем хвост, чтобы перезаписать старый элемент
    if (IsFull())
    {
        _tail = (_tail + 1) % _bufferSize; // Сдвигаем хвост, чтобы перезаписать старый элемент
    }
    else
    {
        _currentSize++; // Увеличиваем текущий размер только если буфер не был полон
    }
}

/// <summary>
/// Извлечение элемента из кольцевого буфера.
/// </summary>
/// <returns></returns>
int RingBuffer::Remove()
{
    if (IsEmpty())
    {
        throw underflow_error("Кольцевой буфер пуст, невозможно извлечь элемент.");
    }
    int data = _buffer[_tail];
    _tail = (_tail + 1) % _bufferSize;
    _currentSize--;
    return data;
}

/// <summary>
/// Проверка, полный ли кольцевой буфер.
/// </summary>
/// <returns></returns>
bool RingBuffer::IsFull()
{
    return _currentSize == _bufferSize;
}

/// <summary>
/// Проверка, пуст ли кольцевой буфер.
/// </summary>
/// <returns></returns>
bool RingBuffer::IsEmpty()
{
    return _currentSize == 0;
}

/// <summary>
/// Получение текущего размера кольцевого буфера.
/// </summary>
/// <returns></returns>
int RingBuffer::Size()
{
    return _currentSize;
}

/// <summary>
/// Вывод всех элементов кольцевого буфера.
/// </summary>
void RingBuffer::Print()
{
    if (IsEmpty())
    {
        cout << "Кольцевой буфер пуст." << endl;
        return;
    }

    cout << "Вывод кольцевого буфера: ";
    for (int i = 0; i < _currentSize; ++i)
    {
        cout << _buffer[(_tail + i) % _bufferSize] << " ";
    }
    cout << endl;
}

/// <summary>
/// Освобождение памяти кольцевого буфера.
/// </summary>
void RingBuffer::Delete() {
    delete[] _buffer;
    _buffer = nullptr;
    _bufferSize = 0;
    _head = 0;
    _tail = 0;
    _currentSize = 0;
}