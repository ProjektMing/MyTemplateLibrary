#pragma once

#include <cstddef>
#include <list>
template <typename TType, template <typename...> class TContainer = std::list> class MyQueue
{
  private:
    TContainer<TType> _data;

  public:
    void Enqueue(const TType &element);
    void Enqueue(TType &&element);
    void Dequeue();

    TType &Front();
    const TType &Front() const;

    size_t Size() const;
    bool IsEmpty() const;
};

#include "MyQueue.tpp"