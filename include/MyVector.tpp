#pragma once

#include "MyVector.hpp"
#include <stdexcept>
#include <utility>

template <typename T> MyVector<T>::MyVector(const MyVector &other) : _size(other._size), _capacity(other._capacity)
{
    _data = new T[_capacity];
    for (size_t i = 0; i < _size; i++)
    {
        _data[i] = other._data[i];
    }
}

template <typename T>
MyVector<T>::MyVector(MyVector &&other) noexcept : _data(other._data), _size(other._size), _capacity(other._capacity)
{
    other._data = nullptr;
    other._size = 0;
    other._capacity = 0;
}

template <typename T> MyVector<T>::~MyVector()
{
    delete[] _data;
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

template <typename T> void MyVector<T>::operator=(const MyVector &other)
{
    delete[] _data;
    _size = other._size;
    _capacity = other._capacity;
    _data = new T[_capacity];
    for (size_t i = 0; i < _size; i++)
    {
        _data[i] = other._data[i];
    }
}

template <typename T> void MyVector<T>::operator=(MyVector &&other) noexcept
{
    delete[] _data;
    _data = other._data;
    _size = other._size;
    _capacity = other._capacity;
    other._data = nullptr;
    other._size = 0;
    other._capacity = 0;
}

template <typename T> T &MyVector<T>::operator[](size_t pos)
{
    if (pos >= _size || pos < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    return _data[pos];
}

template <typename T> const T &MyVector<T>::operator[](size_t pos) const
{
    if (pos >= _size || pos < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    return _data[pos];
}

template <typename T> bool MyVector<T>::IsEmpty() const
{
    return _size == 0;
}

template <typename T> size_t MyVector<T>::Size() const
{
    return _size;
}

template <typename T> size_t MyVector<T>::GetCapacity() const
{
    return _capacity;
}

template <typename T> void MyVector<T>::Push(const T &value)
{
    if (_size == _capacity)
    {
        _capacity <<= 1;
        T *newData = new T[_capacity];
        for (size_t i = 0; i < _size; i++)
        {
            newData[i] = _data[i];
        }
        delete[] _data;
        _data = newData;
    }
    _data[_size++] = value;
}

template <typename T> void MyVector<T>::Push(T &&value)
{
    if (_size == _capacity)
    {
        _capacity <<= 1;
        T *newData = new T[_capacity];
        for (size_t i = 0; i < _size; i++)
        {
            newData[i] = _data[i];
        }
        delete[] _data;
        _data = newData;
    }
    _data[_size++] = std::move(value);
}

template <typename T> void MyVector<T>::Pop()
{
    if (_size == 0)
        throw std::out_of_range("Vector is empty");
    --_size;
}

template <typename T> void MyVector<T>::Clear()
{
    _size = 0;
}
