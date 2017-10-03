#include "temperature.h"

#include <QtGlobal>
#include <QDateTime>

void Temperature::setDate(const QString &string)
{
    date = QDateTime::fromString(string, Qt::ISODate);
}

void Temperature::setDate(const QDateTime &date)
{
    this->date = date;
}

QDateTime Temperature::getDate() const
{
    return date;
}

double Temperature::getTemperature() const
{
    return temperature;
}

void Temperature::setTemperature(double value)
{
    temperature = value;
}
