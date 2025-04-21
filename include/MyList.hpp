#pragma once

#include <cstddef>

template <typename T> class MyList
{
  private:
    struct Node
    {
        T _data;
        Node *_next = nullptr;
        Node *_prev = nullptr;
        Node(const T &data) : _data(data), _next(nullptr), _prev(nullptr)
        {
        }
    };
    Node *_head = nullptr;
    size_t _size = 0;

  public:
    MyList();
    MyList(const MyList<T> &other);
    MyList(MyList<T> &&other) noexcept;
    ~MyList();

    MyList<T> &operator=(const MyList<T> &other);
    MyList<T> &operator=(MyList<T> &&other) noexcept;

    void PushFront(const T &value);
    void PushFront(T &&value);
    void PushBack(const T &value);
    void PushBack(T &&value);
    void PopFront();
    void PopBack();

    T &Front();
    const T &Front() const;
    T &Back();
    const T &Back() const;

    bool IsEmpty() const;
    size_t Size() const;
    void Clear();

    void push_front(const T &value)
    {
        PushFront(value);
    }
    void push_front(T &&value)
    {
        PushFront(value);
    }
    void push_back(const T &value)
    {
        PushBack(value);
    }
    void push_back(T &&value)
    {
        PushBack(value);
    }
    void pop_front()
    {
        PopFront();
    }
    void pop_back()
    {
        PopBack();
    }
    T &front()
    {
        return Front();
    }
    const T &front() const
    {
        return Front();
    }
    T &back()
    {
        return Back();
    }
    const T &back() const
    {
        return Back();
    }
    size_t size() const
    {
        return Size();
    }
    bool empty() const
    {
        return IsEmpty();
    }
    void clear()
    {
        Clear();
    }
};

#include "MyList.tpp"
