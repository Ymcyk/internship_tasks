#include "personobserver.h"

#include <iostream>
#include <stdexcept>

PersonObserver::PersonObserver(QObject *parent) : QObject(parent)
{

}

void PersonObserver::observe(PersonList *personList)
{
    connect(personList, &PersonList::modified, this, &PersonObserver::displayStatus);
    m_personList = personList;
}

void PersonObserver::displayStatus(const PersonPtr person, std::string operation)
{
    if("add" == operation)
        personStatus(person, "Added");
    else if("update" == operation)
        personStatus(person, "Updated");
    else if("remove" == operation)
        personStatus(person, "Removed");
    else
        throw std::invalid_argument("Operation not supported");
}

void PersonObserver::personStatus(const PersonPtr person, std::string desc)
{
    std::cout << desc << " " << *person << std::endl;
    listStatus();
}

void PersonObserver::listStatus()
{
    std::cout << "Remain: " << m_personList->size() << std::endl;
}
