#ifndef QLISTEXAMPLES_H
#define QLISTEXAMPLES_H

#include <QList>
#include <memory>

#include "person.h"

using PersonPtr = std::shared_ptr<Person>;

class QListExamples
{
public:
    QListExamples();
    virtual ~QListExamples() {}

    void indexBasedAccess();
    void javaStyleIterators();
    void stlStyleIterator();
    void removeEven();

private:
    QList<PersonPtr> m_list;
};

#endif // QLISTEXAMPLES_H
