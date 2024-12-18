#pragma once

/// <summary>
/// ��������� ListItem ������������ ������� ����������� ������.
/// ������ �������� ��������� ���� � ��������� �� ���������� � ��������� ��������.
/// </summary>
/// <typeparam name="T">��� ������, ���������� � �������� ������.</typeparam>
template <typename T>
struct ListItem
{
    /// <summary>
    /// ������, ���������� � �������� ������.
    /// </summary>
    T data;

    /// <summary>
    /// ��������� �� ���������� ������� ������.
    /// </summary>
    ListItem<T>* prev;

    /// <summary>
    /// ��������� �� ��������� ������� ������.
    /// </summary>
    ListItem<T>* next;

    /// <summary>
    /// ����������� �������� ������.
    /// </summary>
    /// <param name="value">��������, ������� ����� ��������� � �������� ������.</param>
    ListItem(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};