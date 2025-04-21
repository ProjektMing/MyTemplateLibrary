#pragma once

#include <vector>
template <typename TType, template <typename...> class TContainer = std::vector> class MyStack
{
  private:
    TContainer<TType> _data = TContainer<TType>();
    size_t _topIndex = 0;

  public:
    void Push(const TType &element);
    void Push(TType &&element);
    void Pop();
    TType &Top();
    const TType &Top() const;

    bool IsEmpty() const;
    size_t Size() const;
};

#include "MyStack.tpp"
