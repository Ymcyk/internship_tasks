#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>

class Animal
{
public:
    Animal(const QString &name = "", const QString &species = "", unsigned age = 0, unsigned legs = 0, double height = 0);

    QString name() const;
    void setName(const QString &name);

    QString species() const;
    void setSpecies(const QString &species);

    unsigned age() const;

    unsigned legs() const;
    void setLegs(const unsigned &legs);

    double height() const;
    void setHeight(double height);

private:
    QString name_;
    QString species_;
    unsigned age_;
    unsigned legs_;
    double height_;
};

#endif // ANIMAL_H
