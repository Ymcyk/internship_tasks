#include "requesthandler.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTcpSocket>
#include <stdexcept>
#include <QDateTime>
#include <QDebug>
#include <QList>

#include "temperaturereader.h"
#include "temperaturejsonparser.h"

RequestHandler::RequestHandler(QTcpSocket *socket, QObject *parent)
    : QObject(parent)
    , socket_(socket)
    , reader_(std::unique_ptr<TemperatureReader>(new TemperatureReader))
{

}

RequestHandler::~RequestHandler()
{

}

void RequestHandler::handle()
{
    try
    {
        TemperatureJsonParser parser(socket_->readAll());

        switch(parser.state())
        {
        case TemperatureJsonParser::State::NEWEST_TEMPERATURE:
        {
            Temperature temp = reader_->getCurrent();
            QJsonObject json_object;
            json_object.insert("temperature", temp.temperature);
            json_object.insert("date", temp.date.toString(Qt::ISODate));
            QJsonDocument document(json_object);
            socket_->write(document.toJson(QJsonDocument::Compact));
            break;
        }
        case TemperatureJsonParser::State::ALL_TEMPERATURES:
        {
            auto temp_list = reader_->getAll();

            QJsonArray array;

            for (auto const &temp : temp_list)
            {
                QJsonObject json_object;
                json_object.insert("temperature", temp.temperature);
                json_object.insert("date", temp.date.toString(Qt::ISODate));

                array.append(json_object);
            }

            QJsonDocument document(array);
            socket_->write(document.toJson(QJsonDocument::Compact));
            break;
        }
        default:
            break;
        }
    }
    catch(std::logic_error &err)
    {
        qDebug() << "BadRequest: " << err.what();
        sendErrorResponse(err.what());
    }
}

void RequestHandler::sendErrorResponse(const char *error_text)
{
    QJsonObject json_object;
    json_object.insert("error", error_text);

    QJsonDocument json_document(json_object);

    socket_->write(json_document.toJson(QJsonDocument::Compact));
}
