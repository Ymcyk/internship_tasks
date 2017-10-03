#include "functors.hpp"

bool IsUnderaged::operator() (Person *person)
{
    return person->age() < this->_age;
}

std::string ToString::operator() (Person *person)
{
    return person->name() + " " + person->surname();
}

bool StrCompare::operator() (Person *left, Person *right)
{
    return left->surname() < right->surname();
}
