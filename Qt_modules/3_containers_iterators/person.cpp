#include "person.h"

Person::Person()
    : m_name(), m_surname(), m_age(0)
{

}

Person::Person(QString name, QString surname, unsigned age)
    : m_name(name), m_surname(surname), m_age(age)
{

}

Person::Person(const Person &other)
    : m_name(other.m_name), m_surname(other.m_surname), m_age(other.m_age)
{

}

QString Person::name() const
{
    return m_name;
}

void Person::setName(const QString &name)
{
    m_name = name;
}

QString Person::surname() const
{
    return m_surname;
}

void Person::setSurname(const QString &surname)
{
    m_surname = surname;
}

unsigned Person::age() const
{
    return m_age;
}

void Person::setAge(const unsigned &age)
{
    m_age = age;
}

Person &Person::operator=(const Person &other)
{
    this->m_age = other.m_age;
    this->m_name = other.m_name;
    this->m_surname = other.m_surname;
    return *this;
}

Person::operator QString() const
{
    return QString("%1 %2 %3").arg(m_name).arg(m_surname).arg(m_age);
}

std::ostream& operator<<(std::ostream& out, const Person &person)
{
    out << person.name().toUtf8().toStdString() << " " << person.surname().toUtf8().toStdString() << " " << person.age();
    return out;
}
