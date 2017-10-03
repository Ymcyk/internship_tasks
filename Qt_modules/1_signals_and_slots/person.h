#ifndef PERSON_H
#define PERSON_H

#include <QMetaType>
#include <ostream>
#include <string>

class Person
{
public:
    Person();
    Person(std::string, std::string, unsigned);
    Person(const Person &);
    ~Person() { }

    std::string name() const;
    void setName(const std::string &name);

    std::string surname() const;
    void setSurname(const std::string &surname);

    unsigned age() const;
    void setAge(const unsigned &age);

    Person& operator=(const Person&);

    friend std::ostream& operator<<(std::ostream&, const Person &);

private:
    std::string m_name;
    std::string m_surname;
    unsigned m_age;
};
Q_DECLARE_METATYPE(Person)

#endif // PERSON_H
