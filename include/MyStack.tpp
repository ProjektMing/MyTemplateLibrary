#pragma once
#include "MyStack.hpp"
#include <stdexcept>

template <typename TType, template <typename...> class TContainer>
void MyStack<TType, TContainer>::Push(const TType &element)
{
    _data.push_back(element);
    ++_topIndex;
}

template <typename TType, template <typename...> class TContainer>
void MyStack<TType, TContainer>::Push(TType &&element)
{
    _data.push_back(std::move(element));
    ++_topIndex;
}

template <typename TType, template <typename...> class TContainer> void MyStack<TType, TContainer>::Pop()
{
    if (_topIndex == 0)
    {
        throw std::out_of_range("Stack is empty. Cannot pop.");
    }
    _data.pop_back();
    --_topIndex;
}

template <typename TType, template <typename...> class TContainer> TType &MyStack<TType, TContainer>::Top()
{
    if (_topIndex == 0)
    {
        throw std::out_of_range("Stack is empty. Cannot access top element.");
    }
    return _data.back();
}

template <typename TType, template <typename...> class TContainer> const TType &MyStack<TType, TContainer>::Top() const
{
    if (_topIndex == 0)
    {
        throw std::out_of_range("Stack is empty. Cannot access top element.");
    }
    return _data.back();
}

template <typename TType, template <typename...> class TContainer> bool MyStack<TType, TContainer>::IsEmpty() const
{
    return _topIndex == 0;
}

template <typename TType, template <typename...> class TContainer> size_t MyStack<TType, TContainer>::Size() const
{
    return _topIndex;
}
