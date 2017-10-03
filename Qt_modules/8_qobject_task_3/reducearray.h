#ifndef REDUCEARRAY_H
#define REDUCEARRAY_H

#include <QObject>
#include <QList>

#include "worker.h"

using ListIterator = QList<int>::iterator;

class QThread;
class IncrementProgressBar;

class ReduceArray : public QObject
{
    Q_OBJECT
public:
    explicit ReduceArray(IncrementProgressBar *, QObject *parent = nullptr);
    virtual ~ReduceArray();

    void reduce(ListIterator beg, ListIterator end, int objects);

private slots:
//    void onResultReady(long long);

signals:
    void resultReady(long long);
    void operate();

private:
    void makeConnections(Worker *, QThread *);

private:
    IncrementProgressBar *mProgressBar;
};

//#include "reducearray.inl"

#endif // REDUCEARRAY_H
