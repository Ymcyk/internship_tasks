#ifndef REDUCEARRAY_H
#define REDUCEARRAY_H

#include <QObject>
#include <QList>

using ListIterator = QList<int>::iterator;

class IncrementProgressBar;

class ReduceArray : public QObject
{
    Q_OBJECT
public:
    explicit ReduceArray(IncrementProgressBar *, QObject *parent = nullptr);
    virtual ~ReduceArray() {}

    long long reduce(ListIterator beg, ListIterator end, int objects);

signals:
    void progressValueChanged();

private:
    long long calculate(ListIterator itr, ListIterator end);

private:
    IncrementProgressBar *mProgressBar;
};

//#include "reducearray.inl"

#endif // REDUCEARRAY_H
