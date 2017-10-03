#include "mainclass.h"
#include <QDebug>

#include "person.h"
#include "personlist.h"
#include "personobserver.h"

MainClass::MainClass(QObject *parent)
    : QObject(parent)
{
    app = QCoreApplication::instance();
}

void MainClass::quit()
{
    emit finished();
}

void MainClass::run()
{
    qRegisterMetaType<Person>("Person");

    PersonList list;
    PersonObserver personObserver;

    personObserver.observe(&list);

    const int arrSize = 3;
    int id[arrSize];

    id[0] = list.addPerson(new Person("Jan", "Kowalski", 20));
    list.updatePerson(id[0], new Person("Adam", "Kowalski", 21));

    id[1] = list.addPerson(new Person("Jan", "Kowalski", 21));
    list.updatePerson(id[1], new Person("Adam", "Nowak", 21));

    id[2] = list.addPerson(new Person("Jan", "Kowalski", 20));
    list.updatePerson(id[2], new Person("Adam", "Nowak", 50));

    for(int i = 0; i < arrSize; ++i)
        list.removePerson(id[i]);
    quit();
}

void MainClass::abortToQuitApp()
{

}
