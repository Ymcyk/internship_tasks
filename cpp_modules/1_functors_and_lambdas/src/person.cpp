#include "person.hpp"

Person::Person(const std::string &name, const std::string &surname, unsigned age)
    : m_name(name), m_surname(surname), m_age(age)
{

}

Person::Person(const Person &other)
    : m_name(other.m_name), m_surname(other.m_surname), m_age(other.m_age)
{

}

Person::~Person()
{

}

std::string Person::name() const
{
    return m_name;
}

void Person::setName(const std::string &name)
{
    m_name = name;
}

std::string Person::surname() const
{
    return m_surname;
}

void Person::setSurname(const std::string &surname)
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

std::ostream& operator<<(std::ostream& out, const Person &person)
{
    out << person.name() << " " << person.surname() << " " << person.age();
    return out;
}
