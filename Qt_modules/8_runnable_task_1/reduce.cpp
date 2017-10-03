#include "reduce.h"

#include <QDebug>
#include <QThread>

Reduce::Reduce(QObject *parent)
    : QObject(parent)
{

}

Reduce::Reduce(const QList<int> &list)
    : mList(list)
{

}

Reduce::~Reduce()
{
    qDebug() << "Reduce destructor";
}

void Reduce::run()
{
    emit started(mList.length());

    long long result = 0;

    for (int i = 0; i < mList.length(); ++i)
    {
        result += mList[i];
        if (i % 10)
        {
            emit valueChanged(i + 1);
        }
    }

    emit finished(result);
}
