#ifndef TEMPERATUREREADER_H
#define TEMPERATUREREADER_H

#include <QList>
#include <QSqlQuery>

#include "temperature.h"

class QSqlDatabase;

class TemperatureReader
{
public:
    Temperature getCurrent();
    QList<Temperature> getAll();

private:
    QSqlQuery query_;
};

#endif // TEMPERATUREREADER_H
