#ifndef PERSON_H
#define PERSON_H

#include <ostream>
#include <QString>

class Person
{
public:
    Person();
    Person(QString, QString, unsigned);
    Person(const Person &);
    virtual ~Person() { }

    QString name() const;
    void setName(const QString &name);

    QString surname() const;
    void setSurname(const QString &surname);

    unsigned age() const;
    void setAge(const unsigned &age);

    Person& operator=(const Person&);
    operator QString() const;

    friend std::ostream& operator<<(std::ostream&, const Person &);

private:
    QString m_name;
    QString m_surname;
    unsigned m_age;
};

#endif // PERSON_H
