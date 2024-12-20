#pragma once

/// <summary>
/// Проверяет валидность введенного числа пользователем.
/// </summary>
int CheckData();

/// <summary>
/// Отображает в консоли меню стека.
/// </summary>
void DisplayStackMenu(Stack& stack);

/// <summary>
/// Отображает в консоли меню Кольцевого буфера.
/// </summary>
void DisplayRingBufferMenu(RingBuffer& ringBuffer);

/// <summary>
/// Отображает в консоли меню очереди на основе 2 стеков.
/// </summary>
void DisplayQueueStackMenu(QueueStack& queueStack);

/// <summary>
/// Отображает в консоли меню очереди на основе кольцевого буфера.
/// </summary>
void DisplayQueueRingBufferMenu(QueueRingBuffer& queueRingBuffer);

/// <summary>
/// Точка входа программы.
/// </summary>
int main();