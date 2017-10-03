#ifndef WORKER_H
#define WORKER_H

#include <QObject>

using ListIterator = QList<int>::iterator;

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    Worker(ListIterator beg, ListIterator end);
    virtual ~Worker();

public slots:
    void calculate();

signals:
    void resultReady(long long);
    void valueChanged();

private:
    ListIterator mBeg, mEnd;
};

#endif // WORKER_H
