#include "temperaturereader.h"

#include <stdexcept>
#include <QTime>
#include <QVariant>
#include <QtGlobal>
#include <QDateTime>
#include <QSqlDatabase>

Temperature TemperatureReader::getCurrent()
{
    Temperature temp;

    query_.exec("SELECT datetime, temperature FROM temp WHERE id = (SELECT max(id) FROM temp)");
    query_.next();

    temp.date = QDateTime::fromString(query_.value(0).toString(), Qt::ISODate);
    temp.temperature = query_.value(1).toDouble();

    return temp;
}

QList<Temperature> TemperatureReader::getAll()
{
    QList<Temperature> list;

    query_.exec("SELECT datetime, temperature FROM temp");

    while (query_.next())
    {
        Temperature temp;
        temp.date = QDateTime::fromString(query_.value(0).toString(), Qt::ISODate);
        temp.temperature = query_.value(1).toDouble();
        list.append(temp);
    }

    return list;
}
