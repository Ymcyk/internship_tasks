#include "personlist.h"
#include <QtGlobal>

PersonList::PersonList(QObject *parent) : QObject(parent)
{

}

int PersonList::addPerson(Person *person)
{
    int id = m_counter++;
    auto ptr = PersonPtr(person);
    m_personMap.insert(std::pair<int, PersonPtr>(id, ptr));
    emit modified(ptr, "add");
    return id;
}

void PersonList::updatePerson(int key, Person *person)
{
    auto ptr = m_personMap.at(key);
    ptr.reset(person);
    emit modified(ptr, "update");
}

void PersonList::removePerson(int key)
{
    auto ptr = m_personMap.at(key);
    m_personMap.erase(key);
    emit modified(ptr, "remove");
}

int PersonList::size()
{
    return m_personMap.size();
}
