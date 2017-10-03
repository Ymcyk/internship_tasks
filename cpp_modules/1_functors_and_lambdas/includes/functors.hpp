#include <string>
#include "person.hpp"

struct IsUnderaged
{
    bool operator() (Person *);

private:
    int _age = 18;
};

struct ToString
{
    std::string operator() (Person *);
};

struct StrCompare
{
    bool operator() (Person *, Person *);
};
