#pragma once

#include "MyList.hpp"
#include <stdexcept>
#include <utility>

template <typename T> MyList<T>::MyList() : _head(nullptr), _size(0)
{
}

template <typename T> MyList<T>::MyList(const MyList<T> &other) : _head(nullptr), _size(0)
{
    Node *current = other._head;
    while (current != nullptr)
    {
        PushBack(current->_data);
        current = current->_next;
    }
}

template <typename T> MyList<T>::MyList(MyList<T> &&other) noexcept : _head(other._head), _size(other._size)
{
    other._head = nullptr;
    other._size = 0;
}

template <typename T> MyList<T>::~MyList()
{
    Clear();
}

template <typename T> MyList<T> &MyList<T>::operator=(const MyList<T> &other)
{
    if (this != &other)
    {
        Clear();
        Node *current = other._head;
        while (current != nullptr)
        {
            PushBack(current->_data);
            current = current->_next;
        }
    }
    return *this;
}

template <typename T> MyList<T> &MyList<T>::operator=(MyList<T> &&other) noexcept
{
    if (this != &other)
    {
        Clear();
        _head = other._head;
        _size = other._size;
        other._head = nullptr;
        other._size = 0;
    }
    return *this;
}

template <typename T> void MyList<T>::PushFront(const T &value)
{
    Node *newNode = new Node(value);
    newNode->_next = _head;
    if (_head != nullptr)
    {
        _head->_prev = newNode;
    }
    _head = newNode;
    _size++;
}

template <typename T> void MyList<T>::PushFront(T &&value)
{
    Node *newNode = new Node(std::move(value));
    newNode->_next = _head;
    if (_head != nullptr)
    {
        _head->_prev = newNode;
    }
    _head = newNode;
    _size++;
}

template <typename T> void MyList<T>::PushBack(const T &value)
{
    Node *newNode = new Node(value);

    if (_head == nullptr)
    {
        _head = newNode;
    }
    else
    {
        Node *current = _head;
        while (current->_next != nullptr)
        {
            current = current->_next;
        }
        current->_next = newNode;
        newNode->_prev = current;
    }

    _size++;
}

template <typename T> void MyList<T>::PushBack(T &&value)
{
    Node *newNode = new Node(std::move(value));

    if (_head == nullptr)
    {
        _head = newNode;
    }
    else
    {
        Node *current = _head;
        while (current->_next != nullptr)
        {
            current = current->_next;
        }
        current->_next = newNode;
        newNode->_prev = current;
    }

    _size++;
}

template <typename T> void MyList<T>::PopFront()
{
    if (_head == nullptr)
        throw std::out_of_range("List is empty");

    Node *temp = _head;
    _head = _head->_next;
    if (_head != nullptr)
    {
        _head->_prev = nullptr;
    }
    delete temp;
    _size--;
}

template <typename T> void MyList<T>::PopBack()
{
    if (_head == nullptr)
        throw std::out_of_range("List is empty");

    if (_head->_next == nullptr)
    {
        delete _head;
        _head = nullptr;
    }
    else
    {
        Node *current = _head;
        while (current->_next != nullptr)
        {
            current = current->_next;
        }
        current->_prev->_next = nullptr;
        delete current;
    }

    _size--;
}

template <typename T> T &MyList<T>::Front()
{
    if (_head == nullptr)
        throw std::out_of_range("List is empty");
    return _head->_data;
}

template <typename T> const T &MyList<T>::Front() const
{
    if (_head == nullptr)
        throw std::out_of_range("List is empty");
    return _head->_data;
}

template <typename T> T &MyList<T>::Back()
{
    if (_head == nullptr)
        throw std::out_of_range("List is empty");

    Node *current = _head;
    while (current->_next != nullptr)
    {
        current = current->_next;
    }
    return current->_data;
}

template <typename T> const T &MyList<T>::Back() const
{
    if (_head == nullptr)
        throw std::out_of_range("List is empty");

    Node *current = _head;
    while (current->_next != nullptr)
    {
        current = current->_next;
    }
    return current->_data;
}

template <typename T> bool MyList<T>::IsEmpty() const
{
    return _size == 0;
}

template <typename T> size_t MyList<T>::Size() const
{
    return _size;
}

template <typename T> void MyList<T>::Clear()
{
    Node *current = _head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->_next;
        delete temp;
    }
    _head = nullptr;
    _size = 0;
}
