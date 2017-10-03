#include <QCoreApplication>
#include <QDebug>

#include "stack.h"

int main(int argc, char *argv[])
{
    Stack<int> stack;



    stack.push(1);
    stack.push(2);
    stack.push(3);

    qDebug() << "On stack: 1 2 3";
    qDebug() << "isEmpty()\n" << stack.isEmpty();
    qDebug() << "length()\n" << stack.top();

    qDebug() << "top()\n" << stack.top();
    qDebug() << "pop()\n" << stack.pop();
    qDebug() << "top()\n" << stack.top();
    qDebug() << "length()\n" << stack.top();

    stack.top() = 42;

    qDebug() << "top()\n" << stack.top();

    Stack<int> stack2;
    qDebug() << "top() = 100\n" << stack.top();
    stack2.push(100);

    stack.swap(stack2);

    qDebug() << "top()\n" << stack.top();
    stack.pop();

    qDebug() << "isEmpty()\n" << stack.isEmpty();
}
