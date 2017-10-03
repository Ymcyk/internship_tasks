#ifndef PERSONLIST_H
#define PERSONLIST_H

#include <QObject>

#include <string>
#include <vector>
#include <memory>

#include "person.h"

using PersonPtr = std::shared_ptr<Person>;

class PersonList : public QObject
{
    Q_OBJECT
public:
    explicit PersonList(QObject *parent = nullptr);

    int addPerson(Person *);
    void updatePerson(int, Person *);
    void removePerson(int);

    int size();

signals:
    void modified(const PersonPtr, std::string);

private:
    std::map<int, PersonPtr> m_personMap;
    int m_counter = 1;
};

#endif // PERSONLIST_H
