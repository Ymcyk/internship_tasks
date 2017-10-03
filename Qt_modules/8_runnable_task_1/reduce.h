#ifndef REDUCE_H
#define REDUCE_H

#include <QRunnable>
#include <QObject>
#include <QList>

class Reduce : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Reduce(QObject *parent = 0);
    Reduce(const QList<int> &);
    ~Reduce();

    void run() override;

    void setList(const QList<int> &list);

signals:
    void reduced(int);
    void valueChanged(int);
    void finished(long long);
    void started(int);

private:
    QList<int> mList;
};

#endif // REDUCE_H
