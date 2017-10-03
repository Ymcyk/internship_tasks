#include "personcard.h"

PersonCard::PersonCard()
{

}

void PersonCard::setName(const QString &name)
{
    m_name = name;
}

void PersonCard::setSecondName(const QString &secondName)
{
    m_secondName = secondName;
}

void PersonCard::setAge(const unsigned &age)
{
    m_age = age;
}

void PersonCard::setCountry(const QString &country)
{
    m_country = country;
}

void PersonCard::addSport(const QString &sport)
{
    m_sports.append(sport);
}

PersonCard::operator QString()
{
    QString text = QString("Name: %1, last name: %2, age: %3, country: %4, sports: ")
            .arg(m_name)
            .arg(m_secondName)
            .arg(m_age)
            .arg(m_country);

    for (int i = 0; i < m_sports.length(); ++i)
    {
        text.append(m_sports[i]);
        if (i < m_sports.length() - 1)
            text.append(", ");
    }

    return text;
}
