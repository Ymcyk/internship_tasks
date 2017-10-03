#include "reducearray.h"

#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QFutureSynchronizer>

#include "incrementprogressbar.h"

#include <QDebug>

ReduceArray::ReduceArray(IncrementProgressBar *progress, QObject *parent)
    : QObject(parent),
      mProgressBar(progress)
{

}


long long ReduceArray::reduce(ListIterator beg, ListIterator end, int objects)
{
    int length = end - beg;
    objects = (objects > length) ? length : objects;

    QFutureSynchronizer<long long> futList;

    ListIterator listItr = beg;
    ListIterator listItrNext;

    int portion = length / objects;

    for (int i = 0; i < objects; ++i)
    {
        if (!(i == (objects - 1)))
            listItrNext = listItr + portion;
        else
            listItrNext = end;

        futList.addFuture(QtConcurrent::run(this, &ReduceArray::calculate, listItr, listItrNext));
        listItr = listItrNext;
    }

    futList.waitForFinished();

    long long result = 0;

    for (const auto &ref : futList.futures())
    {
        result += ref.result();
    }

    return result;
}

long long ReduceArray::calculate(ListIterator itr, ListIterator end)
{
    long long result = 0;

    for (; itr != end; ++itr)
    {
        result += *itr;
        mProgressBar->onProgressValueChanged();
    }

    return result;
}
