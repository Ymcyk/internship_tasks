#ifndef PERSONOBSERVER_H
#define PERSONOBSERVER_H

#include <QObject>
#include <string>
#include "personlist.h"

class PersonObserver : public QObject
{
    Q_OBJECT
public:
    explicit PersonObserver(QObject *parent = nullptr);

    void observe(PersonList*);

private:
    void personStatus(const PersonPtr, std::string);
    void listStatus();

public slots:
    void displayStatus(const PersonPtr, std::string);

private:
    PersonList* m_personList = nullptr;
};

#endif // PERSONOBSERVER_H
