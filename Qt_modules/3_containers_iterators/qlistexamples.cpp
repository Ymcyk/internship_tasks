#include "qlistexamples.h"
#include <QDebug>

QListExamples::QListExamples()
{
    for(int i = 0; i < 20; ++i)
    {
        if(i % 2 == 0)
        {
            m_list.insert(i, PersonPtr(new Person("Jan", "Even", 20 + i)));
        }
        else
        {
            m_list.insert(i, PersonPtr(new Person("Jan", "Odd", 20 + i)));
        }
    }
}

void QListExamples::indexBasedAccess()
{
    qDebug() << "List : Index based access";

    for(int i = 0; i < m_list.size(); ++i)
    {
        qDebug() << '\t' << *m_list[i];
    }
}

void QListExamples::javaStyleIterators()
{
    qDebug() << "List : Java style iterator";

    QListIterator<PersonPtr> javaIt(m_list);
    while(javaIt.hasNext())
    {
        qDebug() << '\t' << *javaIt.next();
    }
}

void QListExamples::stlStyleIterator()
{
    qDebug() << "List : STL style iterator";

    QList<PersonPtr>::iterator stlIt = std::begin(m_list);
    for(; stlIt != std::end(m_list); ++stlIt)
    {
        qDebug() << '\t' << **stlIt;
    }
}

void QListExamples::removeEven()
{
    qDebug() << "List : Remove even elements";

    QMutableListIterator<PersonPtr> javaMutIt(m_list);
    for(bool toggle = true; javaMutIt.hasNext(); toggle = !toggle)
    {
        javaMutIt.next();
        if(toggle)
        {
            javaMutIt.remove();
        }
    }

    for(const auto &ref : m_list)
    {
        qDebug() << '\t' << *ref;
    }
}
