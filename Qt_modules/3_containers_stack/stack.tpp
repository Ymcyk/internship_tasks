#include <cassert>

template<typename T>
Stack<T>::Stack()
{

}

template<typename T>
Stack<T>::~Stack()
{

}

template<typename T>
void Stack<T>::push(const T &val)
{
    m_list.append(val);
}

template<typename T>
T &Stack<T>::pop()
{
    assert(!m_list.isEmpty());

    T &last = m_list.last();
    m_list.removeLast();

    return last;
}

template<typename T>
T &Stack<T>::top()
{
    assert(!m_list.isEmpty());

    return m_list.last();
}

template<typename T>
const T &Stack<T>::top() const
{
    assert(!m_list.isEmpty());

    return m_list.last();
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return m_list.isEmpty();
}

template<typename T>
int Stack<T>::length() const
{
    return m_list.length();
}

template<typename T>
void Stack<T>::clear()
{
    m_list.clear();
}

template<typename T>
void Stack<T>::swap(Stack<T> &other)
{
    m_list.swap(other.m_list);
}
