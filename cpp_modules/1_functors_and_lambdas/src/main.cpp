#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include "person.hpp"
#include "functors.hpp"

using PersonVector = std::vector<Person*>;

void generatePeople(PersonVector &);
void deletePeople(PersonVector &);

void functor_remove_if(PersonVector);
void functor_transform(PersonVector);
void functor_sort(PersonVector);

void lambda_remove_if(PersonVector);
void lambda_transform(PersonVector);
void lambda_sort(PersonVector);

int main()
{
    PersonVector vec;

    generatePeople(vec);

    std::cout << "Functors" << std::endl;
    functor_remove_if(vec);
    functor_transform(vec);
    functor_sort(vec);

    std::cout << "Lambda" << std::endl;
    lambda_remove_if(vec);
    lambda_transform(vec);
    lambda_sort(vec);

    

    std::cout << '\n';

    deletePeople(vec);
}

void generatePeople(PersonVector &vec)
{
    for (size_t i = 0; i < 5; i++)
        vec.push_back(new Person("Jan", "Kowalski", 8 + i));

    for (size_t i = 0; i < 5; i++)
        vec.push_back(new Person("Jan", "Adamczuk", 13 + i));

    for (size_t i = 0; i < 5; i++)
        vec.push_back(new Person("Jan", "Nowak", 17 + i));

    for (size_t i = 0; i < 5; i++)
        vec.push_back(new Person("Jan", "Zalewski", 21 + i));
}

void deletePeople(PersonVector &vec)
{
    for(auto &elem : vec)
        delete elem;
}

void functor_remove_if(PersonVector vec)
{
    std::cout << "Only adults\n";
    PersonVector::iterator new_it = std::remove_if(vec.begin(), vec.end(), IsUnderaged());
    for(PersonVector::iterator it = vec.begin(); it != new_it; ++it)
        std::cout << '\t' << *(*it) << std::endl;
}

void functor_transform(PersonVector vec)
{
    std::cout << "Vector converted to string list\n";
    std::list<std::string> per_list;
    std::transform(vec.begin(), vec.end(), std::back_inserter(per_list), ToString());
    for(auto &elem : per_list)
        std::cout << '\t' << elem << std::endl;
}

void functor_sort(PersonVector vec)
{
    std::cout << "Person sorted\n";
    std::sort(std::begin(vec), std::end(vec), StrCompare());
    for(auto &elem : vec)
        std::cout << '\t' << *elem << std::endl;
}

void lambda_remove_if(PersonVector vec)
{
    std::cout << "Only adults\n";
    PersonVector::iterator new_it = std::remove_if(vec.begin(), vec.end(),
        [](Person *person)
        {
            return person->age() < 18;
        });
    for(PersonVector::iterator it = vec.begin(); it != new_it; ++it)
        std::cout << '\t' << *(*it) << std::endl;
}

void lambda_transform(PersonVector vec)
{
    std::cout << "Vector converted to string list\n";
    std::list<std::string> per_list;
    std::transform(vec.begin(), vec.end(), std::back_inserter(per_list),
        [](Person *person)
        {
            return person->name() + " " + person->surname();
        });
    for(auto &elem : per_list)
        std::cout << '\t' << elem << std::endl;
}

void lambda_sort(PersonVector vec)
{
    std::cout << "Person sorted\n";
    std::sort(std::begin(vec), std::end(vec),
        [](Person *left, Person *right)
        {
            return left->surname() < right->surname();
        });
    for(auto &elem : vec)
        std::cout << '\t' << *elem << std::endl;
}
