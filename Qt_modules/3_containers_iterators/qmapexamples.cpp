#include "qmapexamples.h"

#include <QDebug>
#include <algorithm>

QMapExamples::QMapExamples()
{
    for(int i = 0; i < 20; ++i)
    {
        if(i % 2 == 0)
        {
            m_map.insert(i, PersonPtr(new Person("Jan", "Even", 20 + i)));
        }
        else
        {
            m_map.insert(i, PersonPtr(new Person("Jan", "Odd", 20 + i)));
        }
    }
}

void QMapExamples::indexBasedAccess()
{
    qDebug() << "Map : Index based access";

    QList<PersonPtr> values = m_map.values();

    for(int i = 0; i < values.size(); i++)
    {
        qDebug() << '\t' << *values[i];
    }
}

void QMapExamples::javaStyleIterators()
{
    qDebug() << "Map : Java style iterator";

    QMapIterator<int, PersonPtr> iter(m_map);
    while(iter.hasNext())
    {
        iter.next();
        qDebug() << '\t' << iter.key() << " " << *iter.value();
    }
}

void QMapExamples::stlStyleIterator()
{
    qDebug() << "Map : STL style iterator";

    QMap<int, PersonPtr>::iterator iter = std::begin(m_map);
    for(; iter != std::end(m_map); ++iter)
    {
        qDebug() << '\t' << iter.key() << " " << *iter.value();
    }
}

void QMapExamples::removeEven()
{
    qDebug() << "Map : Remove even elements";

    QMap<int, PersonPtr>::iterator iter = std::begin(m_map);
    for(; iter != std::end(m_map); )
    {
        if(iter.key() % 2 == 0)
        {
            iter = m_map.erase(iter);
        }
        else
        {
            ++iter;
        }
    }

    for(const auto &ref : m_map)
    {
        qDebug() << '\t' << *ref;
    }
}
