#ifndef QMAPEXAMPLES_H
#define QMAPEXAMPLES_H

#include <QMap>
#include <memory>
#include "person.h"

using PersonPtr = std::shared_ptr<Person>;

class QMapExamples
{
public:
    QMapExamples();
    virtual ~QMapExamples() {}

    void indexBasedAccess();
    void javaStyleIterators();
    void stlStyleIterator();
    void removeEven();

private:
    QMap<int, PersonPtr> m_map;
};

#endif // QMAPEXAMPLES_H
