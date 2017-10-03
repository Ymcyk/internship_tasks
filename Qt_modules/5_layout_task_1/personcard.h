#ifndef PERSONCARD_H
#define PERSONCARD_H

#include <QString>
#include <QList>

class PersonCard
{
public:
    PersonCard();

    void setName(const QString &name);

    void setSecondName(const QString &secondName);

    void setAge(const unsigned &age);

    void setCountry(const QString &country);

    void addSport(const QString &sport);

    operator QString();
private:
    QString m_name;
    QString m_secondName;
    unsigned m_age;
    QString m_country;
    QList<QString> m_sports;
};

#endif // PERSONCARD_H
