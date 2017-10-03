#include "worker.h"

#include <QDebug>

Worker::Worker(QObject *parent) : QObject(parent)
{

}

Worker::Worker(ListIterator beg, ListIterator end)
    : mBeg(beg), mEnd(end)
{

}

Worker::~Worker()
{
    qDebug() << "Worker destructor";
}

void Worker::calculate()
{
    qDebug() << "Worker started";

    long long result = 0;

    for (ListIterator itr = mBeg; itr != mEnd; ++itr)
    {
        result += *itr;
        emit valueChanged();
    }

    emit resultReady(result);
}
