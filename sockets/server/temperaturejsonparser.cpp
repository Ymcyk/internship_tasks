#include "temperaturejsonparser.h"

#include <QJsonDocument>

#include "badrequest.h"
#include "jsonparseerror.h"

TemperatureJsonParser::TemperatureJsonParser(const QByteArray& byte_array)
{
    QJsonParseError parse_error;
    QJsonDocument document = QJsonDocument::fromJson(byte_array, &parse_error);

    if (parse_error.error != QJsonParseError::NoError)
    {
        throw(JsonParseError("The Json document is corrupted"));
    }

    json_object_ = document.object();

    parse();
}

TemperatureJsonParser::~TemperatureJsonParser()
{

}

QJsonObject TemperatureJsonParser::getJsonObject() const
{
    return json_object_;
}

bool TemperatureJsonParser::hasKey(const QString &key) const
{
    return json_object_.contains(key);
}

QVariant TemperatureJsonParser::getValue(const QString &key) const
{
    return json_object_.value(key).toVariant();
}

void TemperatureJsonParser::parse()
{
    if (!hasKey("request"))
    {
        throw(BadRequest(R"~~(Bad Json format. No "request" key.")~~"));
    }

    QString request = getValue("request").toString();

    if ("newest_temperature" == request)
    {
        state_ = State::NEWEST_TEMPERATURE;
    }
    else if ("all_temperatures" == request)
    {
        state_ = State::ALL_TEMPERATURES;
    }
    else
    {
        throw(BadRequest(QString(R"~~(Request "%1" not known)~~").arg(request).toLatin1().constData()));
    }
}

TemperatureJsonParser::State TemperatureJsonParser::state() const
{
    return state_;
}
