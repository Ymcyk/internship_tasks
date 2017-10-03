#ifndef STACK_H
#define STACK_H

#include <QList>

template <typename T>
class Stack
{
public:
    Stack();
    virtual ~Stack();

    void push(const T &);
    T& pop();
    T& top();
    const T& top() const;
    bool isEmpty() const;
    int length() const;
    void clear();
    void swap(Stack<T> &);

private:
    QList<T> m_list;
};

#include "stack.tpp"

#endif // STACK_H
