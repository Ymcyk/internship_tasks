#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QList>

#include <QDebug>

template<typename InputIterator>
long long ReduceArray::reduce(InputIterator beg, InputIterator end, int objects)
{
    int length = end - beg;
    objects = (objects > length) ? length : objects;

    QList<QFuture<long long> > futList;
    futList.reserve(objects);

    qDebug() << "M-objects in calculate: " << objects;

    InputIterator listItr = beg;
    InputIterator listItrNext;

    int portion = length / objects;

    for (int i = 0; i < objects; ++i)
    {
        if (!(i == (objects - 1)))
            listItrNext = listItr + portion;
        else
            listItrNext = end;

        futList.append(QtConcurrent::run(&ReduceArray::calculate, listItr, listItrNext));
        listItr = listItrNext;
        qDebug() << "In for";
    }

    long long result = 0;

    for (const auto &ref : futList)
    {
        result += ref.result();
    }

    qDebug() << "Result: " << result;

    return result;
}

//template<typename InputIterator>
long long ReduceArray::calculate(QList<int>::iterator itr, QList<int>::iterator end)
{
    long long result = 0;

    for (; itr != end; ++itr)
    {
        qDebug() << "Obliczam: " << *itr;
        result += *itr;
    }

    return result;
}
