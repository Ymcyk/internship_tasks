#ifndef PERSON_HPP
#define PERSON_HPP

#include <ostream>
#include <string>

class Person
{
public:
    Person(const std::string &name = "", const std::string &surname = "", unsigned age = 0);
    Person(const Person &);
    virtual ~Person();

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

#endif // PERSON_HPP
