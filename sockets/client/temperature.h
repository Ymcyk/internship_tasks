#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QDateTime>

class Temperature
{  
public:
    void setTemperature(double);
    void setDate(const QString &);
    void setDate(const QDateTime &);

    QDateTime getDate() const;
    double getTemperature() const;

private:
    QDateTime date;
    double temperature;
};

#endif // TEMPERATURE_H
