#pragma once

#include "MyQueue.hpp"

template <typename TType, template <typename...> class TContainer>
void MyQueue<TType, TContainer>::Enqueue(const TType &element)
{
    _data.push_back(element);
}

template <typename TType, template <typename...> class TContainer>
void MyQueue<TType, TContainer>::Enqueue(TType &&element)
{
    _data.push_back(std::move(element));
}

template <typename TType, template <typename...> class TContainer> void MyQueue<TType, TContainer>::Dequeue()
{
    if (!IsEmpty())
    {
        _data.pop_front();
    }
}

template <typename TType, template <typename...> class TContainer> TType &MyQueue<TType, TContainer>::Front()
{
    return _data.front();
}

template <typename TType, template <typename...> class TContainer>
const TType &MyQueue<TType, TContainer>::Front() const
{
    return _data.front();
}

template <typename TType, template <typename...> class TContainer> size_t MyQueue<TType, TContainer>::Size() const
{
    return _data.size();
}

template <typename TType, template <typename...> class TContainer> bool MyQueue<TType, TContainer>::IsEmpty() const
{
    return _data.empty();
}
