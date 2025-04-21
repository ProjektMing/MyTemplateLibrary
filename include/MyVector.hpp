#pragma once

#include <cstddef>
#include <utility>

template <typename T> class MyVector
{
  private:
    T *_data;
    size_t _size;
    size_t _capacity = 16;

  public:
    MyVector() : _data(new T[16]), _size(0), _capacity(16)
    {
    }
    MyVector(const MyVector &other);
    MyVector(MyVector &&other) noexcept;
    ~MyVector();
    void operator=(const MyVector &other);
    void operator=(MyVector &&other) noexcept;

    T &operator[](size_t pos);
    const T &operator[](size_t pos) const;

    bool IsEmpty() const;
    size_t Size() const;
    size_t GetCapacity() const;

    void Push(const T &value);
    void Push(T &&value);
    void Pop();
    void Clear();

    bool empty() const
    {
        return IsEmpty();
    }
    void push_back(const T &value)
    {
        Push(value);
    }
    void push_back(T &&value)
    {
        Push(std::move(value));
    }
    void pop_back()
    {
        Pop();
    }
    T &back()
    {
        return _data[_size - 1];
    }
    const T &back() const
    {
        return _data[_size - 1];
    }
};

#include "MyVector.tpp"
