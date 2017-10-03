#include "animal.h"

Animal::Animal(const QString &name, const QString &species, unsigned age, unsigned legs, double height)
    : name_(name),
      species_(species),
      age_(age),
      legs_(legs),
      height_(height)
{

}

QString Animal::name() const
{
    return name_;
}

void Animal::setName(const QString &name)
{
    name_ = name;
}

QString Animal::species() const
{
    return species_;
}

void Animal::setSpecies(const QString &species)
{
    species_ = species;
}

unsigned Animal::age() const
{
    return age_;
}

unsigned Animal::legs() const
{
    return legs_;
}

void Animal::setLegs(const unsigned &legs)
{
    legs_ = legs;
}

double Animal::height() const
{
    return height_;
}

void Animal::setHeight(double height)
{
    height_ = height;
}

