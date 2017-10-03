#ifndef TEMPERATUREJSONPARSER_H
#define TEMPERATUREJSONPARSER_H

#include <QVariant>
#include <QJsonObject>

class QByteArray;

class TemperatureJsonParser
{
public:
    enum class State
    {
        NEWEST_TEMPERATURE,
        ALL_TEMPERATURES
    };

    TemperatureJsonParser(const QByteArray& byte_array);
    virtual ~TemperatureJsonParser();

    bool hasKey(const QString &key) const;
    QVariant getValue(const QString &key) const;
    QJsonObject getJsonObject() const;

    State state() const;

protected:
    void parse() noexcept(false);

private:
    QJsonObject json_object_;
    State state_;
};

#endif // TEMPERATUREJSONPARSER_H
