#include "reducearray.h"

#include <QThread>
#include "incrementprogressbar.h"
#include "worker.h"

#include <QDebug>

ReduceArray::ReduceArray(IncrementProgressBar *progress, QObject *parent)
    : QObject(parent),
      mProgressBar(progress)
{

}

ReduceArray::~ReduceArray()
{

}

void ReduceArray::reduce(ListIterator beg, ListIterator end, int)
{
    Worker *worker = new Worker(beg, end);
    QThread *thread = new QThread;

    worker->moveToThread(thread);

    makeConnections(worker, thread);

    thread->start();
}

void ReduceArray::makeConnections(Worker *worker, QThread *thread)
{
    connect(thread, &QThread::finished, worker, &Worker::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    connect(thread, &QThread::started, worker, &Worker::calculate);
    connect(worker, &Worker::resultReady, this, &ReduceArray::resultReady);
    connect(worker, &Worker::valueChanged, mProgressBar, &IncrementProgressBar::onProgressValueChanged);
}
